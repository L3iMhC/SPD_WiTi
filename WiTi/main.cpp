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
	int n, i;
	int parameters;
	
	cout << endl << "data10" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data10.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data11" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data11.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data12" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data12.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data13" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data13.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data14" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data14.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data15" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data15.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data16" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data16.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data17" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data17.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data18" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data18.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data19" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data19.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	cout << endl << "data20" << endl;
	for (i = 0; i < 10; i++) {
		tie(n, parameters, data) = getDataFromFile("data20.txt");
		Brute1 = Dynamic(n, data);
		auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		cout << timeDynamic1.count() << endl;
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	}
	

	//showVector(data);
	//cryterium = CountCryterium(n, data);


	//int mask = 0;
	//int mask1 = 0;
	//int allmask = (1 << 10) - 1;
	//Brute1 = SortD(n, data);
	//for (int i = 0; i < 10; i++) {
	//	auto timeSortD = timeMeasure2(n, data, SortD);
		//cout << "TIME SortD: " << timeSortD.count() << endl;

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

		//tie(n, parameters, data) = getDataFromFile("data20.txt");
		//Brute1 = Dynamic(n, data);

		//auto timeDynamic1 = timeMeasure2(n, data, Dynamic);
		//cout << "TIME Dynamic: " << timeDynamic1.count() << endl;
	//}
		//cout << "Wartosc F dla dynamic= " << Brute1.result << endl;
	
	/*for (int i = 9; i >= 0; i--)
	{
;
		cout <<"Dla i = " << i<<" maska |= : " <<(mask |= (1 << i) )<<" maska | : "<<(mask1 | (1 << i))<< endl;

	}
	cout <<"allmask " <<allmask;
	*/
	return 0;
}