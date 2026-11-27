#include "crash_data.h"

victime* creevictime(){
    victime* a = malloc(sizeof(victime));
    if(a==NULL){
        exit(EXIT_FAILURE)
    }
    a->age=0;
    a->genre=0;
    a->gravite=0;
    a->type=0;
    a->suivant=NULL;
    return a;
} 

voiture *creevoiture() {
    voiture *v = malloc(sizeof(voiture));

    if (v == NULL)
        exit(EXIT_FAILURE);

    v->id = 0;
    v->purpose = 0;
    v->victimes = NULL;

    return v;
}

noeud *creenoeud(voiture v) {
    noeud *n = malloc(sizeof(noeud));

    if (n == NULL)
        exit(EXIT_FAILURE);

    n->voiture = v;
    n->equilibre = 0;
    n->gauche = NULL;
    n->droite = NULL;

    return n;
}



int hauteur(noeud* a){
    if (a==NULL){
        return 0;
    }
    return 1+ MAX(hauteur(a->gauche), hauteur(a->droite));
}

noeud *rechercheAVL(noeud *a, int id) {
    if (a == NULL)
        return NULL;

    if (id == a->voiture.id)
        return a;

    if (id < a->voiture.id)
        return rechercheAVL(a->gauche, id);

    return rechercheAVL(a->droite, id);
}

noeud *rotationDroite(noeud *a) {
    if (a == NULL || a->gauche == NULL)
        return a;

    noeud *pivot = a->gauche;

    a->gauche = pivot->droite;
    pivot->droite = a;
int eq_a=a->equilibre;
int eq_p=pivot->equilibre;

    eq_a = eq_a-MIN(eq_p,0)+1;
    eq_p = MAX(eq_p+2,MAX(eq_p+eq_a+2,eq_a+1));

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

    a->equilibre = calculEquilibre(a);

    if (a->equilibre >= 2) {
        if (calculEquilibre(a->droite) >= 0)
            return rotationGauche(a);
        else
            return doubleRotationGauche(a);
    }

    if (a->equilibre <= -2) {
        if (calculEquilibre(a->gauche) <= 0)
            return rotationDroite(a);
        else
            return doubleRotationDroite(a);
    }

    return a;
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
    if (a == NULL)
        return;

    libererAVL(a->gauche);
    libererAVL(a->droite);

    libererVictimes(a->voiture.victimes);

    free(a);
}

noeud *rechercheOuCree(noeud *a, voiture v) {
    noeud *n = rechercheAVL(a, v.id);

    if (n != NULL)
        return n;

    return creenoeud(v);
}


void *crash_data(FILE *f) {

    CsvData *data;

    while ((data = recup_data(f)) != NULL) {

        /* On traite data ici */

        free(data);
    }

    close_csv(f);

    return ;
}




