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
}liste;




stat_age *creerchainon(int a){                                      // fonction permettant de creer un chainon contenant un age 
stat_age *nouveau = malloc(sizeof(stat_age));                     
if(nouveau == NULL){
exit (0);
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




void ajouter_age(int age, liste *l){                                //procédure permettant d'ajouter un age à la liste triée dans l'ordre croissant
stat_age *nouveau = creerchainon(age);
if (l == NULL){
exit(1);
}
if (nouveau == NULL){
exit(2);
}
stat_age *courant = l -> premier;
stat_age *precedent = l -> premier;
if( nouveau->age < courant->age){
nouveau->suivant = courant;
liste->premier = nouveau;
}
else if(nouveau->age > courant->age);
do{
precedent = courant;
courant = courant->suivant;
if( nouveau->age < courant->age){
nouveau->suivant = courant;
precedent->suivant = nouveau;
}
}while(nouveau->age > courant->age);
} 




int rechercher_age(int age, liste l){                            // fonction permettant de retourner l'emplacement d'un age dans la liste
if (l == NULL){
exit(3);
}
int n = 0;
stat_age *courant = liste->premier;
do{
if(courant->age == age){
return n;
}
courant = courant->suivant;
n++;
}(while courant->age != age);
reutrn -1;
}


  
  



