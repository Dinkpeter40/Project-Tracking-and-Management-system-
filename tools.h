#pragma once
#include <iostream>
#include "class.h"
#include "values.h"

using namespace std;
//placeholder data type 
template <typename DATA>

//randomizing function(for all data type arrays )
int randomizer(int num, DATA randomarr[]){
    int x;
    DATA temp1;
    srand(time(NULL));
    //randomizing mixer loop
    for(int i=0;i<num;i++){
       for(int j=0;j<i;j++){
            x=(rand()%i);
            temp1=randomarr[x];
            randomarr[x]=randomarr[i-x];
            randomarr[i-x]=temp1;
            return 0;
           }}}
           
//randomizing function(for vector)         
 void randomizer(int num,vector <STUDENTS> & list){
    int x;
    STUDENTS temp1;
    srand(time(NULL));
    //mixer
    for(int i=0;i<num;i++){
       for(int j=0;j<i;j++){
            x=(rand()%i);
            temp1=list.at(x);
            list.at(x)=list.at(i-x);
            list.at(i-x)=temp1;
           }}}
           
//asks and accept username and password        
void ask(string & username,string &password){
       cout <<endl<< "please inter username : WCU";
       cin >> username;
       cout << "please inter password : ";
       cin >> password;
       username = "WCU" + username;
       return;}
       
void modifypassword (string oldword, string newword){
           string word;
           file bufferBook,Book;
           bufferBook.open("buffer.txt",ios::out);
           Book.open("logbook.txt",ios::in);
           while(!Book.eof()){
           Book>>word;
           bufferBook<<word;
           Book>>word;
           if (oldword==word){word=newword;}
           bufferBook<<word<<endl;}
           
           Book.close();
           bufferBook.close();
           
           Book.open("buffer.txt",ios::out);
           bufferBook.open("logbook.txt",ios::in);
           while(!Book.eof()){
           bufferBook>>word;
           Book<<word;
           }
           Book.close();
           bufferBook.close();
       }