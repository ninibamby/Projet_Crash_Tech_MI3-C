#ifndef CRASH_DATA_H
#define CRASH_DATA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct victime {
    int type;
    int genre;
    int age;
    int gravite;
    struct victime *suivant;
} victime;

typedef struct voiture {
    int id;
    int purpose;
    victime *victimes;
} voiture;

typedef struct noeud {
    voiture voiture;
    int equilibre;
    struct noeud *gauche;
    struct noeud *droite;
} noeud;

/* Creation */
victime *creevictime();
voiture *creevoiture();
noeud *creenoeud(voiture v);

/* AVL : fonctions de base */
int hauteur(noeud *a);
int calculEquilibre(noeud *a);
noeud *rechercheAVL(noeud *a, int id);

/* Rotations */
noeud *rotationDroite(noeud *a);
noeud *rotationGauche(noeud *a);
noeud *doubleRotationDroite(noeud *a);
noeud *doubleRotationGauche(noeud *a);

/* Equilibrage */
noeud *equilibrageAVL(noeud *a);

/* Insertion et suppression */
noeud *insertionAVL(noeud *a, voiture v);
noeud *minimumAVL(noeud *a);
noeud *maximumAVL(noeud *a);
noeud *suppressionAVL(noeud *a, int id);

/* Liberation memoire */
void libererVictimes(victime *v);
void libererAVL(noeud *a);

#endif