#include<stdio.h>
int main()
{
	int a=0,b=0;
	char *sa,*sb;
	sa=(char *)malloc(sizeof(char)*15);
	sb=(char *)malloc(sizeof(char)*15);
	//int tmp_a,tmp_b;
	//int sign_a=1,sign_b=1;
	int input_to_int(char *input);
	while(scanf("%s %s",sa,sb)!=EOF)//use this to solve the problem time out
	{
		a=input_to_int(sa);
		b=input_to_int(sb);
//		printf("%d %d\n",a,b);
		printf("%d\n",a+b);
	}
	return 0;
}
int input_to_int(char *input)
{
	int tmp=0,sign=1;
	int i;
	if(input[0]=='-') sign=-1;
	else tmp=input[0]-'0';
	i=1;
	while(input[i]!='\0')
	{
		if(input[i]>='0'&&input[i]<='9')
			tmp=tmp*10+input[i]-'0';
		i++;
	}
	return tmp*sign;
}
