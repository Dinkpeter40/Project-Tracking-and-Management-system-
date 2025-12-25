#pragma once
#include <iostream>
using namespace std;

class STUDENTS{
    public:
    string id;
    string fname;
    string mname;
    string lname;
    char gender;
    double gpa;
    string group;
    
    public:
    STUDENTS(string ID,string FNAME,string MNAME ,
    string LNAME,char GENDER,float GPA){
    id=ID;
    fname=FNAME;
    mname=MNAME;
    lname=LNAME;
    gender=GENDER;
    gpa=GPA;
    }
    STUDENTS(){}
    };
