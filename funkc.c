#ifndef funkc_h
#define funkc_h

void addNewFiles(char * string){
    FILE * myfile ;
    myfile=fopen(fileName(),"w");
    fprintf(myfile,"%s",string);
    fclose(myfile);
}
char *fileName(){
    char *name ="textstring.txt";
    return name;
}
void recordSumToFile(int sum){
    FILE * myfile ;
    myfile=fopen(fileName(),"a+");
    fprintf(myfile,"\nSum=%d\r",sum);
    fclose(myfile);
}
int functionSumElementArray (int arr[],int count){
    int i=0;
    int sumelement=0;
    while (i<count) {
        sumelement+=arr[i];
        i++;
    }
    return sumelement;
}
#endif