#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>
#include "ctype.h"
#include <math.h>

#define M 7   // πληθος πωλητων
#define InputElementsFile  "i4f9.dat"
#define OutputElementsFile  "o3f9.dat"

typedef struct{
    int kwd;
    char onoma[25];
    long aksia;
    double prom;
}employeeT;

void readDataFromFile(FILE *infile, employeeT employees[]);
void writeToFile(FILE *outfile, employeeT employees[]);

main(){

    FILE *infile,*outfile;
    employeeT employees[M];
    // ανοιγμα του αρχειου εισοδου
    infile = fopen(InputElementsFile, "r");
    if(infile == NULL)
        printf("FILE NOT FOUND\n");
    else
    {   // ανοιγμα του αρχειου εξοδου
        outfile = fopen(OutputElementsFile, "w");
        //κληση συναρτησεων
        readDataFromFile(infile,employees);
        writeToFile(outfile,employees);
        //κλεισημο του αρχειου εισοδου και εξοδου
        fclose(infile);
        fclose(outfile);
        printf("To programma eisigage automata to arxeio <i4f9.dat> kai eginan oi energeies poy ziti8ikan \n");
    }

    system("PAUSE");
    return 0;
}
// συναρτηση υπολογισμου προμηθειας και προσθηκη στοιχειων στην δομη employeeT
void readDataFromFile(FILE *infile, employeeT employees[])
{
    int nscan,kwd,counter=0;
    long aksia;
    char onoma[25],termch;

    while(TRUE)
    {
        nscan = fscanf(infile,"%2d,%25[^,],%9ld%c",&kwd,onoma,&aksia,&termch);

        if(nscan==EOF)break;
        if(nscan!=4 || termch!='\n')
            printf("Error\n");
        if(kwd == 11){
            employees[counter].prom = aksia*0.03;
            strcpy(employees[counter].onoma,onoma);
        }
        else if(kwd == 12)
        {
            employees[counter].prom = aksia*0.05;
            strcpy(employees[counter].onoma,onoma);
        }
        else if(kwd == 13)
        {
            employees[counter].prom = aksia*0.08;
            strcpy(employees[counter].onoma,onoma);
        }
        else
        {
            employees[counter].prom = aksia*0.11;
            strcpy(employees[counter].onoma,onoma);
        }
        counter++;
    }
}
// συναρτηση προσθηκης στοιχειων στο αρχειο εξοδου
void writeToFile(FILE *outfile, employeeT employees[])
{
    fprintf(outfile,"%s","ONOMATEPWNYMO: ");
    for(int i=0; i<M; i++)
        fprintf(outfile,"%-25s",employees[i].onoma);
    fputc('\n',outfile);
    fprintf(outfile,"%s","PROMITHEIA   : ");
    for(int i=0; i<M; i++)
        fprintf(outfile,"%-25.2lf",employees[i].prom);
}
