#include<stdio.h>
#include<stdlib.h>
/*
int main()
{
	int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int B[10] = { 10,11,12,13,14,15,16,17,18,19 };
	int ret = 0;
	for (int i = 0; i < 10; i++)
	{
		ret = A[i];
		A[i] = B[i];
		B[i] = ret;
	}
	system("pause");
	return 0;
}
*/

int main()
{
	int a = -1;
	int n = -1;
	double sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		n = a * n;
		sum = sum + n * (1 / i);
	}
	printf("ºÍÎª%.10lf",sum);
	system("pause");
	return 0;
}