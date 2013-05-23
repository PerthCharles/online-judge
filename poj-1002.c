/*
 * 解题思路：
 * 	首先将输入转换成标准形式，然后快速排序，最后按序如果有重复的就输出
 * */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH 50
static int cmpline(const void *a, const void *b)
{
	return strcmp(a, b);
}

int main()
{
	int duplicates = 0;	//0 means no duplicates
	int n;
	int i;	//tmp loop variables
	int count = 1;

	void tran2std(char * input_line);
	void quick_sort(char ** input, int begin, int end);

	char **input;
	scanf("%d", &n);

	input = (char **)malloc(sizeof(char *) * n);
	for(i = 0; i < n; i++){
		input[i] = (char *)malloc(sizeof(char) * MAX_LENGTH);
		scanf("%s", input[i]);
		tran2std(input[i]);
	}
//	printf("before sort sizeof(input[0]):%d\n", sizeof(input[0]));
//for(i = 0; i < n; i++){
//	printf("[org]input[%d]:%s\n", i, input[i]);
//	printf("sizeof(input[i]):%d\n", sizeof(input[i]));
//}
	quick_sort(input, 0, n-1);
//	qsort(input, n, 8, (int (*) (const void *, const void *)) strcmp);
//	qsort(input, n, sizeof(input[0]), (int (*) (const void *, const void *)) strcmp);
//	qsort(input, n, 8, cmpline);
//	printf("after sort\n");
//for(i = 0; i < n; i++){
//	printf("[org]input[%d]:%s\n", i, input[i]);
//}
	for(i = 1; i < n; i++){
		if(strcmp(input[i-1], input[i]) == 0){
			count++;
		}
		else{
			if(count > 1){
				printf("%s %d\n", input[i - 1], count);
				duplicates = 1;
			}
			count = 1;
		}
	}
	if(count > 1){
		duplicates = 1;
		printf("%s %d\n", input[i - 1], count);
	}
	if(!duplicates){
		printf("No duplicates.\n");
	}
	return 0;
}


void tran2std(char * input_line)
{
	int i, j;
	int len;
	len = strlen(input_line);
	j = 0;
//	printf("[org]input_line:%s\n", input_line);
	for(i = 0; i < len; i++){
		input_line[i] = toupper(input_line[i]);
		switch(input_line[i]){
			case 'A':
			case 'B':
			case 'C':
				input_line[j] = '2';
				j++;
				break;
			case 'D':
			case 'E':
			case 'F':
				input_line[j] = '3';
				j++;
				break;
			case 'G':
			case 'H':
			case 'I':
				input_line[j] = '4';
				j++;
				break;
			case 'J':
			case 'K':
			case 'L':
				input_line[j] = '5';
				j++;
				break;
			case 'M':
			case 'N':
			case 'O':
				input_line[j] = '6';
				j++;
				break;
			case 'P':
			case 'R':
			case 'S':
				input_line[j] = '7';
				j++;
				break;
			case 'T':
			case 'U':
			case 'V':
				input_line[j] = '8';
				j++;
				break;
			case 'W':
			case 'X':
			case 'Y':
				input_line[j] = '9';
				j++;
				break;
			case '-':
				//keep going
				break;
			default:
				input_line[j] = input_line[i];
				j++;
		}
	}
	if(j == 7){
		input_line[7] = '\0';
	}
	else{
		printf("you must be kidding me, j:%d\n", j);
	}
	for(j = 7; j >= 3; j--){
		input_line[j+1] = input_line[j];
	}
	input_line[j+1] = '-';
//	printf("[std]input_line:%s\n", input_line);
}


void quick_sort(char ** input, int begin, int end)
{
	int i, j;
	char p[50];
	char tmp[50];
//	int mid;
	if(end <= begin){
		return;
	}
	i = begin;
	j = end;
	strcpy(p, input[begin]);
	while(i < j){
	//	mid = (i+j)/2;
		while(strcmp(input[j], p) > 0 && i < j) j--;
		if(strcmp(input[j], p) == 0 && i < j) j--;//若将这行和上一行合并，即使用>=作为判断条件，那么对于每行都相同的输入，将会是最坏的复杂度
		if(i < j){
			strcpy(input[i], input[j]);
		}
		while(strcmp(input[i], p) < 0 && i < j) i++;
		if(strcmp(input[i], p) == 0 && i < j) i++;
		if(i < j){
			strcpy(input[j], input[i]);
		}
	}
	strcpy(input[i], p);
	quick_sort(input, begin, i-1);
	quick_sort(input, i+1, end);
}


