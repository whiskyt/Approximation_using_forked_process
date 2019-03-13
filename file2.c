// this is to be run in file1 in forked process

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

float powerOf(float x, int n) // function to get the n-th power of a decimal number
{
	float temp = x;
	while(n>1)
	{
		temp = temp*x;
		n--;
	}
	return temp;
}

int factorial(int n) // function to the factorial of an integer
{
	if(n ==1)
		return 1;
	else
		return n*(factorial(n-1));
}

float approx(int terms, float x) // function for the approximation of e^x
{
	float sum = 1;
	for(int i =1;i<=terms;i++)
	{
		sum = sum + ((powerOf(x,i))/(factorial(i)));
		//printf("%f\n",sum);
	}
	return sum;
}

void main(int n, char *argv[]) // main
{
	pid_t pid = getpid(); // gets process id 

	//printf("powerOf(0.5,2) is %f\n",powerOf(0.5,2));
	//printf("factorial of 4 is %d\n",factorial(4));
	char *a = argv[2];
	int num = atoi(a); // converts char* to int
	float x = atof(argv[1]); // converts char* to float	
	//printf("num is %d and x is %f\n",num,x);
	printf("CHILD (	PID = %d): for x = %.2f the first %d terms yield %f\n",pid,x,num,approx(num,x));
	//printf("Approximation is : %f\n ",approx(num,x));
}
