#include "Algortimhs.h"
#include "utility.h"

int main()
{
	int cryterium;
	vector <WiTicontainer> data, oblicz;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data14.txt");

	showVector(data);

	cryterium = CountCryterium(n, data);
	
	cout << "Wartosc F dla naturalnego=  " << cryterium << endl;

	oblicz = SortD(n, data);
	cryterium = CountCryterium(n, oblicz);

	cout << "Wartosc F dla sortD=  " << cryterium << endl;


	return 0;
}