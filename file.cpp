#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <ctime>

using namespace std;

void clearScreen() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen()
{
    cout << "\n  Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string getCurrentDate()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    ostringstream oss;
    oss << 1900 + ltm->tm_year << "-"
        << setw(2) << setfill('0') << 1 + ltm->tm_mon << "-"
        << setw(2) << setfill('0') << l  tm->tm_mday;
    return oss.str();
}

void printLine(char c = '-', int width = 60) {
    cout << "  " << string(width, c) << "\n";
}
