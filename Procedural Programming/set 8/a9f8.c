#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "ctype.h"
#include <string.h>
#include <math.h>

#define MaxEmployees 100

typedef struct{
    char name[20];
    char sname[20];
    float misthos_anawra;
    int wres_ergas;
    float miktes_apodox;
    float kratiseis;
    float foros;
    float kathares_apodox;
}employeeT;

void get_data(int kathigites, employeeT staff[]);
void calc_salaries(int kathigites, employeeT staff[]);
void print_data(int kathigites, employeeT staff[]);


main()
{
    employeeT staff[MaxEmployees];
    int kathigites;

    // Εισαγωγη πληθους υπαλληλων
    printf("Dose ton arithmo ton kathigiton: ");
    kathigites = GetInteger();
    // Εισαγωγη στοιχειων για καθε υπαλληλο
    get_data(kathigites,staff);
    // Υπολογισμος μικτων-κρατησεων-φορου-και καθαρων κερδων
    calc_salaries(kathigites,staff);
    // Εκτυπωση αποτελεσματων
    print_data(kathigites,staff);


    system("PAUSE");
    return 0;
}

// Συναρτηση εισαγωγης στοιχειων για καθε υπαλληλο
void get_data(int kathigites, employeeT staff[])
{
    for(int i=0; i<kathigites; i++){
        printf("\nDose ta stoixeia tou kathigiti %d\n", i);
        printf("Dose onoma: ");
        gets(staff[i].name);
        printf("Dose eponymo: ");
        gets(staff[i].sname);
        printf("Dose mishto oras: ");
        staff[i].misthos_anawra = GetReal();
        printf("Dose ores ergasias: ");
        staff[i].wres_ergas = GetInteger();
    }
}
// Συναρτηση υπολογισμου μικτων-κρατησεων-φορου-και καθαρων κερδων
void calc_salaries(int kathigites, employeeT staff[])
{
     for(int i=0; i<kathigites; i++){
        staff[i].miktes_apodox = staff[i].misthos_anawra*staff[i].wres_ergas;
        staff[i].kratiseis = 0.15*staff[i].miktes_apodox;
        staff[i].foros = 0.07*(staff[i].miktes_apodox - staff[i].kratiseis);
        staff[i].kathares_apodox = staff[i].miktes_apodox - staff[i].kratiseis - staff[i].foros;
     }
}
// Συναρτηση εμφανισης αποτελεσματων
void print_data(int kathigites, employeeT staff[])
{


    printf("%-20s %-20s %-15s %-18s %-9s %-14s %-7s %s\n","Name","Surname","Hourly Rate","Hours Worked","Gross","Deductions","Tax","Net");
    for(int i=1; i<=113; i++)
        printf("-");
    printf("\n");
    for(int i=0; i<kathigites; i++){
        printf("%-20s %-20s %11.2f %16d %11.2f %14.2f %7.2f %7.2f\n",
               staff[i].name,
               staff[i].sname,
               staff[i].misthos_anawra,
               staff[i].wres_ergas,
               staff[i].miktes_apodox,
               staff[i].kratiseis,
               staff[i].foros,
               staff[i].kathares_apodox
               );
    }
    for(int i=1; i<=113; i++)
        printf("-");
    printf("\n");
}
