#include <stdio.h>
#include <stdlib.h>
#include "funkc.h"
#include "funkc.c"


typedef struct Array{
    int intnumber[8];
    int floatnumber[8];
} Array;

Array scanInFileToStruct(Array pointer);
int count;
int main()
{
    Array pointer;
    int sum;
    int sum2;
    char *teststring="10.10 20.12 13.14 40.50 50.16 70.21 80.32 90.18";
    addNewFiles(teststring);
    pointer=scanInFileToStruct(pointer);
    sum=functionSumElementArray(pointer.intnumber,count);

    sum2=functionSumElementArray(pointer.floatnumber,count);
    recordSumToFile(sum);
    recordSumToFile(sum2);
    return 0;
}

Array scanInFileToStruct(Array pointer){
    FILE * myfile;
    int i=0;
    myfile=fopen(fileName(),"r");
    while((fscanf(myfile, "%d.%d", &pointer.intnumber[i],&pointer.floatnumber[i]))!=EOF){
        i++;
        count++;
    }
    fclose(myfile);
    return pointer;
}

