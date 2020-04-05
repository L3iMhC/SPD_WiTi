#include "Algortimhs.h"
#include "utility.h"

int main()
{

	vector <WiTicontainer> data;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data10.txt");

	showVector(data);

	return 0;
}