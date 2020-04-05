#include "utility.h"


tuple<int, int, vector <rpqcontainer> > getDataFromFile(const string fileName) {
	ifstream file;
	vector <rpqcontainer> data;
	file.open(fileName);
	int n, parameters;
	file >> n;
	file >> parameters;
	rpqcontainer tmp;
	for (int i = 0; i < n; i++) {
		file >> tmp.p;
		file >> tmp.w;
		file >> tmp.d;

		data.push_back(tmp);
	}

	file.close();
	return make_tuple(n, parameters, data);
}