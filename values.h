#pragma once
#include "fclass2.cpp"
#include <iostream>
#include <vector>
using namespace std;

enum row {idcol=0,fnamecol=11,mnamecol=27,lnamecol=43,gendercol=59,gpacol=61,jump=66};
file projectBook,studBook,groupBook, messageBook;
string username,fname,mname, password;
int group_count, member_count,lead_count;
int group;