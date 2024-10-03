#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int sec1,sec2,sec3;
struct GribMessage {
    int start_pos;
    int end_pos;
    int length;
    int section1_length;
    int section2_length;
    int section3_length;
};

GribMessage parse_grib1_message(ifstream& file) {
    GribMessage message;
    file.seekg(0, ios::beg);
    
    message.start_pos = 40;
    file.seekg(0, ios::end);
    message.end_pos = file.tellg();
    message.length = message.end_pos - message.start_pos;
    
    message.section1_length = sec1;
    message.section2_length = sec2;
    message.section3_length = sec3;
    
    return message;
}

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

    cout << "Enter the lenght of section 1";
    cin >> sec1;
    cout << "Enter the lenght of section 2";
    cin >> sec2;
    cout << "Enter the lenght of section 3";
    cin >> sec3;
    GribMessage message = parse_grib1_message(file);

    file.close();
    output.close();
    
    cout << "GRIB info saved to Output.txt\n";
	return 0;
}