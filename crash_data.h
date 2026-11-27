#ifndef CRASH_DATA_H
#define CRASH_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct victime {
    int type;
    int genre;
    int age;
    int gravite;
    struct victime *suivant;
} victime;

typedef struct voiture {
    char* id;
    int purpose;
    victime *victimes;
    struct voiture *suivant;
} voiture;

typedef struct noeud {
    char* cle;
    voiture *voitures;
    int equilibre;
    struct noeud *gauche;
    struct noeud *droite;
} noeud;

// Creation 
victime *creevictime();
voiture *creevoiture();
noeud *creenoeud(char *cle);

//AVL 
int hauteur(noeud *a);
int calculEquilibre(noeud *a);
noeud *rechercheAVL(noeud *a, char *cle);

// Rotations 
noeud *rotationDroite(noeud *a);
noeud *rotationGauche(noeud *a);
noeud *doubleRotationDroite(noeud *a);
noeud *doubleRotationGauche(noeud *a);

// Equilibrage 
noeud *equilibrageAVL(noeud *a);

// Insertion et suppression 
noeud *insertionAVL(noeud *a, char *cle, voiture *v);
noeud *minimumAVL(noeud *a);
noeud *maximumAVL(noeud *a);
noeud *suppressionAVL(noeud *a, char *cle);

// Liberation 
void libererVictimes(victime *v);
void libererVoitures(voiture *v);
void libererAVL(noeud *a);

#endif