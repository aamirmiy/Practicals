/*Department maintains a student information. The file contains roll number, name, division and address. 
Allow user to add, delete information of student. Display information of particular employee. 
If record of student does not exist an appropriate message is displayed. 
If it is, then the system displays the student details. Use sequential file to main the data.*/
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Student
{
    string name, address, rno, div;
    Student()
    {
        cout << "Enter student name, rno, div, address\n";
        cin >> name >> rno >> div >> address;
    }
    friend class StudentFile;
};
class StudentFile
{
    string records;

public:
    StudentFile()
    {
        records="";
    }
    void add_rec();
    void del_rec();
    void find_stu();
};
void StudentFile::find_stu()
{
    cout<<"Enter student name to be found\n";
    string findname;
    cin>>findname;

    ifstream filein("text.txt");
    string result="";
    if (!filein)
    {
        cout << "Error opening files!" << endl;
    }
    string temp_rec="";
    int flag_del=0;
    while(getline(filein, temp_rec))
    {
        if(temp_rec.find(findname)!=-1)
        {
            cout<<temp_rec<<endl;
        } 
    }
    filein.close();
}
void StudentFile::del_rec()
{
    cout<<"Enter student name to be deleted\n";
    string delname;
    cin>>delname;

    ifstream filein("text.txt");
    string result="";
    if (!filein)
    {
        cout << "Error opening files!" << endl;
    }
    string temp_rec="";
    int flag_del=0;
    while(getline(filein, temp_rec))
    {
        if(temp_rec.find(delname)==-1)
        {
            result+= temp_rec+"\n";
        } else
        {
            flag_del=1;
        }
    }
    filein.close();

    if(flag_del==1)
    {
        cout<<"Records: \n"<<result;
        ofstream fileo("text.txt");
        fileo<<result;
        fileo.close();
    } else
    {
        cout<<"Record not found\n";
    }
    
}
void StudentFile::add_rec()
{
    Student s;

    ifstream filein("text.txt");

    if (!filein)
    {
        cout << "Error opening files!" << endl;
    }
    int flag_add=0;
    string temp_rec="";
    while(getline(filein, temp_rec))
    {
        string curr_name;
        
        curr_name=temp_rec.substr(0, temp_rec.find_first_of(' '));

        if((curr_name>=s.name)&&flag_add==0)
        {
            records+= s.name+" "+s.rno+" "+s.div+" "+s.address+"\n";
            records+= temp_rec+"\n";
            flag_add=1;
        } else
        {
            records+= temp_rec+"\n";
        }
        
        temp_rec="";
    }
    if(flag_add==0)
    {
        records+= s.name+" "+s.rno+" "+s.div+" "+s.address+"\n";
    }
    cout<<"Records: \n"<<records;
    filein.close();
    ofstream fileo("text.txt");
    fileo<<records;
    fileo.close();
}
int main()
{
    StudentFile sf;
    //sf.add_rec();
    //sf.del_rec();
    sf.find_stu();
}
