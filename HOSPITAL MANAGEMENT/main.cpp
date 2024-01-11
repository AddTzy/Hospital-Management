#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class person;
class staff;
class doctor;
class patient;

int chooseMain();
void getDoctorDatabase();
void getPatientDatabase();
void getBedDatabase();
void addDoc();
void addPat();
void readDoctors();
void readPatients();
void writetoFile(doctor d);
void writetoFile(patient p);
void display(doctor d);
void display(patient p);
void showAll(int i);
void findDoc();
void findPat();
void searchDoctors();
vector<doctor> doctors;
vector<patient> patients;

int main()
{
     system("Color 7B");
     cout<<endl;
	cout<<right<<setw(60)<<setfill(' ')<<"WELCOME TO AB HOSPITAL MANAGEMENT SYSTEM "<<endl;
	cout<<endl<<endl;	

     cout << "------------------------------------------------" << endl;

     cout << "1.Main Menu" << endl;
     cout << "2.Exit" << endl;
     cout << "------------------------------------------------" << endl
          << endl;

     cout << "Enter your choice:" << endl
          <<endl;
     int choice1;
     cin >> choice1;

     if (choice1 == 1)
     {
          system("Color 3A");
          int var = chooseMain();
          switch (var)
          {
          case 1:
          {
               system("Color 2D");
               getDoctorDatabase();
               break;
          }
          case 2:
          {
               system("Color 8F");
               getPatientDatabase();
               break;
          }

          case 3:
          {
               main();
               return 0;
               break;
          }
          default:
               cout << "" << endl;
          }
     }
     else if (choice1 == 2)
     { 
          system("Color 4C");
          return 0;
     }
     else
          main();
          cout << "\nCome on!Enter a valid option." << endl;
     return 0;
}


class person
{
public:
     string fname, lname, gender, occupation, city, phnumber;
     int age;
};

class staff : public person
{
public:
     string category, qualification;
     int ID, experience, totalno;
};

class doctor : public staff
{
public:

     string spec;
     friend void display(doctor d);
     doctor(){

     }
     doctor(vector<string> content){
          this -> ID = stoi(content[0]);
          this -> fname = content[1];
          this -> lname = content[2];
          this -> gender = content[3];
          this -> age = stoi(content[4]);
          this -> city = content[5];
          this -> qualification = content[6];
          this -> spec = content[7];
          this -> experience = stoi(content[8]);
     }
     void setSpec()
     {
          cout << "1.MEDICINE" << endl;
          cout << "2.NEUROLOGY" << endl;
          cout << "3.ONCOLOGY" << endl;
          cout << "4.HAEMATOLOGY" << endl;
          cout << "5.GASTROENTEROLOGY" << endl;
          cout << "6.GYNAECOLOGY" << endl;
          int s;
          cin >> s;
          switch (s)
          {

          case 1:
          {
               this->spec = "MEDICINE";
               break;
          }
          case 2:
          {
               this->spec = "NEUROLOGY";
               break;
          }
          case 3:
          {
               this->spec = "ONCOLOGY";
               break;
          }
          case 4:
          {
               this->spec = "HAEMATOLOGY";
               break;
          }
          case 5:
          {
               this->spec = "GASTROENTEROLOGY";
               break;
          }
          case 6:
          {
               this->spec = "GYNAECOLOGY ";
               break;
          }
          default:
          {
               cout << "\nCome on!Enter a valid option." << endl;
          }
          }
     }
     
};


class patient : public person
{
public:
     string dep, addDate, relDate;
     int p_ID;
     double bill;
     friend void display(patient p);
     patient() {
          
     }
     patient(vector<string> content){
          this -> p_ID = stoi(content[0]);
          this -> fname = content[1];
          this -> lname = content[2];
          this -> age = stoi(content[3]);
          this -> phnumber = content[4];
          this -> occupation = content[5];
          this -> city = content[6];
          this -> dep = content[7];
          this -> addDate = content[8];
          this -> relDate = content[9];
          this -> bill = stod(content[10]);
     }

     void setDept()
     {
          cout << "1.MEDICINE" << endl;
          cout << "2.NEUROLOGY" << endl;
          cout << "3.ONCOLOGY" << endl;
          cout << "4.HAEMATOLOGY" << endl;
          cout << "5.GASTROENTEROLOGY" << endl;
          cout << "6.GYNAECOLOGY " << endl
               << endl;
          int s;
          cin >> s;
          switch (s)
          {

          case 1:
          {
               this->dep = "MEDICINE";
               break;
          }
          case 2:
          {
               this->dep = "NEUROLOGY";
               break;
          }
          case 3:
          {
               this->dep = "ONCOLOGY";
               break;
          }
          case 4:
          {
               this->dep = "HAEMATOLOGY";
               break;
          }
          case 5:
          {
               this->dep = "GASTROENTEROLOGY";
               break;
          }
          case 6:
          {
               this->dep = "GYNAECOLOGY ";
               break;
          }
          default:
          {
               cout << "\nCome on!Enter a valid option." << endl; 
          }
          }
     }
     
};




int chooseMain()
{

     int choice2;
     cout << "\nMAIN MENU" << endl
          << endl
          << endl;
     cout << setw(60)<<setfill(' ')<<"-----------------------------------" << endl;
     cout << "			"
          << "1.Enter Into Doctors' Database" << endl;
     cout << "			"
          << "2.Enter Into Patients' Database" << endl;
     cout << "			"
          << "3.Exit to Main Menu." << endl
          << endl;
     cout << setw(60)<<setfill(' ')<<"-----------------------------------" << endl;

     cout << "\nEnter the number corresponding to your choice:" << endl;
     cin >> choice2;
     return choice2;
}

void getDoctorDatabase()
{
     int choice_doc;
     cout << "\n                         "
          << "WELCOME TO DOCTOR'S DATABASE" << endl
          << endl;
     cout << "			"
          << "1.Add New Doctor's Information" << endl;
     cout << "			"
          << "2.Display a Doctor's Information" << endl;
     cout << "			"
          << "3.Display Entire Doctor Database" << endl;
     cout << "			"
          << "4.Exit to main menu" << endl;
     cout << setw(60)<<setfill(' ')<<"---------------------------------------------" << endl;

     cout << "\nEnter the number corresponding to your choice:" << endl
          << endl;
     cin >> choice_doc;
     switch (choice_doc)
     {
          
     case 1:
     {
          system("Color 6C");
          addDoc();
          break;
     }
     case 2:
     {
          system("Color 6C");
          findDoc();
          cout << "\n\n\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit to Main Menu." << endl;
          int c;
          cin >> c;
          if (c == 1)
          {
               getDoctorDatabase();
          }

          else
               main();
               exit(0);
          break;
     }
     case 3:
     {
          system("Color 6C");
          showAll(0);
          cout << "\n\n\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit to Main Menu." << endl;
          int c;
          cin >> c;
          if (c == 1)
          {
               getDoctorDatabase();
          }

          else
          main();
          exit(0);
          break;
     }
     case 4:
     {
          main();
          exit(0);
          break;
     }
     }
}

void getPatientDatabase()
{
     int choice_pat;
     cout << "\n                         "
          << "WELCOME TO PATIENT'S DATABASE" << endl
          << endl;
     cout << "			"
          << "1.Add New Patient's Information" << endl;
     cout << "			"
          << "2.Display a Patient's Information" << endl;
     cout << "			"
          << "3.Display Entire Patient Database" << endl;
     cout << "			"
          << "4.Check for doctor availability" << endl;
     cout << "			"
          << "5.Exit to Main Menu." << endl;
     cout << setw(60)<<setfill(' ')<<"---------------------------------------------"<< endl;

     cout << "\nEnter the number corresponding to your choice:" << endl
          << endl;
     cin >> choice_pat;
     switch (choice_pat)
     {
     case 1:
     {
          system("Color 5C");
          addPat();
          break;
     }
     case 2:
     {
          system("Color 5C");
          findPat();
          cout << "\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit to Main Menu." << endl;
          int c;
          cin >> c;
          if (c == 1)
          {
               getPatientDatabase(); // backtoPatientMenu
          }

          else
               main();
               exit(0);
          break;
     }
     case 3:
     {
          system("Color 5C");
          showAll(1);
          cout << "\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit to Main Menu.." << endl;
          int c;
          cin >> c;
          if (c == 1)
          {
               getPatientDatabase(); // backtoPatientMenu
          }

          else
               main();
               exit(0);
          break;
     }
     case 4:
     {
          system("Color 5C");
          searchDoctors();
          cout << "\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit to Main Menu." << endl;
          int c;
          cin >> c;
          if (c == 1)
          {
               getPatientDatabase(); // backtoPatientMenu
          }

          else
          main();
               exit(0);
          break;
     }
     case 5:
     {
          main();
          exit(0);
          break;
     }
     }
}


void addDoc()
{
     doctor d;
     cout << "Fill up the following details" << endl;
     cout << "ID:" << endl;
     cin >> d.ID;
     cout << "First Name:" << endl;
     cin >> d.fname;
     cout << "Last Name:" << endl;
     cin >> d.lname;
     cout << "Gender:" << endl;
     cin >> d.gender;
     cout << "Age:" << endl;
     cin >> d.age;
     cout << "City:" << endl;
     cin >> d.city;
     cout << "Choose Qualification among the following:\n1.MBBS\n2.MD" << endl;
     int q;
     cin >> q;
     if (q == 1)
          d.qualification = "MBBS";
     else
          d.qualification = "MD";
     cout << "Choose Specialization among the following:" << endl;
     d.setSpec();
     cout << "Experience (in Years):" << endl;
     cin >> d.experience;
     writetoFile(d);
     cout << "\n\n\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit to Main Menu." << endl;
     int c;
     cin >> c;
     if (c == 1)
     {
          getDoctorDatabase();
     }

     else
          main();
          exit(0);
}

void findDoc()
{
     readDoctors();
     int id;
     cout << "Enter the ID"<<endl;
     cin >> id;
     for (int i = 0; i < doctors.size(); i++)
     {
          if (doctors[i].ID == id)
          {
               cout << setw(4)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Sex "<<"Age"<<setw(13)<<"City  "<<setw(9)<<"Qual\t"<<setw(10)<<"Speciality "<<"Experience\n";
               display(doctors[i]);
               return;
          }
     }
     cout << "No Doctor found";
}

void findPat()
{
     readPatients();
     int id;
     cout << "Enter the ID"<<endl;
     cin >> id;
     for (int i = 0; i < patients.size(); i++)
     {
          if (patients[i].p_ID == id)
          {
               cout << setw(4)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Age"<<setw(12)<<"Ph. No  "<<setw(5)<<"Occupation"<<setw(12)<<"City"<<setw(15)<<"Department"<<setw(14)<<"Admin-date"<<setw(14)<<"Release-date"<<setw(10)<<"Bill\n";
               display(patients[i]);
               return;
          }
     }
     cout << "No Patient found";
}


void display(doctor d)
{
     cout << setw(4)<< d.ID 
          << setw(10)<< d.fname 
          << setw(10)<< d.lname 
          << setw(4)<< d.gender 
          << setw(4)<< d.age 
          << setw(14)<< d.city 
          << setw(6)<< d.qualification 
          << setw(14)<< d.spec 
          << setw(4)<< d.experience << endl;
}

void showAll(int i)
{
     if (i == 0)
     {
          readDoctors();
          cout << setw(4)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Sex "<<"Age"<<setw(13)<<"City  "<<setw(9)<<"Qual\t"<<setw(10)<<"Speciality "<<"Experience\n";
          for (int i = 0; i < doctors.size(); i++)
          {
               display(doctors[i]);
          }
     }
     else if (i == 1)
     {
          readPatients();
          cout << setw(4)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Age"<<setw(12)<<"Ph. No  "<<setw(5)<<"Occupation"<<setw(12)<<"City"<<setw(15)<<"Department"<<setw(14)<<"Admin-date"<<setw(14)<<"Release-date"<<setw(10)<<"Bill\n";
          for (int i = 0; i < patients.size(); i++)
          {
               display(patients[i]);
          }
     }
}

void display(patient p)
{
     cout << setw(4)<< p.p_ID 
          << setw(10)<< p.fname 
          << setw(10)<< p.lname 
          << setw(4)<< p.age 
          << setw(11)<< p.phnumber 
          << setw(10)<< p.occupation 
          << setw(14)<< p.city 
          << setw(14)<< p.dep 
          << setw(14)<< p.addDate 
          << setw(14)<< p.relDate 
          << setw(10)<< p.bill << endl;
}

void readDoctors()
{
     doctors.clear();
     fstream fin;
     fin.open("doctors.csv", ios::in);
     vector<vector<string>> content;
     vector<string> row;
     string line, word;

     while (getline(fin, line))
     {
          row.clear();

          stringstream str(line);

          while (getline(str, word, ','))
               row.push_back(word);
          content.push_back(row);
     }

     for (int i = 1; i < content.size(); i++)
     {
          doctor d(content[i]);
          doctors.push_back(d);
     }
     fin.close();
}

void readPatients()
{
     patients.clear();
     fstream fin;
     fin.open("patients.csv", ios::in);
     vector<vector<string>> content;
     vector<string> row;
     string line, word;

     while (getline(fin, line))
     {
          row.clear();

          stringstream str(line);

          while (getline(str, word, ','))
               row.push_back(word);
          content.push_back(row);
     }

     for (int i = 1; i < content.size(); i++)
     {
          patient p(content[i]);
          
          patients.push_back(p);
     }
     fin.close();
}

void addPat()
{
     patient p; // ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,spec
     cout << "Fill up the following details" << endl;
     cout << "ID:" << endl;
     cin >> p.p_ID;
     cout << "First Name:" << endl;
     cin >> p.fname;
     cout << "Last Name:" << endl;
     cin >> p.lname;
     cout << "Age:" << endl;
     cin >> p.age;
     cout << "Phone No.:" << endl;
     cin >> p.phnumber;
     cout << "Occupation:" << endl;
     cin >> p.occupation;
     cout << "City:" << endl;
     cin >> p.city;
     cout << "Kind of Specialization required:" << endl;
     p.setDept();
     cout << "Admission date  (DD/MM/YYYY):" << endl;
     cin >> p.addDate;
     cout << "Release date  (DD/MM/YYYY):" << endl;
     cin >> p.relDate;
     cout << "Total Bill generated:" << endl;
     cin >> p.bill;

     writetoFile(p);

     cout << "\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit to Main Menu." << endl;
     int c;
     cin >> c;
     if (c == 1)
     {
          getPatientDatabase(); // backtoPatientMenu
     }

     else
          main();
          exit(0);
}

void writetoFile(doctor d)
{
     fstream fileObj;
     fileObj.open("doctors.csv", ios::app);
     // fileObj << "doctorId,firstName,lastName,gender,age,city,qualification,spec,experience\n";
     fileObj.seekp(0, ios::end);
     fileObj << d.ID << ","
             << d.fname << ","
             << d.lname << ","
             << d.gender << ","
             << d.age << ","
             << d.city << ","
             << d.qualification << ","
             << d.spec << ","
             << d.experience << endl;
     fileObj.close();

     // after completion
     cout << "\n\t\tNew Doctor profile created successfully!" << endl
          << endl
          << endl;
}

void writetoFile(patient p)
{
     fstream fileObj;
     fileObj.open("patients.csv", ios::app);
     // fileObj << "ID,firstname,lastname,age,phnumber,occupation,city,department,Adate,Rdate,bill\n";
     fileObj.seekp(0, ios::end);
     fileObj << p.p_ID << ","
             << p.fname << ","
             << p.lname << ","
             << p.age << ","
             << p.phnumber << ","
             << p.occupation << ","
             << p.city << ","
             << p.dep << ","
             << p.addDate << ","
             << p.relDate << ","
             << p.bill << endl;
     fileObj.close();

     cout << "\n\t\tNew Patient profile created successfully!" << endl
          << endl
          << endl;
}

void searchDoctors()
{
     readDoctors();
     readPatients();
     int id;
     cout << "Enter the patient ID"<<endl;
     cin >> id;
     cout << setw(4)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Sex "<<"Age"<<setw(13)<<"City  "<<setw(9)<<"Qual\t"<<setw(10)<<"Speciality "<<"Experience\n";
     for (int i = 0; i < patients.size(); i++)
     {
          if (patients[i].p_ID == id)
          {
               for (int j = 0; j < doctors.size(); j++)
               {
                    if (doctors[j].spec == patients[i].dep)
                    {
                         display(doctors[j]);
                    }
               }
               break;
          }
     }
     cout<<"Search finished"<<endl;
}