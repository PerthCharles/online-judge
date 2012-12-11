#include<stdio.h>
void main()
{
  int a,b;
  while(scanf("%d %d",&a,&b)!=EOF)//make sure the scanf() is working properly
  {
    printf("%d\n",a+b);
  }
}
