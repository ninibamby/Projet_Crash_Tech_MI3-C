
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


void ajouter_sats();
stat_age *creerchainon();
liste initialiserliste();
