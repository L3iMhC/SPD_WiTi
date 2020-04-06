#include "Algortimhs.h"
#include "utility.h"

int main()
{
	int cryterium;
	vector <WiTicontainer> data, oblicz;
	Brute Brute1;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data11.txt");

	showVector(data);

	cryterium = CountCryterium(n, data);
	
	cout << "Wartosc F dla naturalnego=  " << cryterium << endl;

	oblicz = SortD(n, data);
	cryterium = CountCryterium(n, oblicz);

	cout << "Wartosc F dla sortD=  " << cryterium << endl;

	Brute1 = BruteForce(n, data);

	cout << "Wartosc F dla BruteForce= " << Brute1.result << endl;

	return 0;
}