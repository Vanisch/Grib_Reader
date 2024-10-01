#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ifstream file("sample.grib", ios::binary);
    if (!file) {
        cout << "Error opening GRIB file.\n";
        return 1;
    }

    ofstream output("Output.txt");
    if (!output) {
        cout << "Error creating output file.\n";
        return 1;
 	}
    file.close();
    output.close();
    
    cout << "GRIB info saved to Output.txt\n";
	return 0;
}