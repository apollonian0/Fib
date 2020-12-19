// Copyright Ben Howenstein 2020. All rights reserved.
//

#include <iostream>

//	Recursive
//
unsigned long fib(const int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return fib(n - 2) + fib(n - 1);
}

//	Iterative
//
unsigned long fib2(int n)
{
	if (n <= 0)
	{
		return 0;
	}

	unsigned long prevSum = 0;
	unsigned long sum = 1;
	for (; n >= 2; --n)
	{
		const auto tmpSum = sum;
		sum += prevSum;
		prevSum = tmpSum;
	}
	return sum;
}

//	Tail recursive
//
unsigned long fib3(const int n, const unsigned long sum = 1, const unsigned long prevSum = 0)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return sum + prevSum;
	}
	return fib3(n - 1, sum + prevSum, sum);
}

int main()
{
	using namespace std;
    
	auto testFib = [](const int n)
	{
		cout << "fib(" << n << ") = " << fib(n) << endl;
		cout << "fib2(" << n << ") = " << fib2(n) << endl;
		cout << "fib3(" << n << ") = " << fib3(n) << endl;
	};

	testFib(1);
	testFib(12);
	testFib(35);
}
