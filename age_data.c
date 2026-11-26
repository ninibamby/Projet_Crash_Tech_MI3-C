#include<stdio.h>
#include<stdlib.h>

typedef struct stat_age{                                           //déclaration de la structure stat_age     
int age;
int homme;
int femme;
int genre_inconnu;
int conducteurs;
int passagers;
int pietons;
struct stat_age *suivant;
}stat_age; 



typedef struct liste{                                               //déclaration de la liste contenant les statistiques de chaque age
stat_age *premier;
stat_age *dernier;
}liste;




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
do{
if(courant->age == age){
return n;
}
courant = courant->suivant;
n++;
}(while courant->age != age && courant->suivant !=NULL);
reutrn -1;
}


  
  



