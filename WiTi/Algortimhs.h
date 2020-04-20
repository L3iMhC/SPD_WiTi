#pragma once
#include "utility.h"
using namespace std;

struct Brute
{
    vector<WiTicontainer> opt;
    int result;
    int dp[6000][20];

    Brute() { opt; result = 100000; memset(dp, -1, sizeof dp);/* set all subsets to -1*/ }
   // Brute(int n) { opt; result = 100000; dp = new int[(2^n-1) * n]; for (int i = 0; i<(2^n-1)*n; i++){ dp[i] = -1; } }

    int Calc(int n, vector <WiTicontainer> data, int mask, int operations);

   // ~Brute(){delete[] dp;}
};

int CountCryterium(int n, vector <WiTicontainer> data);

vector<WiTicontainer> SortD(int n, vector <WiTicontainer> data);

Brute BruteForce(int n, vector <WiTicontainer> data);

int Dynamic(int n, vector <WiTicontainer> data);

