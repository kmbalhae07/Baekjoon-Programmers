#include <stdio.h>
int main()
{
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	int x,y,i,k,v;	scanf("%d %d", &x,&y);
	int sum=0;
	
	for(i=1; i<x; i++) {
		sum = sum + days[i-1];
	}
	
		sum = sum + y;	int day = sum % 7;
		
	if(day==1)	printf("MON");
	else if (day==2)	printf("TUE");
	else if (day==3)	printf("WED");
	else if (day==4)	printf("THU");
	else if (day==5)	printf("FRI");
	else if (day==6)	printf("SAT");
	else if (day==0)	printf("SUN");
}	
