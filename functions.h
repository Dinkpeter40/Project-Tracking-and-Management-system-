#pragma once
#include <fstream>
#include "tools.h"
using namespace std;

// nessary files

void login(){
    string username, password;
    static int atempts = 0;
    if (atempts < 4){
        ask(username,password);
        
        // log as admin check
        if (username == "WCUadmin" and password == "q"){
            sign_up();} 
        // check password match for on log book
        else if (username.at(3)=='A' and is_registered(username,password)){
                cout << "advisor is  registered" << endl;}
        else if (is_registered(username,password)){
                cout << "•••••• you have logged in as student••••••";}
        else {if (atempts < 3){
                cout << "!!!! wrong password or user name please try again !!!! " << endl;}
                atempts += 1;
                file.close();
                login();}}
    else{
        cout << "too much atempts" << '\n'
             << "### if you dont have an account please contact the department ###" << endl;}}

//signup new user
void sign_up()
{
    cout << '\n'
         << "$$ you logged as admin please inter your user info to add them in to the system $$" << '\n';

    //getting additional informations
    
    string username, password, id;
    bool choice = false;
    string f_name, m_name, l_name,gender;
    string gpa;
    ask(username,password);
    // if needed add a class with condtructor if needed

    //check user name in students file
    int position;
    if (exist(username) or exist(username,-1,"advisors.txt")){
        //check if registered
        if (exist(username,-1,"logbook.txt")){
            cout << '\n'<< "user was already registered (usename taken)" << '\n';
            sign_up();}
        else{
            //writting to log file
            file.open("logbook.txt",ios::app);
            file << '\n'<< username<<" "<< password;
            file.close();
            //showing registered message
            position = find(username);
            file.open("student.txt", ios::in);
            file.seekg(position);
            file >> f_name;
            file >> m_name;
            file >> l_name;
            file>>gender;
            file >> gpa;
            // dispay record
            cout << '\n'<< username << " " << f_name << " " << m_name << " " << l_name << " is registerd as user" << '\n';}
           file.close();}
    //if invalid id inputed
    else
    {
        cout << "id is not registerd in software engneeing # " << '\n';
    }

    //fetch data from file table
    //find matching case from student file
    // exist or retry choice
    cout << "1 to retry or 0 to go back : ";
    cin >> choice;
    if (choice){sign_up();}
    else{login();};}

//int main()
//{}