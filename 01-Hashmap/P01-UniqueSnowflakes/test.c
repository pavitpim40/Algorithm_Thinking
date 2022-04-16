#include <stdio.h>

int	identical_rigth(int snow1[], int snow2[], int start)
{
	int offset;
	for (offset = 0 ; offset < 6 ; offset++)
	{
		if(snow1[offset] != snow2[(start + offset) % 6])
			return (0);
	}
	return (1);
}

int	identical_left(int snow1[], int snow2[], int start)
{
	int offset;
	int snow2_index;
	for (offset = 0 ; offset < 6 ; offset++)
	{
		snow2_index = start - offset;
		if (snow2_index < 0)
			snow2_index += 6;
		if(snow1[offset] != snow2[snow2_index])
			return (0);
	}
	return (1);
}

int are_identical(int snow1[], int snow2[])
{
	int start;
	for (start = 0 ; start < 6; start++)
	{
		if(identical_rigth(snow1,snow2,start))
			return (1);
		if(identical_left(snow1,snow2,start))
			return (1);
	}
	return (0);
}

int main() 
{
	int snow1[6] = {1,2,3,4,5,6};
	// int snow2[6] = {1,2,3,4,5,6};
	// int snow2[6] = {4,5,6,1,2,3};
	int snow2[6] = {3,2,1,6,5,4};
	int result;

	result = are_identical(snow1,snow2);
	if(result)
		printf("Twin snowflakes found\n");
	else
		printf("Unique snowflake found\n");

	return (0);
}