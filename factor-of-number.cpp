//https://byjus.com/maths/factors-of-a-number/#:~:text=The%20formula%20for%20the%20total,1)%20(c%2B1)
//https://www.geeksforgeeks.org/find-divisors-natural-number-set-1/
//https://www.geeksforgeeks.org/efficient-program-print-number-factors-n-numbers/

//Theory 
// Given n find the total number of factor of n.
// N = X^a × Y^b × Z^c       (X^a x to power of a)
// where X, Y and Z are the prime numbers and a, b and c are their respective powers.
//Total Number of Factors for N = (a+1) (b+1) (c+1)
// Sum of factors of N = [(X^(a+1)-1)/X-1] × [(Y^(b+1)-1)/Y-1] × [(Z^(c+1)-1)/Z-1]
// Product of factors of N = NTotal No. of Factors/2


// C++ implementation of Naive method to print all
// divisors
//Time complexity of this method is O(n)
#include <iostream>
using namespace std;

// function to print the divisors
void printDivisors(int n)
{
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			cout <<" " << i;
}

int main()
{
	cout <<"The divisors of 100 are: \n";
	printDivisors(100);
	return 0;
}






// A Better (than Naive) Solution to find all divisors
//Time complexity of this problem is O(sqrt(n))
#include <iostream>
#include <math.h>
using namespace std;

// Function to print the divisors
void printDivisors(int n)
{
	for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			if (n/i == i)
				cout <<" "<< i;

			else
				cout << " "<< i << " " << n/i;
		}
	}
}

int main()
{
	cout <<"The divisors of 100 are: \n";
	printDivisors(100);
	return 0;
}



//Time complxity of this program is  O(n * log(max(number)))
// C++ program to count number of factors
// of an array of integers
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

// array to store prime factors
int factor[MAX] = { 0 };

// function to generate all prime factors
// of numbers from 1 to 10^6
void generatePrimeFactors()
{
	factor[1] = 1;

	// Initializes all the positions with their value.
	for (int i = 2; i < MAX; i++)
		factor[i] = i;

	// Initializes all multiples of 2 with 2
	for (int i = 4; i < MAX; i += 2)
		factor[i] = 2;

	// A modified version of Sieve of Eratosthenes to
	// store the smallest prime factor that divides
	// every number.
	for (int i = 3; i * i < MAX; i++) {
		// check if it has no prime factor.
		if (factor[i] == i) {
			// Initializes of j starting from i*i
			for (int j = i * i; j < MAX; j += i) {
				// if it has no prime factor before, then
				// stores the smallest prime divisor
				if (factor[j] == j)
					factor[j] = i;
			}
		}
	}
}

// function to calculate number of factors
int calculateNoOfFactors(int n)
{
	if (n == 1)
		return 1;

	int ans = 1;

	// stores the smallest prime number
	// that divides n
	int dup = factor[n];

	// stores the count of number of times
	// a prime number divides n.
	int c = 1;

	// reduces to the next number after prime
	// factorization of n
	int j = n / factor[n];

	// false when prime factorization is done
	while (j != 1) {
		// if the same prime number is dividing n,
		// then we increase the count
		if (factor[j] == dup)
			c += 1;

		/* if its a new prime factor that is factorizing n,
		then we again set c=1 and change dup to the new
		prime factor, and apply the formula explained
		above. */
		else {
			dup = factor[j];
			ans = ans * (c + 1);
			c = 1;
		}

		// prime factorizes a number
		j = j / factor[j];
	}

	// for the last prime factor
	ans = ans * (c + 1);

	return ans;
}

// Driver program to test above function
int main()
{
	// generate prime factors of number
	// upto 10^6
	generatePrimeFactors();

	int a[] = { 10, 30, 100, 450, 987 };

	int q = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < q; i++)
		cout << calculateNoOFactors(a[i]) << " ";

	return 0;
}
