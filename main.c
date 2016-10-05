#include <stdio.h>
#include <stdlib.h>
FILE * openFile(char *mode);
void recordTofile(int **pointer,int sum0,int sum1,int count);
int main(int argc, char *argv[])
{
    FILE * myfile ;
    myfile=openFile("w");

    char *teststring="10.1 20.3 13.4 40.5 50.5 70.3 80.4 90.2";
    fprintf(myfile,"%s",teststring);
    fclose(myfile);

    // add dynamic memory for 0 array pointer
    int **pointer=(int **)malloc(sizeof(int*));
    pointer[0]=(int *)malloc(2*sizeof(int));

    myfile=openFile("r");
    int i=0;
    int count=0;
    //1)scan from the file to array
    while((fscanf(myfile, "%d.%d", &pointer[i][0], &pointer[i][1]))!=EOF){
        i++;
        // add dynamic memory for i+1 pointers
        pointer=(int **)realloc(pointer,(i+1)*sizeof(int*));
        pointer[i]=(int *)malloc((2)*sizeof(int));
        count++;
    }
    fclose(myfile);
    //2 Finding the sum of the elements
    int sum0=0;
    int sum1=0;
    for (i=0;i<count;i++){
        sum0+= *(*(pointer+i)+0);
        sum1+=*(*(pointer+i)+1);
        printf(" %d %d\n",*(*(pointer+i)+0),*(*(pointer+i)+1));
    }
    printf("\n %d %d",sum0,sum1);
    //3 record ineger numbers and sum to file
    recordTofile(pointer,sum0,sum1,count);

    return 0;
}
FILE *openFile(char *mode){
    FILE *myfile;
    myfile=fopen("doublenumbers.txt",mode);
    return myfile;
}
void recordTofile(int **pointer,int sum0,int sum1,int count){
    FILE *myfile;
    int i;
    myfile=openFile("a");
    fprintf(myfile,"%s","\nInteger numbers:");
    for(i=0;i<count;i++){
    fprintf(myfile,"% d",pointer[i][0]);
    }
    fprintf(myfile,"\nSumm intgerr=%d sum float=%d",sum0,sum1);
    fclose(myfile);
}
//void findSumElements(int**pointer){}