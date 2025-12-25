#pragma once
#include <iostream>
#include "values.h"
#include "class.h"
#include "fclass2.cpp"
#include "tools.h"
#include"login_signup.cpp"
#include"signature.h"
#include"messages.cpp"

using namespace std;


//for input and display
inline string getNdisplay(string placeholder =""){
   string word ;
   getline (groupBook>>ws,word);
   cout<<placeholder<<word;
   return word;}
  
//finds and display a students group
void view_group(){
   string word;
  
   groupBook.open("groups.txt",ios::in);
   //find store(position) and display student name
    int position= -1*groupBook.find(username);
    getline(groupBook>>ws,word);
    cout<<"student name >> "<<word<<endl;
    
    // displays group number
    groupBook.seekg(groupBook.find("group",position));
    groupBook>>word;
    cout<<"you are in   >> group "<<word<<endl;
    
   // project assigned
   groupBook.seekg(groupBook.find("start"+word));
   getline (groupBook>>ws,word);
   cout<<" \n your project: "<<word;
   
   // displays group all members
   getNdisplay("\n your group members are : \n \t - ");
   for (int i=0;i<50;i++){
       getline (groupBook>>ws,word);
      if(word=="end "){break;}
     else{cout<<"\n \t - "<<word;}}
     groupBook.close();
     //redirect to menu
     studmenu();
}

void studmenu(){
    int choice;
    cout<<"\n \t >> 1 for viewing your group \n \t >> 2 for messages \n \t >> 3 for logout \n \t \t :";
    cin>>choice;
    
    if(choice==1){
        view_group();       
    }
    else if(choice==2){
        cout<<" use /exit command to exist \n ";
        readgroupmessage();}
    else{  login();}
}

