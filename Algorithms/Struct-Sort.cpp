#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	int id;
	int year;
	int month;
	int day;
};

bool com(Student A, Student B) {
	if (A.year != B.year) {
		return A.year < B.year;
	}
	if (A.month != B.month) {
		return A.month < B.month;
	}
	if (A.day != B.day) {
		return A.day < B.day;
	}
	return A.id > B. id;
}

int main() {
	int n;
	cin >> n;
	vector<Student> stu(n);
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].year >> stu[i].month >> stu[i].day;
		stu[i].id = i;
	}
	sort(stu.begin(), stu.end(), com);
	for (int i = 0; i < n; i++) {
		cout << stu[i].name<<endl;
	}
	return 0;
}