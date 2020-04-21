#include "Algortimhs.h"
#include "utility.h"


auto timeMeasure2(int n, vector <WiTicontainer> data, Brute(*function)(int, vector <WiTicontainer>))
{
	auto start = std::chrono::high_resolution_clock::now();
	function(n, data);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//cout << "Czas wykonywania sie algorytmu:" << duration.count() << endl;
	return duration;
}

int main()
{
	int cryterium;
	vector <WiTicontainer> data;
	Brute Brute1;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data20.txt");

	showVector(data);
	cryterium = CountCryterium(n, data);

	//Brute1 = SortD(n, data);
	for (int i = 0; i < 10; i++) {
		auto timeSortD = timeMeasure2(n, data, SortD);
		cout << "TIME SortD: " << timeSortD.count() << endl;

		//cout << "Wartosc F dla naturalnego=  " << cryterium << endl;

		//cout << "Wartosc F dla sortD=  " << cryterium << endl;


		//Brute1 = BruteForce(n, data);
		//auto timeBrute1 = timeMeasure2(n, data, BruteForce);
		//cout << "TIME BruteForce1: " << timeBrute1.count() << endl;

		//cout << "Wartosc F dla BruteForce= " << Brute1.result << endl;


		//Brute1 = BruteForce_recursive(n, data);
		//auto timeBrute2 = timeMeasure2(n, data, BruteForce_recursive);
		//cout << "TIME BruteForce2: " << timeBrute2.count() << endl;

		//cout << "Wartosc F dla BruteForceRecursive= " << Brute1.result << endl;


		//Brute1 = Dynamic(n, data);

		//auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		//cout << "TIME Dynamic: " << timeDynamic1.count() << endl;
	}
	//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;


	return 0;
}