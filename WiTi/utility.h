#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <string>
#include <tuple>
#include <queue>
#include <ctime> 

using namespace std;

struct WiTicontainer {
    int p;
    int w;
    int d;


    WiTicontainer& operator = (const WiTicontainer& rpqcopy) {
        p = rpqcopy.p;
        w = rpqcopy.w;
        d = rpqcopy.d;
        return *this;
    }

    WiTicontainer(int x, int y, int z) { p = x; w = y; d = z; }
    WiTicontainer() { p = 0; w = 0; d = 0; }
};

struct CompareD {
    bool operator()(WiTicontainer const& d1, WiTicontainer const& d2)
    {
        return d1.d < d2.d;
    }
};

tuple<int, int, vector <WiTicontainer>> getDataFromFile(const string fileName);
void showVector(vector <WiTicontainer> data);