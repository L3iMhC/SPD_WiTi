#include "Algortimhs.h"

int CountCryterium(int n, vector <WiTicontainer> data)
{
	int* S = new int[n];
	int* T = new int[n];
	int F;

	S[0] = 0;
	T[0] = max(S[0] + data[0].p - data[0].d, 0);
	F = T[0]*data[0].w;

	for (int i = 1; i < n; i++)
	{
		S[i] = S[i - 1] + data[i - 1].p;
		T[i] = max(S[i] + data[i].p - data[i].d, 0);
		F += T[i] * data[i].w;
	}

	delete[] S, T;
	return F;
}

vector<WiTicontainer> SortD(int n, vector <WiTicontainer> data)
{
	vector<WiTicontainer> kopia = data;

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (kopia[i].d > kopia[j].d)
			{
				WiTicontainer kopia2 = kopia[i];
				kopia[i] = kopia[j];
				kopia[j] = kopia2;
			}
		}
	}
	return kopia;
}
/*
Brute::Brute(int n)
{
	opt; result = 100000;
	dp = new int* [2 ^ n];
	for (int i = 0; i < (2 ^ n); i++)
		dp[i] = new int[n];
	memset(dp, -1, sizeof dp);// set all subsets to -1
}
*/
Brute BruteForce(int n, vector <WiTicontainer> data)
{
	Brute outcome;
	vector <WiTicontainer> kopia, wynik;
	kopia = data;
	int F = 0;
	int wynik1=1000000;

	do 
	{
		F = CountCryterium(n, kopia);
		if (F < wynik1)
		{
			wynik1 = F;
			wynik = kopia;
		}
	} while (std::next_permutation(kopia.begin(), kopia.end(),
		[](const auto& lhs, const auto& rhs)
		{ return lhs.indeks < rhs.indeks; }));

	outcome.opt = wynik;
	outcome.result = wynik1;

	return outcome;
}

int Dynamic(int n, vector <WiTicontainer> data)
{
	Brute result;
	int outcome;
	ALLMASK = (1 << n) - 1;//All bits are set to 1, for reference

	//memset(result.dp, -1, sizeof result.dp);// set all subsets to -1

	outcome = result.Calc(n, data, 0, 1);

	return outcome;
}


int Brute::Calc(int n, vector <WiTicontainer> data, int mask, int operation)
{
	int F = 100000;//latency
	int newlatency;

	if (mask == ALLMASK)
		return dp[mask] [operation];
	
	if (dp[mask][operation] != -1) return dp[mask][operation];

	for (int j = 0; j < n; j++)
	{
		int sum = 0;
		if (!(mask & (1 << data[j].indeks)))//if it is not in mask
		{
			for (int g = 0; g < n; g++)
			{
				if ((mask & (1 << data[g].indeks)))//rest of elements in mask
					sum += data[g].p;
			}
			newlatency = max(-1 * data[j].d + sum + data[j].p, 0) * data[j].w + Calc(n, data, mask | (1 << data[j].indeks), operation + 1);
			F = min(F, newlatency);
		}

	}

	return dp[mask][operation] = F;
}

/*
int solve(int n, int bitmask, int pos, int **dp, vector <WiTicontainer> data)
{
	// If we have solved this subproblem previously, return the result that was recorded
	if (dp[bitmask][pos] != -1)
		return dp[bitmask][pos];

	// If the bitmask is all 1s, we need to return home    
	//if (bitmask == (1 << n) - 1)
	//	return latency[pos][0];

	// Keep track of the minimum distance we have seen when visiting other cities
	int minDistance = 2000000000;

	// For each city we haven't visited, we are going to try the subproblem that arises from visiting it
	for (int k = 0; k < n; k++)
	{
		int res = bitmask & (1 << k);

		// If we haven't visited the city before, try and visit it
		if (res == 0)
		{
			int newBitmask = bitmask | (1 << k);

			// Get the distance from solving the subproblems
			int newDist = latency[pos][k] + solve(n, newBitmask, k, dp, data);

			// If newDist is smaller than the current minimum distance, we will override it here
			minDistance = min(minDistance, newDist);
		}
	}

	// Set the optimal value of the current subproblem
	return dp[bitmask][pos] = minDistance;
}

Brute Dynamic1(int n, vector <WiTicontainer> data)
{
	Brute outcome;
	int** dp = 0;
	int** latency = 0;
	dp = new int* [2^n-1];
	latency = new int* [n];

	for (int i = 0; i < (2 ^ n - 1); i++)
	{
		dp[i] = new int[n];
	}


	for (int z = 0; z < (2^n-1); z++)
		for (int g = 0; g < n; g++)
		{
			if(g==0)
				dp[z][g] = 0;
			else
			dp[z][g] = -1;
		}
	for (int j = 0; j < (n); j++)
		latency[j] = new int[n];



		outcome.result = solve(n, 0, 0, dp, latency);



	delete[] dp,latency;
	return outcome;
}
*/