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