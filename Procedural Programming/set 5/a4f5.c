#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>


#define tm1 25000
#define tm2 15000
#define tm3 32000
#define tm4 21000
#define tm5 9200

main()
{
    long syn_eis1,syn_eis2,syn_eis3,syn_eis4;
    float syn_prom1=0,syn_prom2=0,syn_prom3=0,syn_prom4=0;
    int s_pos1=0,s_pos2=0,s_pos3=0,s_pos4=0,s_pos5=0,i;
    int A[4][5];


    A[0][0] = 10;
    A[0][1] = 4;
    A[0][2] = 5;
    A[0][3] = 6;
    A[0][4] = 7;

    A[1][0] = 7;
    A[1][1] = 0;
    A[1][2] = 12;
    A[1][3] = 1;
    A[1][4] = 3;

    A[2][0] = 4;
    A[2][1] = 9;
    A[2][2] = 5;
    A[2][3] = 0;
    A[2][4] = 8;

    A[3][0] = 3;
    A[3][1] = 2;
    A[3][2] = 1;
    A[3][3] = 5;
    A[3][4] = 6;


    syn_eis1 = A[0][0]*tm1 + A[0][1]*tm2 + A[0][2]*tm3 + A[0][3]*tm4 + A[0][4]*tm5;
    syn_eis2 = A[1][0]*tm1 + A[1][1]*tm2 + A[1][2]*tm3 + A[1][3]*tm4 + A[1][4]*tm5;
    syn_eis3 = A[2][0]*tm1 + A[2][1]*tm2 + A[2][2]*tm3 + A[2][3]*tm4 + A[2][4]*tm5;
    syn_eis4 = A[3][0]*tm1 + A[3][1]*tm2 + A[3][2]*tm3 + A[3][3]*tm4 + A[3][4]*tm5;


    syn_prom1 += syn_eis1*0.1;
    syn_prom2 += syn_eis2*0.1;
    syn_prom3 += syn_eis3*0.1;
    syn_prom4 += syn_eis4*0.1;


    for (i=0; i<4; i++)
    {
        s_pos1 += A[i][0];
        s_pos2 += A[i][1];
        s_pos3 += A[i][2];
        s_pos4 += A[i][3];
        s_pos5 += A[i][4];
    }

    printf("Synoliko Poso Eispaksis / Pwlhth: %ld %ld %ld %ld\n", syn_eis1, syn_eis2, syn_eis3, syn_eis4);
    printf("Promitheia / Pwlhth: %.2f %.2f %.2f %.2f\n", syn_prom1, syn_prom2, syn_prom3, syn_prom4);
    printf("Posothtes Proiontwn: %d %d %d %d %d\n", s_pos1, s_pos2, s_pos3, s_pos4, s_pos5);


    system("pause");
    return 0;
}
