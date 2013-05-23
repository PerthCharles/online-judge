/*
 * 计算浮点数的平均值
 * */

#include <stdio.h>

int main()
{
	float sum, tmp;
	int i;
	for(i = 0; i < 12; i++){
		scanf("%f", &tmp);
		sum += tmp;
	}
	printf("$%.2f\n", sum/12);
	return 0;
}
