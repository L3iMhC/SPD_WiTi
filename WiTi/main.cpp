#include "Algortimhs.h"
#include "utility.h"

int main()
{
	int cryterium;
	vector <WiTicontainer> data;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data20.txt");

	showVector(data);

	cryterium = CountCryterium(n, data);
	
	cout << "Wartosc F=  " << cryterium << endl;
	return 0;
}