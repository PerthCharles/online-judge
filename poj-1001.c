#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH	1000

int main()
{
	void multi(char *multi_1, char *a, char *result);
	char a[LENGTH], result[LENGTH], multi_1[LENGTH];
	int has_point;
	int pow_p;	//temp loop variable for pow
	int point_p;	//temp loop variable for point_position
	int pow, position;
	int eliminate_end_zero;
	char * point;
	memset(a, 0, LENGTH);
	while(scanf("%s %d", a, &pow) != EOF){
		has_point = 0;
		position = 0;
		memset(result, 0, LENGTH);
		memset(multi_1, 0, LENGTH);
		if(pow == 0){	//为了符合AC条件，即使a是零，只要pow等于0，那么就输出1。 这点真郁闷
			printf("1\n");
			continue;
		}
		else if(atof(a) == 0.0){
			printf("0\n");
			continue;
		}
		if((point = strstr(a, ".")) != 0){
			has_point = 1;	//如果找到小数点，就标志为1
			*point = '\0';
			point++;
			position = strlen(point);
			strcat(a, point);//此时a已经是没有小数点的形式，小数点以后应该出现的位置通过pow*position计算出来
		}
		strcpy(result, a);
		for(pow_p = 1; pow_p < pow; pow_p++){
			strcpy(multi_1, result);
			multi(multi_1, a, result);//result = multi_1 * a
		}
		if(has_point){
			position = strlen(result) - pow*position;//计算小数点最终应该出现的位置
			for(point_p = strlen(result) + 1; point_p > position; point_p--){
				result[point_p] = result[point_p - 1];
			}
			result[point_p] = '.';
			point = result;
			while(point[0] == '0'){	//消除最前面出现的多余的0
				point++;
			}
			eliminate_end_zero = strlen(point) - 1;
			while(point[eliminate_end_zero] == '0' || point[eliminate_end_zero] == '.'){//消除最后面多余的0
				if(point[eliminate_end_zero] == '.'){
					point[eliminate_end_zero] = '\0';
					break;
				}
				point[eliminate_end_zero] = '\0';
				eliminate_end_zero--;
			}
			printf("%s\n", point);
		}
		else{
			point = result;
			while(point[0] == '0'){//没有小数点的情形只要消除前面的多余0就可以了。
			//	point_p++;
				point++;
			}
			printf("%s\n",  point);
		}
//		printf("postion is:%d\n", position);
//		printf("length of a:%d a:%f pow:%d\n\n", strlen(a), atof(a), pow);
	}
	return 0;
}

/*
 * multiple two big number by char-array simulate.
 * */
void multi(char *multi_1, char *a, char *result)
{
	int len1, len2;
	int tmp_value = 0;
	int i, j, carry = 0;
	int result_len_p;	//loop variable for result_len
	memset(result, 0, sizeof(result));
	for(i = strlen(multi_1) - 1; i >= 0; i--){
		for(j = strlen(a) - 1; j >= 0; j--){
			result_len_p = i + j + 1;
			if(result[result_len_p] != '\0'){	//如果result_len_p对应位置不为'\0'，则表明之前已经存入一个ASCII编码的字符代表一个数字。
				tmp_value = ((multi_1[i]-'0')*(a[j]-'0') + (result[result_len_p]-'0') + carry);
			}
			else{
				tmp_value = ((multi_1[i]-'0')*(a[j]-'0') + result[result_len_p] + carry);
			}
			result[result_len_p] = tmp_value % 10 + '0';
			carry = tmp_value/10;
		//	printf("multi_1[%d]:%c , a[%d]:%c , result[%d]:%c carry:%d\n", i, multi_1[i], j, a[j],
		//		 result_len_p, result[result_len_p], carry);
		}
		result[result_len_p - 1] = carry + '0';
		carry = 0;
	}
//	printf("multi_1:%s a:%s result:%s\n", multi_1, a, result);
}

