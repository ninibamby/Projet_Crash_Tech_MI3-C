

typedef struct victime{
    int type;
    int genre;
    int age;
    int gravite;
    victime suivant;
}victime;

typedef struct voiture{
    int id;
    int purpose; 
    victime victime;
}voiture;


typedef struct noeud{
        voiture voiture;
        struct noeud droite;
        struct noeud gauche;
}




