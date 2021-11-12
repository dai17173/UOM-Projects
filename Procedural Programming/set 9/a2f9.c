#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>
#include "ctype.h"
#include <math.h>

#define M 100

typedef struct{
    char name[30];
    int apousies;
}studentT;

void readInput(FILE* infile,studentT students[],int *pApousies,int *pStudents);
void writeOutput(FILE* outfile,int size,studentT students[],int total);

main(){

    studentT students[M];
    char inputfilename[30];
    char outputfilename[30];
    FILE *infile;
    FILE *outfile;
    int numberOfStudents, numberOfApousies;

    while(TRUE){
        printf("Dwste to onoma gia to arxeio eisodou :");
        gets(inputfilename);

        infile = fopen(inputfilename, "r");

        if(infile != NULL)break;
        printf("Cannot open input file %s. Try again.\n",inputfilename);
    }

    printf("Dwste to onoma gia to arxeio exodou :");
    gets(outputfilename);
    outfile = fopen(outputfilename, "w");

    readInput(infile, students, &numberOfApousies, &numberOfStudents);
    writeOutput(outfile, numberOfApousies, students, numberOfStudents);

    fclose(infile);
    fclose(outfile);
    return 0;
}

void readInput(FILE* infile,studentT students[],int *pApousies,int *pStudents)
{
    int nscan,apousies,studcount,apouscount;
    char name[30],comments[68],termch;

    apouscount = 0;
    studcount = 0;
    while(TRUE)
    {
        nscan=fscanf(infile,"%30[^,],%d,%68[^\n]%c",name,&apousies,comments,&termch);
        if(nscan==EOF) break;
        if(nscan!=4||termch!='\n')
            printf("Error\n")                //Error("Error4\n")  ΙΔΙΑΙΤΕΡΟ.σταματαει την εκτελεση
        if(apousies>100)
        {
            strcpy(students[apouscount].name,name);
            students[apouscount].apousies=apousies;
            apouscount++;
        }
        studcount++;
    }
    *pApousies = apouscount;
    *pStudents = studcount;
}

void writeOutput(FILE* outfile,int size,studentT students[],int total)
{
    int i;
    fprintf(outfile,"%-30s%-9s\n","ONOMATEPWNYMO","APOYSIES");
    for(i=1; i<=39; i++)
        fputc('-',outfile);
    fputc('\n',outfile);
    for(i=0; i<size; i++)
        fprintf(outfile,"%-30s%9d\n",students[i].name,students[i].apousies);
    for(i=1; i<=39; i++)
        fputc('-',outfile);
    fputc('\n',outfile);
    fprintf(outfile,"%-30s%9d\n","SYNOLO MATHITWN:",total);
    fprintf(outfile,"%-30s%9d\n","SYNOLO APONTWN:",size);
}
