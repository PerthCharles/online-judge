/*
 *可以用到互质的性质
 * */

#include <stdio.h>

int get_m(int a, int b, int c)
{
    int ab, ab_r;
    int i, j;
    ab = a*b;
    ab_r = ab%c;
    j = ab;
    for(i = 0; i < c; i ++){
        if(ab % c == 1)
            return ab;
        else
            ab += j;
    }
    return -1;
}

int main()
{
	int p, e, i, start, case_count = 0;
	int tmp;
	while(scanf("%d %d %d %d", &p, &e, &i, &start) != EOF){
		if(start == -1){
			break;
		}
		case_count++;
		tmp = (p*get_m(28, 33, 23) + e*get_m(23, 33, 28) + i*get_m(23, 28, 33))%21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", case_count, (tmp > start) ? (tmp-start):(tmp+21252-start) );
	}
}

