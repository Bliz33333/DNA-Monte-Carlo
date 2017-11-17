//============================================================================
// Name        : DNA-Monte_Carlo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
using namespace std;

int main()
{
	srand(time(NULL));
//	long double mutationU = .0001;
	long double mutationN = .00000001;
	long double numSims = 100000;
	long double fails[5] = { 0, 0, 0, 0, 0 };
	long double sds[5] = {0, 0, 0, 0, 0};

	bool unchanged[5][(int)numSims] = { 0 };
	int depth[5] = {1, 10, 100, 1000, 10000};

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<long double> dist(0.0, 1.0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < numSims; j++)
		{
			bool b = true;
			cout << j << endl;
			for (int k = 0; k < depth[i]; k++)
			{
				if (b && dist(mt) <= mutationN)
				{
//					cout << "fail" << endl;
					b = false;
					fails[i]++;
					break;
				}
			}
			unchanged[i][j] = b;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		long double average = (numSims - fails[i])/numSims;
		long double runningSum = 0;
		for (int j = 0; j < numSims; j++)
		{
			long double diff = unchanged[i][j] - average;
			runningSum += pow(diff, 2);
		}
		sds[i] = sqrt(runningSum/(numSims - 1));
	}


	cout << "Success Chances" << endl;
	cout << (numSims - fails[0])/numSims << endl;
	cout << (numSims - fails[1])/numSims << endl;
	cout << (numSims - fails[2])/numSims << endl;
	cout << (numSims - fails[3])/numSims << endl;
	cout << (numSims - fails[4])/numSims << endl;

	cout << "Standard Deviations" << endl;
	cout << sds[0] << endl;
	cout << sds[1] << endl;
	cout << sds[2] << endl;
	cout << sds[3] << endl;
	cout << sds[4] << endl;
	return 0;
}
