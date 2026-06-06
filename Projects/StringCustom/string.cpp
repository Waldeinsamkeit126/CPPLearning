#include "string.h"

String::String() {
	cap = 1;
	len = 0;
	data = new char[cap];
	data[0] = '\0';
}

String::String(const char* s) {
	len = 0;
	while (s[len] != '\0') {
		len++;
	}
	cap = 1;
	while (cap <= len) {
		cap *= 2;
	}
	data = new char[cap];
	for (int i = 0; i < len; i++) {
		data[i] = s[i];
	}
	data[len] = '\0';
}

String::String(const String& Target) {
	this->len = Target.len;
	this->cap = Target.cap;
	this->data = new char[cap];
	for (int i = 0; i < len+1; i++) {
		data[i] = Target.data[i];
	}
}

String::~String() {
	delete[]data;
}

String String::operator+(const String& other) const {
	String str;
	int newlen = this->len + other.len;
	int newcap=1;
	while (newcap <= newlen) {
		newcap *= 2;
	}
	str.data = new char[newcap];
	for (int i = 0; i < this->len; i++) {
		str.data[i] = this->data[i];
	}
	for (int i = 0; i < other.len; i++) {
		str.data[len + i] = other.data[i];
	}
	str.data[newlen] = '\0';
	str.len = newlen;
	str.cap = newcap;
	return str;
}

bool String::operator<(const String& other) const {
	int i = 0;
	while (i < len && i < other.len) {
		if (data[i] < other.data[i]) {
			return true;
		}
		if (data[i] > other.data[i]) {
			return false;
		}
		i++; 
	}
	return len < other.len;
}

String& String::operator=(const String& Target) {
	delete[] data;
	this->len = Target.len;
	this->cap = Target.cap;
	this->data = new char[cap];
	for (int i = 0; i < len + 1; i++) {
		data[i] = Target.data[i];
	}
	return *this;
}

String& String::operator+=(const char c) {
	if (len + 1 >= cap) {
		int newCap = cap * 2;
		char* newData = new char[newCap];
		for (int i = 0; i < len; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		cap = newCap;
	}
	data[len] = c;
	len++;
	data[len] = '\0';
	return *this;
}

istream& operator>>(istream& input, String& str) {
	String result;
	char ch;
	while (input.get(ch) && ch == ' ') {
	}
	if (input) {
		result += ch;
		while (input.get(ch) && ch != ' ') {
			result += ch;
		}
		if (ch == ' ' ) {
			input.putback(ch);
		}
	}
	str = result;
	return input;
}
ostream& operator<<(ostream& out, const String& str) {
	for (int i = 0; i < str.len; i++) {
		out << str.data[i];
	}
	return out;
}