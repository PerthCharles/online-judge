#include<stdio.h>

void main()
{
  void init_array(long int* a,int len);//init the array
  long int find_medium(long int* a,long int* b,int len_one_low,int len_one_up,int len_two_low,int len_two_up);//change the array's length to the same
  int len_one,len_two;
  long int *a,*b; 
  while(scanf("%d",&len_one)!=EOF)
  {
    a=(long int*)malloc(sizeof(long int)*(len_one+1));//declare one more space for add a number when needed
    init_array(a,len_one);
    scanf("%d",&len_two);
    b=(long int*)malloc(sizeof(long int)*(len_two+1));
    init_array(b,len_two);
    printf("%ld\n",find_medium(a,b,0,len_one-1,0,len_two-1));
  }
}

void init_array(long int* a,int len)
{
  int tmp;
  for(tmp=0;tmp<len;tmp++)
  {
    scanf("%ld",&a[tmp]);
  }
}

long int find_medium(long int *a,long int *b,int len_one_low,int len_one_up,int len_two_low,int len_two_up)
{
//  printf("aha1111:%d %d\n",len_one_up,len_two_up);
  int diff;//the difference of length 
  long int find_medium2(long int *a,long int *b,int left1,int right1,int left2,int right2);//find the midium when the length is the same
  
  if(len_one_up==len_two_up) 
    return find_medium2(a,b,len_one_low,len_one_up,len_two_low,len_two_up);  
  if(len_one_up>len_two_up)//a is longer then b
  {
    //all in a is bigger then all in b 
    if(a[len_one_low]>=b[len_two_up])
    { 
//       printf("aha:%d %d\n",(len_two_up+len_one_up)/2,len_two_up-1);
       //be careful for the difference between odd and even, (len_one_up-len_two_up)%2 is added for solving this difference
       return a[(len_two_up+len_one_up)/2-len_two_up-1+(len_one_up-len_two_up)%2];
    }
    //all in b is bigger then all in a
    if(b[len_two_low]>=a[len_one_up]) 
      return a[(len_two_up+len_one_up)/2+(len_one_up-len_two_up)%2];
    
    b[len_two_up+1]=a[len_one_up]+1;//add a number
   
    diff=(len_one_up-len_two_up)/2;//divide 2 is for convenience of coding
    if(len_one_up%2==0)//the length of a is odd,be careful with len_one_up and the true length of a 
    {
      if(len_two_up%2==0)
        //change the length to the same,more details please see the notes in README
        return find_medium2(a,b,len_one_low+diff,len_one_up-diff,len_two_low,len_two_up);
      else
        return find_medium2(a,b,len_one_low+diff,len_one_up-diff,len_two_low,len_two_up+1);
    }
    else
    {
      if(len_two_up%2==0)
        return find_medium2(a,b,len_one_low+diff,len_one_up-diff,len_two_low,len_two_up+1);
      else
       return find_medium2(a,b,len_one_low+diff,len_one_up-diff,len_two_low,len_two_up);
    }
  }
  else//when b is longer then a, almost the same
  {
    if(a[len_one_low]>=b[len_two_up]) return b[(len_two_up+len_one_up)/2+(len_two_up-len_one_up)%2];
    if(b[len_two_low]>=a[len_one_up]) return b[(len_two_up+len_one_up)/2-len_one_up-1+(len_two_up-len_one_up)%2];
    
    a[len_one_up+1]=b[len_two_up]+1;//add a number
   
    diff=(len_two_up-len_one_up)/2;
    if(len_one_up%2==0)
    {
      if(len_two_up%2==0)
        return find_medium2(a,b,len_one_low,len_one_up,len_two_low+diff,len_two_up-diff);
      else
        return find_medium2(a,b,len_one_low,len_one_up+1,len_two_low+diff,len_two_up-diff);
    }
    else
    {
      if(len_two_up%2==0)
        return find_medium2(a,b,len_one_low,len_one_up+1,len_two_low+diff,len_two_up-diff);
      else
       return find_medium2(a,b,len_one_low,len_one_up,len_two_low+diff,len_two_up-diff);
    }
  }
}

long int find_medium2(long int *a,long int *b,int left1,int right1,int left2,int right2)
{
  int mid1,mid2;
  if(left1==right1) return a[left1]<=b[left2]? a[left1]:b[left2];
  mid1=(left1+right1)/2;
  mid2=(left2+right2)/2;
  if(a[mid1]==b[mid2])
    return a[mid1];
  else if(a[mid1]<b[mid2])
  {
    //if the left length of array is even: (right1-left1)%2==1 means right-left+1 is even
    (right1-left1)%2==1?  find_medium2(a,b,mid1+1,right1,left2,mid2):find_medium2(a,b,mid1,right1,left2,mid2);
  }
  else
    (right1-left1)%2==1?  find_medium2(a,b,left1,mid1,mid2+1,right2):find_medium2(a,b,left1,mid1,mid2,right2);
}

