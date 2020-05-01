#pragma once
#include "utility.h"
using namespace std;

struct Brute
{
    vector<WiTicontainer> opt;
    int result;
   // int dp[6000][15];
/*
    Brute() { opt; result = 10000000; memset(dp, -1, sizeof dp);/* set all subsets to -1 }
    Brute(int n) { opt.resize(n); result = 10000000; memset(dp, -1, sizeof dp); }
    */
    Brute() { opt; result = 10000000; }; //memset(dp, -1, sizeof dp); set all subsets to -1 }
    Brute(int n) { opt.resize(n); result = 10000000; }; //memset(dp, -1, sizeof dp); }
    
  //  int Calc(int n, vector <WiTicontainer> data, int mask, int operations, int *dp);
    int Calc(int n, vector <WiTicontainer> data, int mask, int operations, int *dp);
    void permutations(vector <WiTicontainer> data, int indeks);

   // ~Brute(){delete[] dp;}
};

int CountCryterium(int n, vector <WiTicontainer> data);

Brute SortD(int n, vector <WiTicontainer> data);

Brute BruteForce(int n, vector <WiTicontainer> data);


Brute BruteForce_recursive(int n, vector<WiTicontainer> data);

Brute Dynamic(int n, vector <WiTicontainer> data);