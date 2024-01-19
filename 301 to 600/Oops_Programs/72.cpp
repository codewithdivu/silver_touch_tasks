#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Doctor {
public:
    string name;

    Doctor(const string& n) : name(n) {}

    void prescribeMedication(const string& patientName, const string& medication) const {
        cout << "Prescribing " << medication << " to patient " << patientName << endl;
    }
};

class Patient {
public:
    string name;

    Patient(const string& n) : name(n) {}
};

class Appointment {
public:
    Doctor* doctor;
    Patient* patient;

    Appointment(Doctor* d, Patient* p) : doctor(d), patient(p) {
        cout << "Appointment scheduled with Dr. " << doctor->name << " for patient " << patient->name << endl;
    }

    void attendAppointment(const string& medication) {
        doctor->prescribeMedication(patient->name, medication);
        cout << patient->name << " attended the appointment." << endl;
    }
};

class Hospital {
private:
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;

public:
    void addDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }

    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    void scheduleAppointment(Doctor* doctor, Patient* patient) {
        appointments.emplace_back(doctor, patient);
    }

    vector<Appointment>& getAppointments() {
        return appointments;
    }
};

int main() {
    Hospital hospital;

    Doctor doctor1("Dr. Smith");
    Doctor doctor2("Dr. Johnson");

    Patient patient1("Alice");
    Patient patient2("Bob");

    hospital.addDoctor(doctor1);
    hospital.addDoctor(doctor2);

    hospital.addPatient(patient1);
    hospital.addPatient(patient2);

    hospital.scheduleAppointment(&doctor1, &patient1);
    hospital.scheduleAppointment(&doctor2, &patient2);

    // Simulate attending appointments
    for (auto& appointment : hospital.getAppointments()) {
        appointment.attendAppointment("Painkiller");
        appointment.attendAppointment("Antibiotics");
    }

    return 0;
}