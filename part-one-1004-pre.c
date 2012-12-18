/*This is the pre-question of 1004, as assumed that the length of two array is the same*/

#include<stdio.h>
void main()
{
//  int *a,*b;
//  int lena,lenb;
  int len;
  while(scanf("%d",&len)!=EOF)
  {
    int *a,*b;
    //int medium;
    void init_array(int *a,int len);
    int find_medium(int *a,int *b,int left1,int right1,int left2,int right2);
   // int find_medium(int *a,int *b,int left,int right);
    a=(int *)malloc(sizeof(int)*len);
    b=(int *)malloc(sizeof(int)*len);
    
    init_array(a,len);
    init_array(b,len);
    printf("%d\n",find_medium(a,b,0,len-1,0,len-1));
  }
}

void init_array(int *a,int len)
{
  int tmp;
  for(tmp=0;tmp<len;tmp++)
  {
    scanf("%d",&a[tmp]);
  }
}

int find_medium(int *a,int *b,int left1,int right1,int left2,int right2)
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
    (right1-left1)%2==1?  find_medium(a,b,mid1+1,right1,left2,mid2):find_medium(a,b,mid1,right1,left2,mid2);
  }
  else 
    (right1-left1)%2==1?  find_medium(a,b,left1,mid1,mid2+1,right2):find_medium(a,b,left1,mid1,mid2,right2);
}








