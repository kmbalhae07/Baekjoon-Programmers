#include <stdio.h> 
int Rev(int number); 
int main() 
{ 
	int x, y, result; 
	scanf("%d %d", &x, &y); 
	result = Rev(Rev(x) + Rev(y)); 
	printf("%d", result); 
	return 0; 
} 

int Rev(int number) 
{ 
	int result = 0; 
	while (number != 0) 
	{	 
    	result *= 10; 
		result += number % 10; 
    	number /= 10; 
 	} 
 	return result; 
} 