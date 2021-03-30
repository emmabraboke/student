#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
// #include <cstring>
// #include <cstdlib>

using namespace std;

class studentDatabase
{

    public:
        void addRecords();
        void listRecords();
        void modifyRecords();
        void deleteRecords();
        void home();
};
void studentDatabase :: home()
{
    cout<<"========= STUDENT DATABASE MANAGEMENT SYSTEM =========" <<endl;
    cout<<endl <<endl;
    cout<<"     .1 Add      Records" <<endl;
    cout<<"     .2 List     Records" <<endl;
    cout<<"     .3 Modify   Records" <<endl;
    cout<<"     .4 Delete   Records" <<endl;
    cout<<"     .5 Exit     Records" <<endl;
}

void studentDatabase :: addRecords()
{   
    int x;
    char userchoice;
    ofstream profile;
    do{
    profile.open("profile.txt", ios::app);
    cout<<"Enter your name: ";
    string name;
    getline(cin,name);
   
    profile<<name <<"\t";

    cout<<"Numbers of courses: " <<endl;
    cin>>x;  
    cin.ignore();
    for (int y=0; y<x; y++)
    {
    string buf1;
    cout<<"Enter course Title: " <<endl;
    
    getline(cin,buf1);
    profile<<buf1 <<endl;
    }
   
    cout<<"Do you want to add another record" <<endl;
    cin>>userchoice;
    userchoice=toupper(userchoice);
    }while(toupper(userchoice)=='Y');
};

void studentDatabase::listRecords()
{
string list;
  ifstream studentprofile;
  studentprofile.open("profile.txt");
  if (!studentprofile.fail())
  {
      while(studentprofile>>list)
      {
          cout<<list << " " ;
      }
      cout<<endl;
  }

}

void studentDatabase :: modifyRecords()
{
    string list;
    string delist;
    string name;
    cout<<"Enter record: " << endl;
    getline(cin,delist);
    ifstream studentprofile;
    ofstream profile;
    studentprofile.open("profile.txt");
    profile.open("pro.txt");
    while(!studentprofile.eof())
    { 
        studentprofile>>list;
        if (list == delist)
        {
        profile<< "Kennedina" <<endl;
        }
        else
        {
        profile<<list <<endl;
        }

    }
    profile.close();
    studentprofile.close();
    remove("profile.txt");
    rename("pro.txt","profile.txt");
    //cin.ignore();
}
void studentDatabase :: deleteRecords()
{   char option;
    cout<< "Do you want to Delete Records (Y/N)? " <<endl;
    cin>>option;
    if (toupper(option)=='Y')
    {
    remove("profile.txt");
    cout<<"Records deleted " <<endl;
    }
}
    int main()
    {    
        studentDatabase student;
        student.home();
        int z;
        do{ 
            cout<<"Select Option" <<endl;
            cin>>z;
            switch(z)
            {
            case 1:
            {   cin.ignore();
                student.addRecords();
                break;
            }
        
            
            case 2:
            {
                student.listRecords();
                break;
            }
            case 3:
            {
            student.modifyRecords();
            break;
            }
            case 4:
            {   
                cin.ignore();
                student.deleteRecords();
                break;
            }
            }
        } while(z!=5);
        return 0;
   }


