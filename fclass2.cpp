#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class file : public fstream{
    public:
    string word;
    public:
    
    //final final checker
    inline bool end(){return (this->eof());}
     
     //word finder in a file
     int find(string keyword,int row=-1,int jump=66){
            if(row==-1){this->seekg(0);} //0 search(default)
            else if (row<-1){this->seekg(row*-1);}//jump search 
            else {this->seekg(row);}//continue search 
              
              //search loop
            int i=0;
        while (!end()){
            //jump condition 
            if (row>-1){this->seekp(i*jump+row);}

            *this>>word;
            if(keyword==word){
                return this->tellg();}
            else if(end()){
                return 0;}
                i++;}}
                
       
                //credential checker  
       bool registered(string keyword,string password,int row=-1,int jump=66){
            find(keyword,row,jump);
            string tempo_password;
            *this>>tempo_password;
            if(password==tempo_password) {return true;}
            else {return false;}}
            };//class ender
    