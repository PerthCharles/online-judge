#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979
int main()
{
	int i, n, j;
	float x, y;
	float r;
	float s = 50.0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%f %f", &x, &y);
		//r = sqrt(x*x + y*y);
		r = x*x + y*y;
		for(j = 1; ; j++){
			//if(r > sqrt((2*s)/PI)){
			if(r < (100*j)/PI){
		//		s += 50;
		//		printf("s:%f\n", s);
		//	}
		//	else{
				break;
			}
		}
		printf("Property %d: This property will begin eroding in year %d.\n", i, j);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
