#include <iostream>
using namespace std;

enum Day { Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
enum Weather { SUNNY, RAINY, CLOUDY, SNOWNY };

int main() {
    int d = 0;
    int w = 0;
    cout << "input the Day value: Monday(1), Tuesday(2), Wednesday(3), Thursday(4), Friday(5), Saturday(6), Sunday(7)\n";
    cin >> d;
    const char* dayNames[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cout << "This is " << dayNames[d] << endl;

    cout << "input the Weather value: SUNNY(0), RAINY(1), CLOUDY(2), SNOWNY(3)\n";
    cin >> w;
    const char* weatherNames[] = {"SUNNY", "RAINY", "CLOUDY", "SNOWNY"};
    cout << "The weather is: " << weatherNames[w] << endl;

    if ((d == 6 || d == 7) && w == SUNNY) {
        cout << "can Travel\n";
    } else {
        cout << "not suitable for travelling\n";
    }

    return 0;
}