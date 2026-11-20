int *openf(char* nom, FILE* f){
  f=fopen(nom,'r');
  if(f==NULL){
  printf("erreur ouverture fichier");
  return 0;
  }
  return 1;
}    //return si le fichier est ouvert ou non 





