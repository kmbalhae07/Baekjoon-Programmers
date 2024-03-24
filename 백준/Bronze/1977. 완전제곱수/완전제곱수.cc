#include <stdio.h>
#include <math.h>

int main()
{
	int sum = 0,a1,b1;
	int m,n;	 scanf("%d\n%d", &m, &n);
	
	int a = sqrt( (double)m );	
	int b = sqrt( (double)n );
	
	
	if(a*a==m)		 a1 = a;
	else			 a1 = a/1 +1 ;
	
/*	if(b*b==n)		b1 = b;
	else			b1 = b/1 +1 ;
*/
	b1 = b/1;
	
		
	if(m==n && a*a==m) 		printf("%d\n%d",m,m);
	
	else if(a1>b1)	printf("-1");
	
	else {
		for (int i=a1; i<=b1; i++) {
			sum = sum + i*i;
		}
		int p = a1*a1;
		printf("%d\n%d", sum,p);
	}		
}
