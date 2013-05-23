/*
 * 给一个浮点数m，然后求使式子1/2+1/3+1/4+...+1/(1+n)不小与m的最小的n
 * 思路：
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float m;
	int n, i;
	//while(scanf("%f", &m) != EOF){
	while(scanf("%f", &m) != EOF && m != 0.0){
		for(i = 2; i < 400; i++){
			if(m > 0){
				m -= 1.0/i;
		//		printf("m %f\n", m);
			}
			else{
				break;
			}
		}
		printf("%d card(s)\n", i-2);
	}
	return 0;
}
