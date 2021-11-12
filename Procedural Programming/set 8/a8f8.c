#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "ctype.h"
#include <string.h>
#include <math.h>


typedef struct{
    int width;   // πλατος
    int height;  // υψος
    int depth;   // βαθος
    int area;    // εμβαδο
    int volume;  // Ογκος
}box;

void EkxwrDiastaseis(box *aBox);
void YpolEmbadou(box *aBox);
void YpolOgkou(box *aBox);

main()
{
    box kouti;

    // Ζηταω απο το χρηστη τις διαστασεις
    EkxwrDiastaseis(&kouti);
    // Υπολογιζει το συνολικο εμβαδο του κουτιου
    YpolEmbadou(&kouti);
    // Υπολογιζει το συνολικο ογκο του κουτιου
    YpolOgkou(&kouti);

    // Εκτυπωση αποτελεσματων
    printf("To emvadon tou koutiou einai %d cm2 \n", kouti.area);
    printf("O ogos tou koutiou einai %d cm3 \n", kouti.volume);


    system("PAUSE");
    return 0;
}
// Συναρτηση για εισαγωγη δεδομενων
void EkxwrDiastaseis(box *aBox)
{
    printf("Dose to mikos tou koutiou se cm: ");
    (*aBox).width = GetInteger();
    printf("Dose to ypsos tou koutiou se cm: ");
    (*aBox).height = GetInteger();
    printf("Dose to vathos tou koutiou se cm: ");
    (*aBox).depth = GetInteger();
}
// Συναρτηση υπολογισμου εμβαδου
void YpolEmbadou(box *aBox)
{
    (*aBox).area = 2*((*aBox).width*(*aBox).height + (*aBox).height*(*aBox).depth + (*aBox).depth*(*aBox).width);
}
// Συναρτηση υπολογισμου ογκου
void YpolOgkou(box *aBox)
{
    (*aBox).volume = (*aBox).width*(*aBox).height*(*aBox).depth;
}

