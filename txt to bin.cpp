#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void writeField(ofstream& f, const char* src, int width) {
    char buf[50];
    memset(buf, ' ', width);
    memcpy(buf, src, min((int)strlen(src), width));
    f.write(buf, width);
    f.write(" ", 1);
}

int main() {
    ifstream sfile("students.txt");
    ofstream dfile("student.txt", ios::binary);

    char id[20], fname[20], mname[20], lname[20], gender[10], gpa[10];

    while (sfile >> id >> fname >> mname >> lname >> gender >> gpa) {
        writeField(dfile, id, 10);
        writeField(dfile, fname, 15);
        writeField(dfile, mname, 15);
        writeField(dfile, lname, 15);
        writeField(dfile, gender, 1);
        writeField(dfile, gpa, 4);
    }
}