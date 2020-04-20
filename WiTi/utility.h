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
#include <bitset>
#include <new>

using namespace std;

static int ALLMASK;


struct WiTicontainer {
    int p;
    int w;
    int d;

    int indeks;


    WiTicontainer& operator = (const WiTicontainer& witicopy) {
        p = witicopy.p;
        w = witicopy.w;
        d = witicopy.d;
        indeks = witicopy.indeks;
        return *this;
    }

    WiTicontainer(int x, int y, int z, int h) { p = x; w = y; d = z; indeks = h; }
    WiTicontainer() { p = 0; w = 0; d = 0; indeks = 0; }

  //  bool operator<(const WiTicontainer& rhs) const {
  //      return (this->indeks) < (rhs.indeks);
  //  }
};




struct CompareD {
    bool operator()(WiTicontainer const& d1, WiTicontainer const& d2)
    {
        return d1.d < d2.d;
    }
};

tuple<int, int, vector <WiTicontainer>> getDataFromFile(const string fileName);

void showVector(vector <WiTicontainer> data);