#pragma once
#include <fstream>
#include<iostream>

using namespace std;

//login logout 
void sign_up();
void login();
inline void collect(file &studBook, string &fname, string &mname, string &lname);

//advisors Menu 
void advisorMenu();
void add_proj();
void grouper();

//student Menu 
void studmenu();
inline string getNdisplay(string placeholder);
void view_group();

void readgroupmessage ();
void messageTogroup();