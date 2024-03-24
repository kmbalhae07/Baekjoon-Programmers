#include <stdio.h>
int main()
{
	int k;	scanf("%d", &k);
	int p=1, cnt=0;
	
	while(1){
		p= p + cnt*6;
		if(p>=k)	break;
		
		cnt++;
	}
	
	printf("%d", cnt+1);
	
}