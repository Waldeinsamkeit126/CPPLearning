#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String {
    friend istream& operator>>(istream&, String&);
    friend ostream& operator<<(ostream&, const String&);
private:
    int cap, len;                           // capacity and length
    char* data;                             // the content of the string
public:
    String();                               // create empty string with capacity 1
    String(const char*);                   // initialize with proper capacity
    String(const String&);                 // copy with new space
    ~String();                              // release memory
    String operator+(const String&) const; // return the concatenated string
    bool operator<(const String&) const;   // alphabetical order
    String& operator=(const String&);      // allocate new space and release old space
    String& operator+=(const char);         // insert a character at the end of string
};

istream& operator>>(istream&, String&);       // allows the use of cin >> str;
ostream& operator<<(ostream&, const String&); // allows the use of cout << str;

#endif
