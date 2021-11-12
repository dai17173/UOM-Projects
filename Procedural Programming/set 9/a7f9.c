#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>
#include <ctype.h>
#include <math.h>

#define InputElementsFile  "i7f9.dat"
#define OutputElementsFile  "o7f9.dat"

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
            if(ch==EOF) break;
            if(isdigit(ch))
            {
                putc(ch,outfile);
                i=1;
            }
            else
                if(i==1)
                {
                    putc('\n',outfile);
                    i++;
                }
        }
        //κλεισημο του αρχειου εισοδου και εξοδου
        fclose(infile);
        fclose(outfile);
        printf("To programma eisigage automata to arxeio <i7f9.dat> kai eginan oi energeies poy ziti8ikan \n");
    }

    system("PAUSE");
    return 0;
}
