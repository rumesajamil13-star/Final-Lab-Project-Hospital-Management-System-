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
void printLine(char c = '-', int width = 60)
{
    cout << "  " << string(width, c) << "\n";
}
void printHeader(const string& title) {
    clearScreen();
    cout << "\n";
    printLine('=');
    cout << "  " << setw(60) << left << ("  HOSPITAL MANAGEMENT SYSTEM") << "\n";
    printLine('=');
    cout << "  >> " << title << "\n";
    printLine();
    cout << "\n";
}
class Person
{
protected:
    string id;
    string name;
    int   age;
    string gender;
    string phone;
public:
    Person(const string& id, const string& name, int age,
        const string& gender, const string& phone)
        : id(id), name(name), age(age), gender(gender), phone(phone)
    {
    }
    virtual ~Person() 
    {
    }
    string getId() const
    {
        return id; 
    }
    string getName() const 
    {
        return name;
    }
    int    getAge() const 
    {
        return age; 
    }
    string getGender() const 
    {
        return gender;
    }
    string getPhone() const
    {
        return phone;
    }
    void setName(const string& n)
    {
        name = n; 
    }
    void setAge(int a) 
    {
        age = a;
    }
    void setGender(const string& g) 
    {
        gender = g;
    }
    void setPhone(const string& p)
    {
        phone = p; 
    }
    virtual void displayInfo()  const = 0;
    virtual void saveToFile(ofstream& ofs) const = 0;
    virtual string getType()    const = 0;
};
