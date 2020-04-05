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

struct rpqcontainer {
    int p;
    int w;
    int d;


    rpqcontainer& operator = (const rpqcontainer& rpqcopy) {
        p = rpqcopy.p;
        w = rpqcopy.w;
        d = rpqcopy.d;
        return *this;
    }

    rpqcontainer(int x, int y, int z) { p = x; w = y; d = z; }
    rpqcontainer() { p = 0; w = 0; d = 0; }
};

struct CompareD {
    bool operator()(rpqcontainer const& d1, rpqcontainer const& d2)
    {
        return d1.d < d2.d;
    }
};

tuple<int, int, vector <rpqcontainer>> getDataFromFile(const string fileName);