#ifndef CVS_H
#define CVS_H


#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {
    int year;
    char collision_id[20];
    char vehicle_id[20];
    int location;
    int user_type;
    int severity;
    int gender;
    int birth_year;
    int purpose;
} CsvData;



CsvData *recup_data(FILE *f);

int openf(char* nom, FILE** f);

void close_csv(FILE *f);



#endif