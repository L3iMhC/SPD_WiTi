#include "utility.h"


tuple<int, int, vector <WiTicontainer> > getDataFromFile(const string fileName) {
	ifstream file;
	vector <WiTicontainer> data;
	file.open(fileName);
	int n, parameters;
	file >> n;
	file >> parameters;
	WiTicontainer tmp;
	for (int i = 0; i < n; i++) {
		file >> tmp.p;
		file >> tmp.w;
		file >> tmp.d;
		tmp.indeks = i;

		data.push_back(tmp);
	}

	file.close();
	return make_tuple(n, parameters, data);
}

void showVector(vector <WiTicontainer> data) {
	for (int i = 0; i < data.size(); i++) {
		cout << "Wartosc p=  " << data[i].p << " w= " << data[i].w << " d= " << data[i].d << "  " << endl;
	}
	//cout << endl;
}