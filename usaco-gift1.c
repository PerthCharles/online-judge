/*
ID:zhongbi1
LANG:C
PROG:gift1
*/

#include<stdio.h>
#include<string.h>//for strcmp
#define NP 20
void main()
{
    char name[NP][14],tmpname[14];
    int money[NP]={0};
    int tmpmoney=0,tmpj=0,j=0;
    int tmpnum=0;//tmpnum for how much person will be given
    int npnum=0;//# of NP
    int tmp=0,tmp2=0;//loop variable
    FILE *fin,*fout;
    fin=fopen("gift1.in","r");
    fout=fopen("gift1.out","w");
    fscanf(fin,"%d",&npnum);//# of NP
    for(tmp=0;tmp<npnum;tmp++)//read name of each person
    {
        fscanf(fin,"%s",name[tmp]);
    }
    for(tmp=0;tmp<npnum;tmp++)
    {
        tmp2=0;
        fscanf(fin,"%s",tmpname);
        while(strcmp(name[tmp2],tmpname))//find tmpname in namelist 
            tmp2++;
        fscanf(fin,"%d %d",&tmpmoney,&tmpnum);
        if(tmpnum==0)
        {
            j=0;
        }
        else
        {
            j=tmpmoney/tmpnum;
            money[tmp2]=money[tmp2]-tmpnum*j;
            for(tmpj=0;tmpj<tmpnum;tmpj++)
            {
                tmp2=0;
                fscanf(fin,"%s",tmpname);
                while(strcmp(name[tmp2],tmpname))
                    tmp2++;
                money[tmp2]=money[tmp2]+j;
                if(tmp2==3) printf("%d %d\n",money[tmp2],j);
            }
        }
    }
    for(tmp=0;tmp<npnum;tmp++)
    {
        fprintf(fout,"%s %d\n",name[tmp],money[tmp]);
    }
    exit(0);
}
