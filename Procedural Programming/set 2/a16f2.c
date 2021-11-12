#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
    int sms;
    double xrewsi;


    printf("Dose plithos sms :");
    sms = GetInteger();

    if (sms>=1 && sms<=10)
        xrewsi = sms*0.02;
    else if (sms>=11 && sms<=60)
        xrewsi = 10*0.02+(sms-10)*0.015;
    else if (sms>=61 && sms<=160)
        xrewsi = 10*0.02+50*0.015+(sms-60)*0.012;
    else if (sms>=161)
        xrewsi = 10*0.02+50*0.015+100*0.012+(sms-160)*0.01;
    printf("Synoliko poso se euro: %g", xrewsi);

}
