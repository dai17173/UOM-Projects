#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>


typedef struct {
    char owner[40];
    long balance;
    int year;
    float rate;
} accountT;


int readFileData(char fileName[30],  accountT tab[]);
int compareDeposits(accountT newTab[], int newS, accountT oldTab[], int oldS, accountT missing[]);
void maziTaFagame(accountT newTab[], int size);
float taxExpected(accountT tab[],int size);
void maxBalanceOwner(accountT tab[], int size, char name[], int *year);

int main() {
    int i;

    accountT newData[100];
    int newDataSize;

    accountT oldData[100];
    int oldDataSize;

    accountT missing[100];
    int mSize;

    char maxNew[40];
    char maxOld[40];

    int yearNew;
    int yearOld;

    newDataSize = readFileData("bank_new.dat", newData);
    oldDataSize = readFileData("bank_old.dat", oldData);

    mSize = compareDeposits(newData,newDataSize, oldData, oldDataSize, missing);
    printf(" Clients in List New not in Old \n");
    for(i=0;i<mSize;i++)
      printf("- %s %ld \n", missing[i].owner, missing[i].balance);

    maziTaFagame(newData, newDataSize);

    printf("Expected Tax New %.2f \n", taxExpected(newData,newDataSize));
    printf("Expected Tax Old %.2f \n", taxExpected(oldData,oldDataSize));

    maxBalanceOwner(newData, newDataSize, maxNew, &yearNew );
    maxBalanceOwner(oldData, oldDataSize, maxOld, &yearOld );

    printf("Max in New: %s %d \n",maxNew, yearNew);
    printf("Max in Old: %s %d \n",maxOld, yearOld);

    system("PAUSE");
    return 0;
}

int readFileData(char fileName[30], accountT tab[]) {

   FILE* infile;

   int count = 0;

   char name[40];
   char termch;

   int nscan;

   infile = fopen(fileName, "r");
   if(infile == NULL)
   {
        printf("Input file does not exist\n");
        return 0;
   }

   while(TRUE) {
       nscan = fscanf(infile, "%40[^,], %ld, %f, %d%c",
                    tab[count].owner,
                    &tab[count].balance,
                    &tab[count].rate,
                    &tab[count].year,
                    &termch);

       if(nscan == EOF) break;
       if(nscan != 5 || termch != '\n')
          printf("Line Error in file %s \n", fileName);
       else
          count++;
    }

    fclose(infile);
    return count;
}

int compareDeposits(accountT newTab[], int newS, accountT oldTab[], int oldS, accountT missing[]){

   int i,j;
   int count = 0;
   int flag;

   for(i=0;i<newS;i++)
   {
        flag = 0;
        for(j=0;j<oldS;j++)
        {
            if (strcmp(newTab[i].owner, oldTab[j].owner) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) missing[count++] = newTab[i];
    }

    return count;
}

void maziTaFagame(accountT newTab[], int size){
   int i;
   FILE *outfile;

   outfile = fopen("mztfgm.dat", "w");
   for(i=0;i<size;i++)
   {
     if (newTab[i].year >= 2000)
       fprintf(outfile,"%s, %ld, %f, %d\n",
                newTab[i].owner,
                newTab[i].balance,
                newTab[i].rate,
                newTab[i].year);
    }

   fclose(outfile);
}

float taxExpected(accountT tab[],int size){
   int i;
   float tax = 0;
   for(i=0;i<size;i++)
     tax = tax + tab[i].balance;
   return tax * 0.4 ;
}

void maxBalanceOwner(accountT tab[], int size, char name[], int *year){

  int i;
  long maxBalance;

  maxBalance = tab[0].balance;
  strcpy(name, tab[0].owner);
  *year =  tab[0].year;

  for(i=1;i<size;i++)
    if (tab[i].balance > maxBalance)
    {
        strcpy(name, tab[i].owner);
        *year =  tab[i].year;
        maxBalance = tab[i].balance;
    }
}
