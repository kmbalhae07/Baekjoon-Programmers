#include <stdio.h>
int main()
{
	int v,k,x,cnt=0,floor=1;	scanf("%d", &x);
	
	for (int i=0; i<x; i++) {
		
		v=0;
		for(k=0; k<floor; k++) {  
			v=v+1;	cnt++;	
			if(v==floor) break;
			else if(cnt==x)	break;
		}
		
		if(cnt==x) break;
		floor= floor+1; 
	}
	
	int sum=0 ;
	for(int z=1; z<floor; z++)	sum=sum+z;
	
	sum = sum+1;
	int select = x-sum;
	int a= floor- select; int b=1+select;

	if(floor%2==1)
	printf("%d/%d", a,b);  
	
	else
	printf("%d/%d",b,a);	
}

