#include "Algortimhs.h"
#include "utility.h"

int main()
{
	int cryterium;
	vector <WiTicontainer> data, oblicz;
	Brute Brute1;
	int n;
	int parameters;
	tie(n, parameters, data) = getDataFromFile("data10.txt");

	int x = 2 ^ n - 1;
	//int** dp = new int* [x];
	//for (int i = 0; i < (x); ++i)
	//	dp[i] = new int[n];
	//memset(dp, -1, sizeof dp);// set all subsets to -1
	//for (int g = 0; g < (2 ^ n - 1); ++g)
	//	for (int z = 0; z < n; ++z)
	//		dp[g][z] = -1;
	/*vector<vector<int> > dp(n, vector<int>(x));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < x; j++) {
			dp[i][j] = -1;
		}
	}
	*/
	showVector(data);

	cryterium = CountCryterium(n, data);
	
	cout << "Wartosc F dla naturalnego=  " << cryterium << endl;

	oblicz = SortD(n, data);
	cryterium = CountCryterium(n, oblicz);

	cout << "Wartosc F dla sortD=  " << cryterium << endl;

	//Brute1 = BruteForce(n, data);

	//cout << "Wartosc F dla BruteForce= " << Brute1.result << endl;

	Brute1.result = Dynamic(n, data);

	cout << "Wartosc F dla dynamic= " << Brute1.result << endl;

	//for (int j = 0; j < (2 ^ n - 1); ++j)
	//	delete[] dp[j];
	//delete[] dp;


	return 0;
}