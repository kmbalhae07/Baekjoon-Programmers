#include <stdio.h>
int main()
{
	int first, after,count=0;
	scanf("%d", &after);
	first=after;
	
	while(1) {
	first= (first%10)*10+ (first%10 + first/10) %10;	
	if(first==after) break;
	count++;
	
	}
	printf("%d", count+1);
}
