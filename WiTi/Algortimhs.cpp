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