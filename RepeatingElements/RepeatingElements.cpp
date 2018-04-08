/* Problem Statement: Given an array of n+2 elements, all elements from 1 to n occur
 * once except 2. Find the 2 repeating elements.
 * Author: Kajal Damji Gada
 * Date Created: 7th April, 2018
*/

#include <iostream>
#include <vector>
#include <math.h>

int func_fact(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return (n * func_fact(n-1));
	}
}

int main()
{
	
	std::vector<int> arr = {1,2,3,3,4,5,6,6,7};

	int arrSize = arr.size();
	int n = arrSize - 2;

	// Compute sum of array
	int sum = 0;
	for (int arrInd = 0; arrInd < arr.size(); ++arrInd)
	{
		sum += arr[arrInd];
	}

	// Compute product of array
	int prod = 1;
	for (int arrInd = 0; arrInd < arr.size(); ++arrInd)
	{
		prod *= arr[arrInd];
	}

	//std::cout << "Sum: " << sum << " Product: " << prod << std::endl;

	// Compute sum of n and product of n
	int expSum = n * (n + 1)/2;
	int expProd = func_fact(n);
	//std::cout << "Expected Sum: " << expSum << " Expected Product: " << expProd << std::endl;

	// Compute difference to get (a+b) and (a*b)
	int n1 = sum - expSum;
	int n2 = prod/expProd;
	//std::cout << "n1: " << n1 << " n2: " << n2 << std::endl;

	/* Find repeating elements a and b
	* (a + b) = n1
	* (a * b) = n2
	* (a - b)^2 = (a+b)^2 - 4ab
	* (a - b)^2 = (n1)^2 - 4n2
	* (a - b) = sqrt(n1^2 - 4n2 = n3
	*/

	int n3 = sqrt((n1*n1) - (4*n2));
	//std::cout << "n3: " << n3 << std::endl;

	/* a + b = n1
	 * a - b = n3
	 * 2a = n1 + n3
	*/

	int a = (n1 + n3)/2;
	int b = n1 - a;

	// Print results
	std::cout << "Repeating elements are: " << a << " " << b << std::endl;


	return 0;
} 



