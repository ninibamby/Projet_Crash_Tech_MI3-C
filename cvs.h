#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int year;
    char collision_id[20];
    char vehicle_id[20];
    int location;
    int user_type;
    int severity;
    int gender;
    int age;
    int purpose;
} CsvData;
