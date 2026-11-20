


int openf(char* nom, FILE** f){
  *f=fopen(nom,"r");
  if(*f==NULL){
  printf("erreur ouverture fichier");
  return 0;
  }
  return 1;
}    //return si le fichier est ouvert ou non 


CsvData* recup_data(FILE*f){
  
  CsvData*data;
  char ligne[256];

 while (fgets(ligne, sizeof(ligne), f) != NULL) {

     if( sscanf(f," %d;%19[^;];%19[^;];%d;%d;%d;%d;%d;%d ",
              &data->year,
              data->collision_id,
              data->vehicle_id,
              &data->location,
              &data->user_type,
              &data->severity,
              &data->gender,
              &data->age,
              &data->purpose) == 9){
      
          return data;
       }
      // ligne incorecte
       }
    return NULL;
}
 
void close_csv(FILE *f) {
    if (fichier != NULL) {
        fclose(fichier);
        fichier = NULL;
    }
}

  
  
  
  

  
  



