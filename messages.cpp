#pragma once
#include <iostream>
#include "values.h"
#include "fclass2.cpp"
#include "class.h"
#include "tools.h"
#include"login_signup.cpp"
#include"signature.h"

using namespace std;

int getGroup(){
    groupBook.open("groups.txt",ios::in);
    groupBook.find("group",-groupBook.find(username));
    groupBook>>group;
    groupBook.close();
    return group;
}
string  getGroup(string & group){
    groupBook.open("groups.txt",ios::in);
    groupBook.find("group",-groupBook.find(username));
    groupBook>>group;
    groupBook.close();
    return group;
}
void messageTogroup(){
    cout<<"me : ";
   messageBook.open("messages.txt",ios:: app);
    string message;
    getline(cin>>ws,message);
    //existing 
    if(message=="/exit"){
        messageBook.close();
       studmenu();}
   messageBook<<endl<<getGroup ()<<" "<<username<<" "<<message<<endl;
   messageBook.close();
   //readgroupmessage ();
   messageTogroup();}
    
void readgroupmessage (){
    string word,group,slenderid;
    getGroup(group);
   messageBook.open("messages.txt",ios::in);
    studBook.open("student.txt",ios::in);
    while(!messageBook.eof()){
       messageBook>>word ;
        if(group==word){
           messageBook>>slenderid;
           getline (messageBook>>ws,word);
           if (username==slenderid){
            cout<<"me >> "<<word<<endl;}
            else{
             studBook.find(slenderid,idcol);
             studBook>>slenderid; 
             cout<<slenderid<<" >> "<<word<<endl;
               }}}
               messageBook.close();
               studBook.close();
               messageTogroup();
}
