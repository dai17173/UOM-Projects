#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <ctype.h>
#include <string.h>
#include <math.h>

#define LEN 80

void removeSpaces(char s[LEN],char out[LEN]);

main()
{
    char str[LEN],name[LEN],server[LEN],temp[LEN];
    int index1,i,j;

    printf("Dose to email sou :");
    gets(temp);
    removeSpaces(temp,str);
    index1=0;
    while (str[index1]!='@')
    {
        index1++;
    }
    strncpy(name,str,index1);
    name[index1]='\0';
    strncpy(server,str+index1+1,(strlen(str)-index1));

    printf("Original email address : %s\n",str);
    printf("Name : %s LENGTH = %d\n",name,strlen(name));
    printf("Server: %s\n",server);

    system("PAUSE");
    return 0;
}

void removeSpaces(char s[LEN],char out[LEN])
{
    int i,j;
    j=0;
    for(i=0; i<=strlen(s); i++)
        if(s[i]!=' '){
            out[j]=s[i];
            j++;
        }
}
