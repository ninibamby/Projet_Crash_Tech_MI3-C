FILE *openf(char* nom){
  FILE* f=fopen(nom,'r');
  if(f==NULL){
  printf("erreur ouverture fichier");
  retrun NULL;
  }
  return f;
}

FILE



