#include<stdio.h>
#include<stdlib.h>

typedef struct chainon{
int age;
int homme;
int femme;
int genre_inconnu;
int conducteurs;
int passagers;
int piétons;
struct chainon *suivant;
}chainon; 

typedef struct liste{
chainon *premier;
}liste;

chainon *creerchainon(int a){
chainon *nouveau = malloc(sizeof(chainon));
if(nouveau == NULL){
exit (0);
}
nouveau->age = a;
nouveau->homme = 0;
nouveau->femme = 0;
nouveau->genre_inconnu = 0;
nouveau->conducteurs = 0;
nouveau->passagers = 0;
nouveau->piétons = 0;
nouveau->suivant = NULL;
return nouveau;
}

liste *trierage(liste *l, int age){




int rechercher_age(int age, liste l){
  
  



