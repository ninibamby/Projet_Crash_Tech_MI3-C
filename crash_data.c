#include "crash_data.h"
#include "cvs.h"


victime *creevictime() {
    victime *a = malloc(sizeof(victime));
    if (a == NULL){
        exit(EXIT_FAILURE);
    }
    a->age = 0;
    a->genre = 0;
    a->gravite = 0;
    a->type = 0;
    a->suivant = NULL;
    return a;
}

voiture *creevoiture() {

    voiture *v = malloc(sizeof(voiture));

    if (v == NULL){
        exit(EXIT_FAILURE);
    }
    v->id = NULL;
    v->purpose = 0;
    v->victimes = NULL;
    v->suivant = NULL;
    return v;

}

noeud *creenoeud(char *cle) {

    noeud *n = malloc(sizeof(noeud));

    if (n == NULL){
        exit(EXIT_FAILURE);
    }
    n->cle = malloc(strlen(cle) + 1);

    if (n->cle == NULL){
        exit(EXIT_FAILURE);
    }
    strcpy(n->cle, cle);
    n->voitures = NULL;
    n->equilibre = 0;
    n->gauche = NULL;
    n->droite = NULL;
    return n;

}

voiture *rechercheVoiture(voiture *v, char *id) {
    while (v != NULL) {
        if (strcmp(v->id, id) == 0){
            return v;
        }
        v = v->suivant;
    }
    return NULL;
}

int hauteur(noeud* a){
    if (a==NULL){
        return 0;
    }
    return 1+ MAX(hauteur(a->gauche), hauteur(a->droite));
}

noeud *rechercheAVL(noeud *a, char *cle) {

    if (a == NULL) {
        return NULL;
    }

    int comparaison = strcmp(cle, a->cle);

    if (comparaison == 0) {
        return a;
    }

    if (comparaison < 0) {
        return rechercheAVL(a->gauche, cle);
    }

    return rechercheAVL(a->droite, cle);

}

noeud *rotationDroite(noeud *a) {
    if (a == NULL || a->gauche == NULL){
        return a;
    }
    noeud *pivot = a->gauche;

    a->gauche = pivot->droite;
    pivot->droite = a;
int eq_a=a->equilibre;
int eq_p=pivot->equilibre;

    eq_a = eq_a-MIN(eq_p,0)+1;
    eq_p = MAX(eq_p+2,MAX(eq_p+eq_a+2,eq_a+1));

    a->equilibre=eq_a;
    pivot->equilibre=eq_p;

    return pivot;
}

noeud *rotationGauche(noeud *a) {
    if (a == NULL || a->droite == NULL)
        return a;

    noeud *pivot = a->droite;

    a->droite = pivot->gauche;
    pivot->gauche = a;
int eq_a=a->equilibre;
int eq_p=pivot->equilibre;

    eq_a = eq_a-MAX(eq_p,0)-1;
    eq_p = MIN(eq_p-2,MIN(eq_p+eq_a-2,eq_a-1));

    a->equilibre=eq_a;
    pivot->equilibre=eq_p;

    return pivot;
}

noeud *doubleRotationDroite(noeud *a) {
    if (a == NULL)
        return NULL;

    a->gauche = rotationGauche(a->gauche);

    return rotationDroite(a);
}

noeud *doubleRotationGauche(noeud *a) {
    if (a == NULL)
        return NULL;

    a->droite = rotationDroite(a->droite);

    return rotationGauche(a);
}


noeud *equilibrageAVL(noeud *a) {
    if (a == NULL)
        return NULL;

    if (a->equilibre >= 2) {
        if( a->droite->equilibre >= 0){
            return rotationGauche(a);
        }
        else{
            return doubleRotationGauche(a);
        }
    }

    if (a->equilibre <= -2) {
        if (a->gauche->equilibre <= 0)
            return rotationDroite(a);
        else
            return doubleRotationDroite(a);
    }

    return a;
}

void libererVoitures(voiture *v) {

    voiture *tmp;

    while (v != NULL) {
        tmp = v;
        v = v->suivant;
        libererVictimes(tmp->victimes);
        free(tmp->id);
        free(tmp);
    }
}

void libererVictimes(victime *v) {
    victime *tmp;

    while (v != NULL) {
        tmp = v;
        v = v->suivant;
        free(tmp);
    }
}

void libererAVL(noeud *a) {
    if (a == NULL){
        return;
}
    libererAVL(a->gauche);
    libererAVL(a->droite);
    libererVoitures(a->voitures);
    free(a->cle);
    free(a);
}

noeud *rechercheOuCree(noeud *a, voiture v) {
    noeud *n = rechercheAVL(a, v.id);

    if (n != NULL)
        return n;

    return creenoeud(v);
}

noeud *insertionAVL(noeud *a, char *cle, voiture *v) {

    if (a == NULL) {
        a = creenoeud(cle);
        a->voitures = v;
        return a;
    }

    int comparaison = strcmp(cle, a->cle);

    if (comparaison < 0){
        a->gauche = insertionAVL(a->gauche, cle, v);
    }
    else if (comparaison > 0){
        a->droite = insertionAVL(a->droite, cle, v);
    }
    else{
        return a;
    }
    a->equilibre = hauteur(a->droite) - hauteur(a->gauche);
    return equilibrageAVL(a);
}

noeud *crash_data(FILE *f) {
    CsvData *data;
    noeud *arbre = NULL;
    noeud *n;
    voiture *v;
    victime *vic;
    char cle[40];

    while ((data = recup_data(f)) != NULL) {

        sprintf(cle, "%d%s", data->year, data->collision_id);
        n = rechercheAVL(arbre, cle);
        v = NULL;
        if (n != NULL){
            v = rechercheVoiture(n->voitures, data->vehicle_id);
        }
        vic = creevictime();

        vic->age = data->year - data->birth_year;
        vic->genre = data->gender;
        vic->gravite = data->severity;
        vic->type = data->user_type;

        if (n == NULL) {

            v = creevoiture();

            v->id = malloc(strlen(data->vehicle_id) + 1);

            if (v->id == NULL){
                exit(EXIT_FAILURE);
            }
            strcpy(v->id, data->vehicle_id);

            v->purpose = data->purpose;
            v->victimes = vic;

            arbre = insertionAVL(arbre, cle, v);
        }

        else if (v == NULL) {

            v = creevoiture();
            v->id = malloc(strlen(data->vehicle_id) + 1);

            if (v->id == NULL){
                exit(EXIT_FAILURE);
            }
            strcpy(v->id, data->vehicle_id);

            v->purpose = data->purpose;
            v->victimes = vic;

            v->suivant = n->voitures;
            n->voitures = v;
        }
        else {
            vic->suivant = v->victimes;
            v->victimes = vic;
        }
        free(data);
    }
    close_csv(f);
    return arbre;
}



