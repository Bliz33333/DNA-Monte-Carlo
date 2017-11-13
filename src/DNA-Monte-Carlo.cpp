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
using namespace std;

int main()
{
	srand(time(NULL));
	long double mutationU = .0001;
	long double mutationN = .00000001;
	int numSims = 100000;
	int fails[5] = {0,0,0,0,0};

	bool unchanged[5][numSims] = {0};
	int depth[4] = {10, 100, 1000, 10000};

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<long double> dist(0.0, 1.0);

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < numSims; j++)
		{
			bool b = true;
			cout << j << endl;
			for(int k = 0; k < depth[i]; k++)
			{
				if(b && dist(mt) <= mutationU)
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

	cout << fails[0] << endl;
	cout << fails[1] << endl;
	cout << fails[2] << endl;
	cout << fails[3] << endl;
	cout << fails[4] << endl;
	return 0;
}
