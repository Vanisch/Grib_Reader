#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream grib;
	grib.open("all.grib", ios::in | ios::binary);

	if (!grib.is_open())
	{
		cout << "Nie udalo sie otworzyc pliku!\n";
		return -1;
	}

	return 0;
}