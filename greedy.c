#include <stdio.h>
#include <cs50.h>
int main(void)
{
	float monetu;
	printf("Print change in coins:");
	monetu=GetFloat();
	while (monetu>=1.0 || monetu<0)
	    {
	        printf("This is not right. Retry:");
	        monetu=GetFloat();
	    }
	if (monetu>=0.25)
	{
		int count=0;
		while (monetu>=0.25)
		{
			count++;
			monetu=monetu-0.25;
		}
		printf("Number of quarters: %d\n", count);
	}
	if (monetu>=0.10)
	{
		int count2=0;
		while (monetu>=0.10)
		{
			count2++;
			monetu=monetu-0.10;
		}
		printf("Number of dimes: %d\n", count2);
	}
	if (monetu>=0.05)
	{
		int count3=0;
		while (monetu>=0.05)
		{
			count3++;
			monetu=monetu-0.05;
		}
		printf("Number of nickels: %d\n", count3);
	}
	if (monetu>=0.01)
	{
		int count4=0;
		while (monetu>=0.01)
		{
			count4++;
			monetu=monetu-0.01;
		}
		printf("Number of pennies: %d\n", count4);
	}
}