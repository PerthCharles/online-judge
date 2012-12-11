#include<stdio.h>
void main()
{
  while(1)
  {
    int M,N;
    int flag;
    scanf("%d",&M);
    if(M<=0) break;
    else scanf("%d",&N);
    int **a,**b,**c;//declare three dynamic 2-dimension arrays
    a=(int **)malloc(sizeof(int*)*M);//notice here is sizeof(int *)
    b=(int **)malloc(sizeof(int*)*M);//declare the number of rows
    c=(int **)malloc(sizeof(int*)*M);
    int count=0;
    int tmpm,tmpn;
    for(tmpm=0;tmpm<M;tmpm++)
    {
      a[tmpm]=(int *)malloc(sizeof(int)*N);//declare the length each line
      b[tmpm]=(int *)malloc(sizeof(int)*N);//also means the number of columns
      c[tmpm]=(int *)malloc(sizeof(int)*N);
    }
    for(tmpm=0;tmpm<M;tmpm++)//initialize array a
    {
      for(tmpn=0;tmpn<N;tmpn++)
      {
        scanf("%d",&a[tmpm][tmpn]);
      }
    }
    for(tmpm=0;tmpm<M;tmpm++)//initialize array b
    {
      for(tmpn=0;tmpn<N;tmpn++)
      {
        scanf("%d",&b[tmpm][tmpn]);
      }
    }
    for(tmpm=0;tmpm<M;tmpm++)//caculate matrices a+b 
    {
      flag=0;
      for(tmpn=0;tmpn<N;tmpn++)
      {
        c[tmpm][tmpn]=a[tmpm][tmpn]+b[tmpm][tmpn];
        if(c[tmpm][tmpn]!=0)
        {
          flag=1;//change the flag into 1 if this row has a non-zero number 
        } 
      }
      if(flag == 0) count++;
    }
    for(tmpn=0;tmpn<N;tmpn++)
    {
      flag=0; 
      for(tmpm=0;tmpm<M;tmpm++)
      {
        if(c[tmpm][tmpn]!=0) flag=1;//change the flag into 1 if this colunme has a non-zero number
      }
      if(flag==0) count++;
    }
    printf("%d\n",count);
    for(tmpm=0;tmpm<M;tmpm++)//to free 2-dimension dynamic array 
    {
      free(a[tmpm]); 
      free(b[tmpm]);
      free(c[tmpm]);
    }
    free(a);
    free(b);
    free(c);
  }
}
