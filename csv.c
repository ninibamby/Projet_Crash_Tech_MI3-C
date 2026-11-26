


int openf(char* nom, FILE** f){
  *f=fopen(nom,"r");
  if(*f==NULL){
  printf("erreur ouverture fichier");
  return 0;
  }
  return 1;
}    //return si le fichier est ouvert ou non 


CsvData *recup_data(FILE *f) {

    char ligne[256];
    int naissance;

    while (fgets(ligne, sizeof(ligne), f) != NULL) {

        CsvData *data = malloc(sizeof(CsvData));

        if (data == NULL)
            exit(EXIT_FAILURE);

        if (sscanf(ligne, " %d;%19[^;];%19[^;];%d;%d;%d;%d;%d;%d",
                   &data->year,
                   data->collision_id,
                   data->vehicle_id,
                   &data->location,
                   &data->user_type,
                   &data->severity,
                   &data->gender,
                   &naissance,
                   &data->purpose) == 9) {

            data->birth_year = data->year - naissance;

            return data;
        }

        free(data);
    }

    return NULL;
}
 
void close_csv(FILE *f) {
    if (fichier != NULL) {
        fclose(fichier);
        fichier = NULL;
    }
}

  
  
  
  

  
  



