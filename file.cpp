#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Person
{
protected:
    int id;
    string name;
    int age;
    string gender;

public:
    Person() 
    {
    }

    Person(int i, string n, int a, string g)
    {
        id = i;
        name = n;
        age = a;
        gender = g;
    }

    virtual void displayInfo() = 0;

    int getID() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    string getGender() const
    {
        return gender;
    }
};

class Patient : public Person 
{
private:
    string disease;
    string bloodGroup;

public:
    Patient()
    {
    }

    Patient(int i, string n, int a, string g, string d, string bg): Person(i, n, a, g) 
    {

        disease = d;
        bloodGroup = bg;
    }

    void displayInfo() override
    {

        cout << "\n***********************************";
        cout << "\nPATIENT INFORMATION";
        cout << "\n***********************************";
        cout << "\nID          : " << id;
        cout << "\nName        : " << name;
        cout << "\nAge         : " << age;
        cout << "\nGender      : " << gender;
        cout << "\nDisease     : " << disease;
        cout << "\nBlood Group : " << bloodGroup;
        cout << "\n***********************************\n";
    }

    string getDisease() const
    {
        return disease;
    }

    string getBloodGroup() const
    {
        return bloodGroup;
    }
};
class Doctor : public Person 
{
private:
    string specialization;
    int experience;

public:
    Doctor() 
    {
    }

    Doctor(int i, string n, int a, string g,string s, int e): Person(i, n, a, g)
    {

        specialization = s;
        experience = e;
    }

    void displayInfo() override
    {

        cout << "\n***********************************";
        cout << "\nDOCTOR INFORMATION";
        cout << "\n***********************************";
        cout << "\nID             : " << id;
        cout << "\nName           : " << name;
        cout << "\nAge            : " << age;
        cout << "\nGender         : " << gender;
        cout << "\nSpecialization : " << specialization;
        cout << "\nExperience     : " << experience << " Years";
        cout << "\n***********************************\n";
    }

    string getSpecialization() const 
    {
        return specialization;
    }

    int getExperience() const
    {
        return experience;
    }
};
class Appointment
{
private:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;

public:
    Appointment() 
    {
    }

    Appointment(int aid, int pid, int did,
        string d, string t) 
    {

        appointmentID = aid;
        patientID = pid;
        doctorID = did;
        date = d;
        time = t;
    }

    int getAppointmentID() const
    {
        return appointmentID;
    }

    int getPatientID() const
    {
        return patientID;
    }

    int getDoctorID() const
    {
        return doctorID;
    }

    string getDate() const
    {
        return date;
    }

    string getTime() const
    {
        return time;
    }

    void displayAppointment()
    {

        cout << "\n===================================";
        cout << "\nAPPOINTMENT DETAILS";
        cout << "\n===================================";
        cout << "\nAppointment ID : " << appointmentID;
        cout << "\nPatient ID     : " << patientID;
        cout << "\nDoctor ID      : " << doctorID;
        cout << "\nDate           : " << date;
        cout << "\nTime           : " << time;
        cout << "\n===================================\n";
    }
};

class Hospital 
{
private:

    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

public:

    void addPatient()
    {

        int id, age;
        string name, gender, disease, bloodGroup;

        cout << "\nEnter Patient ID: ";
        cin >> id;

        for (auto& p : patients)
        {
            if (p.getID() == id)
            {
                cout << "\nPatient ID already exists!\n";
                return;
            }
        }

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Gender: ";
        getline(cin, gender);

        cout << "Enter Disease: ";
        getline(cin, disease);

        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);

        Patient p(id, name, age, gender,
            disease, bloodGroup);

        patients.push_back(p);

        cout << "\nPatient Added Successfully!\n";
    }

    void viewPatients()
    {

        if (patients.empty())
        {
            cout << "\nNo Patients Found!\n";
            return;
        }

        for (auto& p : patients)
        {
            p.displayInfo();
        }
    }

    void searchPatient() 
    {

        int id;
        bool found = false;

        cout << "\nEnter Patient ID to Search: ";
        cin >> id;

        for (auto& p : patients) 
        {

            if (p.getID() == id)
            {
                p.displayInfo();
                found = true;
            }
        }

        if (!found) 
        {
            cout << "\nPatient Not Found!\n";
        }
    }

    void deletePatient()
    {

        int id;
        bool found = false;

        cout << "\nEnter Patient ID to Delete: ";
        cin >> id;

        for (auto it = patients.begin();
            it != patients.end(); it++)
        {

            if (it->getID() == id)
            {

                patients.erase(it);

                cout << "\nPatient Deleted Successfully!\n";

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nPatient Not Found!\n";
        }
    }

    void addDoctor() 
    {

        int id, age, experience;
        string name, gender, specialization;

        cout << "\nEnter Doctor ID: ";
        cin >> id;

        for (auto& d : doctors) 
        {
            if (d.getID() == id) 
            {
                cout << "\nDoctor ID already exists!\n";
                return;
            }
        }

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Gender: ";
        getline(cin, gender);

        cout << "Enter Specialization: ";
        getline(cin, specialization);

        cout << "Enter Experience (Years): ";
        cin >> experience;

        Doctor d(id, name, age, gender, specialization, experience);

        doctors.push_back(d);

        cout << "\nDoctor Added Successfully!\n";
    }

    void viewDoctors()
    {

        if (doctors.empty())
        {
            cout << "\nNo Doctors Found!\n";
            return;
        }

        for (auto& d : doctors)
        {
            d.displayInfo();
        }
    }

    void searchDoctor()
    {

        int id;
        bool found = false;

        cout << "\nEnter Doctor ID to Search: ";
        cin >> id;

        for (auto& d : doctors) 
        {

            if (d.getID() == id)
            {
                d.displayInfo();
                found = true;
            }
        }

        if (!found)
        {
            cout << "\nDoctor Not Found!\n";
        }
    }


    void bookAppointment() 
    {

        int aid, pid, did;
        string date, time;

        bool patientFound = false;
        bool doctorFound = false;

        cout << "\nEnter Appointment ID: ";
        cin >> aid;

        cout << "Enter Patient ID: ";
        cin >> pid;

        for (auto& p : patients)
        {
            if (p.getID() == pid)
            {
                patientFound = true;
            }
        }

        if (!patientFound) 
        {
            cout << "\nPatient ID does not exist!\n";
            return;
        }

        cout << "Enter Doctor ID: ";
        cin >> did;

        for (auto& d : doctors) 
        {
            if (d.getID() == did)
            {
                doctorFound = true;
            }
        }

        if (!doctorFound)
        {
            cout << "\nDoctor ID does not exist!\n";
            return;
        }

        cin.ignore();

        cout << "Enter Appointment Date: ";
        getline(cin, date);

        cout << "Enter Appointment Time: ";
        getline(cin, time);

        Appointment a(aid, pid, did,date, time);

        appointments.push_back(a);

        cout << "\nAppointment Booked Successfully!\n";
    }

    void viewAppointments() 
    {

        if (appointments.empty()) 
        {
            cout << "\nNo Appointments Found!\n";
            return;
        }

        for (auto& a : appointments) 
        {
            a.displayAppointment();
        }
    }

    void savePatientsToFile()
    {

        ofstream file("patients.txt");

        for (auto& p : patients) 
        {

            file << p.getID() << ","
                << p.getName() << ","
                << p.getAge() << ","
                << p.getGender() << ","
                << p.getDisease() << ","
                << p.getBloodGroup() << endl;
        }

        file.close();

        cout << "\nPatient Data Saved Successfully!\n";
    }

    void saveDoctorsToFile() 
    {

        ofstream file("doctors.txt");

        for (auto& d : doctors) 
        {

            file << d.getID() << ","
                << d.getName() << ","
                << d.getAge() << ","
                << d.getGender() << ","
                << d.getSpecialization() << ","
                << d.getExperience() << endl;
        }

        file.close();

        cout << "\nDoctor Data Saved Successfully!\n";
    }

    void saveAppointmentsToFile() 
    {

        ofstream file("appointments.txt");

        for (auto& a : appointments) 
        {

            file << a.getAppointmentID() << ","
                << a.getPatientID() << ","
                << a.getDoctorID() << ","
                << a.getDate() << ","
                << a.getTime() << endl;
        }

        file.close();

        cout << "\nAppointment Data Saved Successfully!\n";
    }
};

int main() 
{

    Hospital h;

    int choice;

    do
    {

        cout << "\n\n***************************************";
        cout << "\n HOSPITAL MANAGEMENT SYSTEM";
        cout << "\n***********************************";
        cout << "\n1. Add Patient";
        cout << "\n2. View Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Delete Patient";

        cout << "\n\n5. Add Doctor";
        cout << "\n6. View Doctors";
        cout << "\n7. Search Doctor";

        cout << "\n\n8. Book Appointment";
        cout << "\n9. View Appointments";

        cout << "\n\n10. Save Patients File";
        cout << "\n11. Save Doctors File";
        cout << "\n12. Save Appointments File";

        cout << "\n\n0. Exit";

        cout << "\n***********************************";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) 
        {

        case 1:
            h.addPatient();
            break;

        case 2:
            h.viewPatients();
            break;

        case 3:
            h.searchPatient();
            break;

        case 4:
            h.deletePatient();
            break;

        case 5:
            h.addDoctor();
            break;

        case 6:
            h.viewDoctors();
            break;

        case 7:
            h.searchDoctor();
            break;

        case 8:
            h.bookAppointment();
            break;

        case 9:
            h.viewAppointments();
            break;

        case 10:
            h.savePatientsToFile();
            break;

        case 11:
            h.saveDoctorsToFile();
            break;

        case 12:
            h.saveAppointmentsToFile();
            break;

        case 0:
            cout << "\nExiting System...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    }
    while (choice != 0);

    return 0;
}
