#include<stdio.h>
#include<stdlib.h>
#include"cvs.h"

stat_age *creerchainon(int a){                                      // fonction permettant de creer un chainon contenant un age 
stat_age *nouveau = malloc(sizeof(stat_age));                     
if(nouveau == NULL){
printf("erreur");
  exit(1);
}
nouveau->age = a;
nouveau->homme = 0;                                                 //initialisation des champs a 0
nouveau->femme = 0;
nouveau->genre_inconnu = 0;
nouveau->conducteurs = 0;
nouveau->passagers = 0;
nouveau->pietons = 0;
nouveau->suivant = NULL;  
return nouveau;
}

liste initialiserliste(liste l){                                   // fonction permettant d'initialiser une liste
if(l==NULL){
  return NULL;
}
  l->premier = NULL;
l->dernier = NULL;
  return l;
}

void ajouter_sats(chainon *a, int genre, int type_usager){         //procédure permettant d'incrémenter des statistiques à un chainon contenant un age
if(a==NULL){
return;
}
switch(genre){

  case 1 :
    a->homme++;
  break;

  case 2 :
    a->femme++;
  break;
  
  case 3 :
    a->genre_inconnu++;
  break;

  default : 
    printf("erreur");
  break;
}

switch(type_usager){

  case 1 :
    a->conducteurs++;
  break;

  case 2 :
    a->passagers++;
  break;
  
  case 3 :
    a->pietons++;
  break;

  default : 
    printf("erreur");
  break;
}
}



void ajouter_age(int age, liste *l){                                //procédure permettant d'ajouter un age a la liste triée dans l'ordre croissant
    if (l == NULL) {
        return;
    }

    stat_age *courant = l->premier;
    stat_age *precedent = NULL;

    while (courant != NULL && courant->age < age) {
        precedent = courant;
        courant = courant->suivant;
    }
    
  
  if (courant != NULL && courant->age == age) {
        return;
    }

  
    stat_age *nouveau = creerchainon(age);

  
  if (precedent == NULL) {
        nouveau->suivant = l->premier;
        l->premier = nouveau;
    }


  else {
        nouveau->suivant = courant;
        precedent->suivant = nouveau;
    }

   
  if (nouveau->suivant == NULL) {
        l->dernier = nouveau;
    }
}



int rechercher_age(int age, liste *l){                            // fonction permettant de retourner l'emplacement d'un age dans la liste
if (l == NULL){
return -1;
}
int n = 0;
stat_age *courant = l->premier;
while(courant!=NULL){
if(courant->age == age){
return n;
}
courant = courant->suivant;
n++;
}
reutrn -1;
}


void age_data(FILE *f, liste *l) {

    CsvData *data;

    while ((data = recup_data(f)) != NULL) {

        if (data->birth_year >= 0 && data->birth_year <= 120) {
        
          
          if (rechercher_age(data->birth_year, l) == -1) {
              ajouter_age(data->birth_year, l);
            }

            stat_age *courant = l->premier;

            while (courant != NULL && courant->age != data->birth_year) {
                courant = courant->suivant;
            }

           
            if (courant != NULL) {
                ajouter_sats(courant, data->gender, data->user_type);
            }
        }

        free(data);
    }
close_csv(f);
  }






void afficher_sats_age(liste *l) {

    if (l == NULL || l->premier == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    stat_age *courant = l->premier;

    printf("\n========== STATISTIQUES PAR AGE ==========\n");

    while (courant != NULL) {

        printf("\nAge : %d ans\n", courant->age);

        printf("  Genres :\n");
        printf("    Hommes         : %d\n", courant->homme);
        printf("    Femmes         : %d\n", courant->femme);
        printf("    Genre inconnu  : %d\n", courant->genre_inconnu);

        printf("  Types d'usagers :\n");
        printf("    Conducteurs    : %d\n", courant->conducteurs);
        printf("    Passagers      : %d\n", courant->passagers);
        printf("    Pietons        : %d\n", courant->pietons);

        courant = courant->suivant;
    }

    printf("\n==========================================\n");
}
  
  



