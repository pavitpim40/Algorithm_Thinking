/* 
O^2 Complexity
n(n-1)/2 = 0.5*(n^2 - n) 
if n = 100,000 give 4,999,950,000 (4999.95 M comparisons)
maybe 4 min to solve (we need 2 sec)
*/

#include <stdio.h>
#define SIZE 100000
// ---------------------------- OLD FUNCTION ---------------------------//
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

// ---------------------------- NEW FUNCTION ---------------------------//

void indentify_identical(int snowflake[][6],int n)
{
	int i,j;
	for (i = 0 ; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if(are_identical(snowflake[i],snowflake[j]))
			{
				printf("Twin snowflakes found.\n");
				return;
			}
		}
	}
	printf("No two snowflakes are alike.\n");
}
int main() 
{
	static int snowflake[SIZE][6];
	int n,i,j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for( j = 0; j < 6; j++)
			scanf("%d", &snowflake[i][j]);
	indentify_identical(snowflake,n);
	return (0);
}
