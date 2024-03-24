#include <stdio.h>
int main()
{
	int A,B,C,make=0;
	scanf("%d %d %d", &A, &B, &C);
	
	if(C==B || B>C) 
		printf("-1"); 
	else {
		int k = A/(C-B);
		while (make<=k)
			make++;
	
		printf("%d",make);
	}
}
