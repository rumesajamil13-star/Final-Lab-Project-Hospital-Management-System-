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

    Patient(int i, string n, int a, string g, string d, string bg) : Person(i, n, a, g) 
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
        cout << "\n===================================\n";
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

    Doctor(int i, string n, int a, string g,  string s, int e): Person(i, n, a, g) 
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
        cout << "\n===================================\n";
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

    Appointment(int aid, int pid, int did,  string d, string t)
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
        cout << "\n***********************************";
        cout << "\nAPPOINTMENT DETAILS";
        cout << "\n***********************************";
        cout << "\nAppointment ID : " << appointmentID;
        cout << "\nPatient ID     : " << patientID;
        cout << "\nDoctor ID      : " << doctorID;
        cout << "\nDate           : " << date;
        cout << "\nTime           : " << time;
        cout << "\n===================================\n";
    }
};
