


int openf(char* nom, FILE** f){
  *f=fopen(nom,'r');
  if(*f==NULL){
  printf("erreur ouverture fichier");
  return 0;
  }
  return 1;
}    //return si le fichier est ouvert ou non 

void pass_l(FILE*f){
  char ligne[256];
  fgets(ligne,sizeof(ligne),f);
  return;
}

CsvData* recup_data(FILE*f){
  
  CvsData*data;

 if( fscanf(f," %d;%19[^;];%19[^;];%d;%d;%d;%d;%d;%d ",
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

  
  
  
  

  
  



