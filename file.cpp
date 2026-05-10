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
class Appointment 
{
private:
    string appointmentId;
    string patientId;
    string doctorId;
    string date;
    string timeSlot;
    string reason;
    string status;

public:
    Appointment() : status("Scheduled")
    {
    
    }

    Appointment(const string& aId, const string& pId, const string& dId,
                const string& date, const string& time,
                const string& reason, const string& status = "Scheduled")
        : appointmentId(aId), patientId(pId), doctorId(dId),
          date(date), timeSlot(time), reason(reason), status(status)
    {
    
    }

    ~Appointment()
    {
    
    }

    string getAppointmentId() 
const { return appointmentId; }
    string getPatientId()    
const { return patientId; }
    string getDoctorId()   
const { return doctorId; }
    string getDate()        
const { return date; }
    string getTimeSlot()     
const { return timeSlot; }
    string getReason()       
const { return reason; }
    string getStatus()        
const { return status; }

    void setStatus(const string& s) { status = s; }
    void setDate(const string& d)   { date = d; }
    void setTimeSlot(const string& t){ timeSlot = t; }

    void display(const string& patientName = "", const string& doctorName = "") const 
    {
        cout << "  Appointment ID : " << appointmentId << "\n";
        if (!patientName.empty()) cout << "  Patient        : " << patientName << " (" << patientId << ")\n";
        if (!doctorName.empty())  cout << "  Doctor         : " << doctorName  << " (" << doctorId  << ")\n";
        cout << "  Date           : " << date << "\n";
        cout << "  Time Slot      : " << timeSlot << "\n";
        cout << "  Reason         : " << reason << "\n";
        cout << "  Status         : " << status << "\n";
    }

    void saveToFile(ofstream& ofs) const
    {
        ofs << appointmentId << "|" << patientId << "|" << doctorId << "|"
            << date << "|" << timeSlot << "|" << reason << "|" << status << "\n";
    }

    static Appointment loadFromLine(const string& line) 
    {
        istringstream ss(line);
        string aId, pId, dId, date, time, reason, status;
        getline(ss, aId,    '|');
        getline(ss, pId,    '|');
        getline(ss, dId,    '|');
        getline(ss, date,   '|');
        getline(ss, time,   '|');
        getline(ss, reason, '|');
        getline(ss, status, '|');
        return Appointment(aId, pId, dId, date, time, reason, status);
    }
};
