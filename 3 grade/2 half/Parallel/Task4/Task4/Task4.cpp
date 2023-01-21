#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	int k, rank;
	cin >> k;

#pragma omp parallel num_threads(k) private(rank)
	{
#pragma omp critical 
		{
			rank = omp_get_thread_num();
			cout << "I am " << rank << " thread." << endl;
		}
	}
}