#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>
#include "ctype.h"
#include <math.h>

#define InputElementsFile  "i10f9.dat"
#define OutputElementsFile  "o10f9.dat"

main(){

    FILE *infile;
    FILE *outfile;
    int ch,i;
    // ανοιγμα του αρχειου εισοδου
    infile = fopen(InputElementsFile, "r");
    if(infile == NULL)
        printf("FILE NOT FOUND\n");
    else
    {   // ανοιγμα του αρχειου εξοδου
        outfile = fopen(OutputElementsFile, "w");
        i=1;
        while(TRUE)
        {
            ch = getc(infile);
            if(ch == EOF)break;
            if(i == 0)
                if(isspace(ch))
                    i=1;
                else
                {
                    putc(32,outfile);
                    i=1;
                }
            if(ispunct(ch))
            {
                i=0;
                putc(ch,outfile);
            }
            if(isalpha(ch))
                putc(ch,outfile);
            if(isspace(ch))
                putc(' ',outfile);      //mporousa na balw ton ari8mo 32 anti gia ' '
        }
        //κλεισημο του αρχειου εισοδου και εξοδου
        fclose(infile);
        fclose(outfile);
        printf("To programma eisigage automata to arxeio <i10f9.dat> kai eginan oi energeies poy ziti8ikan \n");
    }

    system("PAUSE");
    return 0;
}
