/*
ID:zhongbi1
LANG:C
PROG:ride
 */
#include<stdio.h>
main()
{
	FILE *fin=fopen("ride.in","r");
	FILE *fout=fopen("ride.out","w");
	int a=1,b=1;
	int tmp,tmp2;
	char *s1,*s2;
	s1=(char *)malloc(sizeof(char)*7);
	s2=(char *)malloc(sizeof(char)*7);
	fscanf(fin,"%s %s",s1,s2);
/*	for(tmp=0;tmp<6;tmp++)
	{
        if(s1[tmp!='\0'])
        {
            tmp2=s1[tmp]-64;//A's ascii value is 65
            a*=tmp2;
        }
        if(s2[tmp]!='\0')
        {
		    tmp3=s2[tmp]-64;
		    b*=tmp3;
        }
	}
*/
    tmp=0;
    while(s1[tmp]!='\0')
    {
        tmp2=s1[tmp]-64;//A's ascii value is 65
        a *=tmp2;
        tmp++;
        printf("%d ",tmp2);
    }
    printf("\n");
    tmp=0;
    while(s2[tmp]!='\0')
    {
        tmp2=s2[tmp]-64;
        b *=tmp2;
        tmp++;
        printf("%d ",tmp2);
    }
    printf("\n");
    if(a%47==b%47)
		fprintf(fout,"GO\n");
	else
		fprintf(fout,"STAY\n");
	exit(0);
}
