#include <iostream>
#include <omp.h>

using namespace std;

int main() {
	int k, n = 0;
	cout << "Enter the nums of threads to run: ";
	cin >> k;

	int isEven;
	cout << "Do you want to display only even nums? ";
	cin >> isEven;

#pragma omp parallel num_threads(k) private (n)
	{
		n = omp_get_thread_num();
#pragma omp critical
		{
			if (isEven && n % 2 == 0)
				cout << "I am " << n << " thread from " << omp_get_num_threads() << " threads" << endl;
			else if (!isEven)
				cout << "I am " << n << " thread from " << omp_get_num_threads() << " threads" << endl;
		}

		//cout << "I am " << k << " thread from " << omp_get_num_threads() << " threads" << endl;
	}
}