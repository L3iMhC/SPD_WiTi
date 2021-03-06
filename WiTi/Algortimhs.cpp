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

Brute SortD(int n, vector <WiTicontainer> data)
{
	Brute kopia(n);
	kopia.opt = data;

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (kopia.opt[i].d > kopia.opt[j].d)
			{
				swap(kopia.opt[i], kopia.opt[j]);
			}
		}
	}
	kopia.result = CountCryterium(n, kopia.opt);
	return kopia;
}

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

Brute BruteForce_recursive(int n, vector<WiTicontainer> data)
{
	Brute result(n);
	vector<WiTicontainer> kopia = data;

	result.permutations(kopia, 0);

	return result;
}

/*
void Brute::permutations(vector<WiTicontainer> data, int indeks)
{
	if (indeks == (data.size() - 1))
	{
		int x = CountCryterium(data.size(), data);
		if (result > x)
		{
			result = x;
			opt = data;
		}
		else
			for (int i = indeks; i < (data.size()); i++)
			{
				swap(data[indeks], data[i]);
				permutations(data, indeks + 1);
				swap(data[indeks], data[i]);
			}
	}
}*/

void Brute::permutations(vector<WiTicontainer> data, int indeks)
{
	if (indeks < (data.size() - 1))
		for (int i = indeks; i < (data.size()); i++)
		{
			swap(data[indeks], data[i]);
			permutations(data, indeks + 1);
			swap(data[indeks], data[i]);
		}
	else if (indeks == (data.size() - 1))
	{
		int x = CountCryterium(data.size(), data);
		if (result > x)
		{
			result = x;
			opt = data;
		}
	}
}

Brute Dynamic(int n, vector <WiTicontainer> data)
{
	Brute result(n);
	
	int z = n + 1;
	int o = pow(2,n);

	int *dp = new int[o*z];
	for (int y = 0; y < o*z; y++)
			dp[y] = -1;
			
	//int outcome;
	ALLMASK = (1 << n) - 1;//All bits are set to 1, for reference

	//memset(dp, -1, sizeof dp);// set all subsets to -1


	result.result = result.Calc(n, data, ALLMASK, 0, dp);

	return result;
}

/*int Brute::Calc(int n, vector <WiTicontainer> data, int mask, int operation)
{
	int F = 1000000;//latency
	int newlatency;
	int newmask, sum, result=0;

	if (mask == ALLMASK)
		return dp[mask][operation];
	if (dp[mask][operation] != -1) return dp[mask][operation];

	for (int j = 0; j < n; j++)
	{
		sum = 0;
		newmask = mask;
		if (!(newmask & (1 << data[j].indeks)))//if it is not in mask
		{
			for (int g = 0; g < n; g++)
			{
				if ((newmask & (1 << data[g].indeks)))//rest of elements in mask
					sum += data[g].p;
			}
			newlatency = max(-1 * data[j].d + sum + data[j].p, 0) * data[j].w + Calc(n, data, newmask |= (1 << data[j].indeks), operation + 1);
			//F = min(F, newlatency);
			if (newlatency < F)
			{
				F = newlatency;
				mask = newmask;
			}
		}

	}

	return dp[mask][operation] = F;
}*/
/*
int Brute::Calc(int n, vector <WiTicontainer> data, int mask, int operation)
{
	int F = 1000000;//latency
	int newlatency;
	int newmask, sum; //result = 0;
	int o = 2 ^ n;

	if (mask == 0)
		return 0;//dp[mask][operation];
	if (dp[mask][operation] != -1)
		return dp[mask][operation];

	for (int j = 0; j < n; j++)
	{
		sum = 0;
		newmask = mask;
		if ((newmask & (1 << data[j].indeks)))//if is in mask
		{
			for (int g = 0; g < n; g++)
			{
				if ((newmask & (1 << data[g].indeks)))// elements in mask
					sum += data[g].p;
			}
			newmask ^= (1 << data[j].indeks);
			newlatency = max(-1 * data[j].d + sum, 0) * data[j].w + Calc(n, data, newmask, operation + 1);
			//F = min(F, newlatency);
			if (newlatency < F)
			{
				F = newlatency;

			}
		}

	}

	return dp[mask][operation] = F;
}
*/
int Brute::Calc(int n, vector <WiTicontainer> data, int mask, int operation, int *dp)
{
	int F = 1000000;//latency
	int newlatency;
	int newmask, sum; //result = 0;
	int o = n+1;

	if (mask == 0)
		return 0;//dp[mask][operation];
	if (dp[mask*o+operation] != -1)
		return dp[mask * o + operation];

	for (int j = 0; j < n; j++)
	{
		sum = 0;
		newmask = mask;
		if ((newmask & (1 << data[j].indeks)))//if is in mask
		{
			for (int g = 0; g < n; g++)
			{
				if ((newmask & (1 << data[g].indeks)))// elements in mask
					sum += data[g].p;
			}
			newmask ^= (1 << data[j].indeks);
			newlatency = max(-1 * data[j].d + sum, 0) * data[j].w + Calc(n, data, newmask , operation + 1, dp);
			//F = min(F, newlatency);
			if (newlatency < F)
			{
				F = newlatency;

			}
		}

	}

	return dp[mask * o + operation] = F;
}