#include <stdio.h>
int main()
{ 
	int n,max=0,sum=0;	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		int score;
		scanf("%d", &score);
		sum = sum + score;
		
			if(score > max)		max = score;
			
	}
	double fscore = (double)sum/(max*n)*100;
	printf("%f",fscore);
}