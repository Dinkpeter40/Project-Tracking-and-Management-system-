#pragma once
#include <iostream>
#include"signature.h"
#include "values.h"
#include"login_signup.cpp"
#include"studentmenu.cpp"
#include "class.h"
#include "fclass2.cpp"
#include "tools.h"


using namespace std;



//for adding projects
void add_proj(){
    int keep=1;
    string word;
    projectBook.open("projectlist.txt",ios::app);
    cout<<"::++enter projects++::"<<endl<<"project name : ";
    getline(cin>>ws,word);
    projectBook<<endl<<word;
    
    //ask for user action
    cout<<"\n 0 to exit \n 1 to add more \n ";
    cin>>keep;
    projectBook.close();
    if(bool(keep)){add_proj();}
    else {advisorMenu();};
    }
    
//automatic group and project assignment 
void grouper(){
    double mingpa=3.6;
    cout<<"\t input minimum gpa for leader : ";
    cin>>mingpa;
    
    //declarations
    vector <STUDENTS> members;
    vector <STUDENTS> leaders;
    STUDENTS studentloader;
    string  projects[50],projectname;
    int project_count=0;
    if(bool(project_count)){goto skip;}
    //load and separate based on gpa
    studBook.open("student.txt",ios::in);
    while(!studBook.eof()){
        studBook>>studentloader.id;
        studBook>>studentloader.fname;
        studBook>>studentloader.mname;
        studBook>>studentloader.lname;
        studBook>>studentloader.gender;
        studBook>>studentloader.gpa;
       if(studentloader.gpa>= mingpa){
            leaders.push_back(studentloader);}
       else{members.push_back(studentloader);}
        }
        studBook.close();
        
        //project loader
        projectBook.open("projectlist.txt",ios::in);
         while(!(projectBook.eof())){
         getline(projectBook>>ws,projects[project_count]);
         project_count++;}
         projectBook.close();
        
         //leaders and member count
         lead_count=leaders.size();
         member_count=members.size();
         
         skip:
         //shuffling 
         randomizer(project_count,projects);
         randomizer(lead_count,leaders);
         randomizer(member_count,members);
         
         //ask to display
        cout<<"\t  >>"<<lead_count<<" leaders are chosen  \n \t 1 to display \n \t 2 to redo \n \t : ";
        int choice;
        cin>>choice;
        
        int mem=0;//members display id
 
        //choice 1 display  groups
        if (choice==1){
         
         for(int i=0;i<lead_count;i++){
            cout<<"group "<<i+1<<" project "<<projects[i]<<endl<<leaders[i].id<<" "<<leaders[i].fname<<" leader "<<endl;
            //members
            for(int j=0;j<member_count/lead_count;j++){
            cout<<'\t'<<members[mem].id<<" "<<members[mem].fname<<endl;
           mem++;}
           if(i<member_count%lead_count){
            cout<<'\t'<<members[mem].id<<" "<<members[mem].fname<<endl;
           mem++;}}
            
            //ask for user choice(save/redo/exit)
               cout<<"\n \t 1 to save and override \n \t 2 main menu \n \t 3 redo \n \t : ";
               choice=0;
               cin>>choice;
              
             
              // saving section
              if (choice==1){
                   groupBook.open("groups.txt",ios::out);
                
                   mem=0;//member counter
                   for(int i=0;i<lead_count;i++){
                        groupBook<<"start"<<i+1<<endl<<projects[i]<<endl<<leaders[i].id<<" "<<leaders[i].fname<<" "<<leaders[i].mname<<" leader "<<endl;
                        //store members
                        for(int j=0;j<member_count/lead_count;j++){
                            groupBook<<members[mem].id<<" "<<members[mem].fname<<" "<<members[mem].mname<<endl;
                            mem++;}
                       if(i<member_count%lead_count){
                            groupBook<<members[mem].id<<" "<<members[mem].fname<<" "<<members[mem].mname<<endl;
                            mem++;}
                            groupBook<<"end \n"<<"project "<<projects[i]<<endl<<" group "<<i+1<<endl;}
                            //finish stuff up
                        groupBook.close();
                        cout<<" \t >> successfully saved"<<endl;
                        messageBook.open("messages.txt",ios::out);
                        messageBook.close();
                        advisorMenu();}
                        
              
              else if (choice==2){groupBook.close();
              advisorMenu();}
              else{goto line;}}
              
        //choice two
       else{
               line :
       groupBook.close();
       grouper ();}}
        
        
    
 void advisorMenu(){
    int choice;
    cout<<"\t @@@### Wellcom to Advisors menu ###@@@ \n";
    cout<<"\t 1 to add new projects \n \t 2 to auto group and assign task \n \t 3 to log out \n \t :  ";
    cin>>choice;
    if(choice==1){add_proj();}
    else if(choice==3){ return ;}
    else {grouper();}
    }   
    
//int main(){grouper();}
