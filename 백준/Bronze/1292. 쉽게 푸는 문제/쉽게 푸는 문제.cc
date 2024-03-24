#include <stdio.h>
int main()
{
	int a,b,sum=0,k,cnt=0;
	
	scanf("%d %d", &a,&b);
	
		for (int i=1; i<=10000; i++) {
			
			for(int p=1; p<=i; p++)	{
				cnt ++;	k=i;	
				if(cnt>=a && cnt <=b) {
					sum += k;
				}
			}	
			if(cnt == b)	break;
		}
	printf("%d", sum);
}