#pragma once
#include <fstream>
#include "tools.h"
#include "fclass2.cpp"
#include "advisormenu.cpp"
#include"studentmenu.cpp"
#include "values.h"

using namespace std;

//accepts full name sequencentally
inline void collect(file &studBook, string &fname, string &mname, string &lname){
    studBook>>fname;
    studBook>>mname;
    studBook>>lname;}
    
// nessary declaration 
file logbook,advBook;
const int attemptLimit=3;

void login(){
    cout<<"****##$ Login page $##***";
    
    
    for(int i=0;i<attemptLimit;i++){
    ask(username, password);
    
    if(username=="WCUadmin" and password=="q"){
    cout<<"##-logged in as admin-## \n input user credentials to creat account";
    i=0;
    sign_up();}
    
    else{//check logbook
        logbook.open("logbook.txt",ios:: in);
        bool registered=logbook.registered(username, password);
        logbook.close();
        if(username.at(3)=='A' and registered){
            advisorMenu();
             i=0;}
            
        else if(registered){
            i=0;
            studmenu();}
           
         else{cout<<"wrong user name or password";}
        }}
        cout<<endl<<"too much attempt";
        return ;}
        
void sign_up(){
    
    string password,lname;
    ask(username,password);
    int choice;
    
    studBook.open("student.txt",ios::in);
    bool is_stud=studBook.find(username,idcol);
    collect(studBook,fname,mname,lname);
    studBook.close();
    
    advBook.open("advisors.txt",ios::in);
    bool is_advisor=advBook.find(username);
    collect(advBook,fname,mname,lname);
    advBook.close();
    
    logbook.open("logbook.txt",ios::in);
    bool have_account=logbook.find(username);
    logbook.close();
    
        
    if((is_advisor or is_stud)and !(have_account)){
        logbook.open("logbook.txt",ios::app);
        logbook<<'\n'<<username<<' '<<password<<endl;
        logbook.close();
        cout<<username<<" "<<fname<<" "<<mname<<" "<<lname<<" :signed up successfully";}
    else if (have_account){cout<<"user has account";}
    else{cout<<"invalid user";}
    cout<<"\n \t 0 for login  page \n \t 1 for sign up page \n \t :";
    cin>>choice;
    (bool(choice))?sign_up:login;}
    