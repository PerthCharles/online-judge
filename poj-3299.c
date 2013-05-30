#include <stdio.h>
#include <math.h>

int main()
{       
        float t, d, h, e;
	float tmp1, tmp2;
        char a, b;
        while(scanf("%c", &a) != EOF){
                if(a == 'E'){
                        break;
                }
                else{
                        if(scanf("%f %c %f", &tmp1, &b, &tmp2) == -1){
                                printf("you must be kidding me!\n");
                        }
                }
		getchar();//scanf函数要用的很仔细啊！
		//printf("a:%c b:%c\n", a, b);
		if(a == 'D' && b == 'T'){
			d = tmp1;
			t = tmp2;
                	e = 6.11*exp(5417.7530*((1/273.16)-(1/(d + 273.16))));
                	h = (0.5555)*(e - 10.0) + t;
		}
		else if(a == 'T' && b == 'D'){
			d = tmp2;
			t = tmp1;
                	e = 6.11*exp(5417.7530*((1/273.16)-(1/(d + 273.16))));
                	h = (0.5555)*(e - 10.0) + t;
		}
		else if(a == 'D' && b == 'H'){
			d = tmp1;
			h = tmp2;
                	e = 6.11*exp(5417.7530*((1/273.16)-(1/(d + 273.16))));
                	t = h - (0.5555)*(e - 10.0);
		}
		else if(a == 'H' && b == 'D'){
			d = tmp2;
			h = tmp1;
                	e = 6.11*exp(5417.7530*((1/273.16)-(1/(d + 273.16))));
                	t = h - (0.5555)*(e - 10.0);
		}
		else if(a == 'T' && b == 'H'){
			t = tmp1;
			h = tmp2;
			e = (h - t)/0.5555 + 10.0;
			d = 1 / ( -log(e / 6.11) / 5417.7530 + 1 / 273.16) - 273.16;
		}
		else if(a == 'H' && b == 'T'){
			t = tmp2;
			h = tmp1;
			e = (h - t)/0.5555 + 10.0;
			d = 1 / ( -log(e / 6.11) / 5417.7530 + 1 / 273.16) - 273.16;
		}
                printf("T %0.1f D %0.1f H %0.1f\n", t, d, h);
        }
	return 0;
}

