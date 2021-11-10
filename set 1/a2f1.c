#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define megisto_plithos 256
#define N 100

typedef enum{
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean KenoSynolo(typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);
boolean isValidInteger(char table1[N],typos_synolou CharacterSet,typos_synolou DigitSet);
boolean isValidIdentifier(char table2[N],typos_synolou LetterSet,typos_synolou DigitSet);

main()
{
    char table1[N],table2[N];
    char epilogi1,epilogi2;
    typos_synolou CharacterSet,DigitSet,LetterSet;

    // Δημιουργει το συνολο CharacterSet και εισαγει σε πινακα τα στοιχεια του
    Dimiourgia(CharacterSet);
    Eisagogi(43,CharacterSet);
    Eisagogi(45,CharacterSet);

    // Δημιουργει το συνολο DigitSet και εισαγει σε πινακα τα στοιχεια του
    Dimiourgia(DigitSet);
    for(int i=48; i<=57; i++)
        Eisagogi(i,DigitSet);

    // Δημιουργει το συνολο LetterSet και εισαγει σε πινακα τα στοιχεια του
    Dimiourgia(LetterSet);
    for(int i=65; i<=90; i++)
        Eisagogi(i,LetterSet);
    for(int i=97; i<=122; i++)
        Eisagogi(i,LetterSet);

    // βρογχος για εισαγωγει και ελεγχο αλφαριθμητικου
    do{
        fflush(stdin);
        printf("Dose ena alfarithmitiko: ");
        gets(table1);

        if( isValidInteger(table1,CharacterSet,DigitSet) )
            printf("Valid integer ");
        else
            printf("Not a valid integer ");

        do
        {
            printf("\nContinue Y,y/N,n: ");
            fflush(stdin);
            scanf("%c", &epilogi1);
        } while (epilogi1 != 'N' && epilogi1 != 'Y' && epilogi1 != 'y' && epilogi1 != 'n');

    }while(epilogi1 == 'Y' || epilogi1 == 'y');

    printf("------------------------------------\n");

    // βρογχος για εισαγωγει και ελεγχο αλφαριθμητικου
    do{
        fflush(stdin);
        printf("Dose alfarithmitiko: ");
        gets(table2);

        if( isValidIdentifier(table2,LetterSet,DigitSet) )
            printf("Valid identifier ");
        else
            printf("Not a valid identifier ");

        do
        {
            printf("\nContinue Y,y/N,n: ");
            fflush(stdin);
            scanf("%c", &epilogi2);
        } while (epilogi2 != 'N' && epilogi2 != 'Y' && epilogi2 != 'y' && epilogi2 != 'n');

    }while(epilogi2 == 'Y' || epilogi2 == 'y');


    system("PAUSE");
    return 0;
}

// Συναρτηση που ελεγχει αμα ενα αλφαριθμητικο ειναι ακεραιος
boolean isValidInteger(char table1[N],typos_synolou CharacterSet,typos_synolou DigitSet)
{
    int flag = 0;
    if( Melos(table1[0],CharacterSet) )
    {
        for(int i=1; table1[i] != '\0'; i++)
        {
            if( Melos(table1[i],DigitSet) )
                flag = 1;
            else
                return FALSE;
        }
    }

    if(flag == 0)
        return FALSE;
    else
        return TRUE;
}

// Συναρτηση που ελεγχει αμα ενα αλφαριθμητικο ειναι αναγνωριστικο
boolean isValidIdentifier(char table2[N],typos_synolou LetterSet,typos_synolou DigitSet)
{
    int flag = 0;
    if( Melos(table2[0],LetterSet) )
    {
        for(int i=1; table2[i] != '\0'; i++)
        {
            if( Melos(table2[i],DigitSet) || Melos(table2[i],LetterSet) || table2[i] == 95 )
                flag = 1;
            else
                return FALSE;
        }
    }

    if(flag == 0)
        return FALSE;
    else
        return TRUE;
}


void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Katholiko(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}

void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = FALSE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

boolean KenoSynolo(typos_synolou synolo)
{
    stoixeio_synolou i;
    boolean keno;

    keno=TRUE;
    i = 0;

    while (i < megisto_plithos  && keno) {
        if (Melos(i, synolo))
            keno = FALSE;
        else
            i++;
    }
    return keno;
}

boolean IsaSynola(typos_synolou s1, typos_synolou s2)
{
    stoixeio_synolou i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

boolean Yposynolo(typos_synolou s1, typos_synolou s2)
{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
    return yposyn;
}

void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}

void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}

void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}
