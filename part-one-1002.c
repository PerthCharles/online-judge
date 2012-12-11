#include<stdio.h>
#include<stdlib.h>
/*this method is also working*/ 
//#define MAX(x,y) (x)<(y)? (y):(x)

void main()
{
	int isinT(int a,int b,int T);
	int max(int a,int b);
	int P,T,G1,G2,G3,GJ;
	while(scanf("%d %d %d %d %d %d",&P,&T,&G1,&G2,&G3,&GJ)!=EOF)
	{
		if(isinT(G1,G2,T)==1) printf("%.1f\n",(G1+G2)/2.0);
		else if(isinT(G1,G3,T)==1)
		{
			if(isinT(G2,G3,T)==1) printf("%.1f\n",max(G1,max(G2,G3))*1.0);
			else printf("%.1f\n",(G1+G3)/2.0);//this kind of online judge need to be fomulized, so the "\n" is needed!!!
		}
		else if(isinT(G2,G3,T)==1) printf("%.1f\n",(G2+G3)/2.0);
		else printf("%.1f\n",GJ*1.0);//pay attention to precision
	}
}
int isinT(int a,int b,int T)//jobdu doesn't support type of bool, so i use int to replace it
{
	if(abs(a-b)<=T) return 1;
	else return 0;
}
int max(int a,int b)
{
	return(a>b? a:b); 
}
