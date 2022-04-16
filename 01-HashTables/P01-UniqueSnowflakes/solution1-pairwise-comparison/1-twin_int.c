#include <stdio.h>

void identify_identical(int arr[], int n)
{
	int	i;
	int	j;
	for (i = 0; i < n ; i++)
	{
		for (j = i + 1 ; j < n ; j ++)
		{
			if (arr[i] == arr[j])
			{
				printf("Twin integer found.\n");
				return;
			}
		}
	}
	printf("No two integers are alike.\n");
}

int main ()
{
	int arr1[6] = {1,2,3,4,3,6};
	int arr2[6] = {1,2,3,4,5,6};

	identify_identical(arr1,6);
	identify_identical(arr2,6);
	return (0);
}