#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

void menu_word_output(int order, string word) {
	// this is menu word design interface
	cout << "[" << order << "] " << word << endl;
}
void copy_character(string character, int sum, int space) {
	// this can use to print out numerous same character, last one mean should add space when finish print
	for (int i = 0; i < sum; i++) {
		cout << character;
	}
	if (space == 1) {
		cout << endl;
	}
}
void beginning_progress(int progress) {
	cout << "\r|";

	copy_character("*", progress, 0);
	copy_character(" ", 100 - progress, 0);

	cout << "| " << setw(3) << progress << "%";
}
void loading_animation() {
	cout << "\r+";
	for (int i = 0; i <= 100; i++) {
		if (i == 2) {
			cout << "loading";
			i += 7;
		}
		else {
			cout << "-";
		}
	}
	cout << "+" << endl;
	// loading animation, only show in the beginning
	for (int j = 0; j <= 100; j++) {
		beginning_progress(j);
		Sleep(100 - j);//loading time
	}
	cout << "\033[A" << "\r+-completed" << "\033[2B";
	cout << "\r+";
	copy_character("-", 100, 0);
	cout << "+" << endl;
}

class Student_record {
public:
	void setRecord(string n, string s_id, string m, int y, float gpa) {
		name = n;
		S_ID = s_id;
		major = m;
		year = y;
		GPA = gpa;
	}
	void setName(string n) {
		name = "";
		name = n;
	}
	void setMajor(string m) {
		major = "";
		major = m;
	}

	void getData() {
		cout << name << "  " << S_ID << "  " << major << "  " << year << "  " << GPA;
	}
	string getS_ID() {
		return S_ID;
	}
	string getName() {
		return name;
	}
	string getMajor() {
		return major;
	}
private:
	string name;	// student's name
	string S_ID;	// student's id
	string major;	// student's major
	vector <string> subject_information = {{}}; // subject cord and Grade

	int year;		// student's year
	float GPA;		// student's gpa
};
vector <Student_record> student_record_collection;//this vector use to contain any object inside

void F1() {

}

void F2() {

}

void F3() {

}

void copy_object_data(vector <Student_record> student_record_collection_oringinal) {
	// this function use to copy obejct vector
	for (int i = 0; i < student_record_collection.size(); i++) {
		student_record_collection_oringinal.push_back(student_record_collection[i]);
	}
}

void show_edited_information(string before, string current) {
	//int margin = abs(current.size() - before.size());
	cout << "Before" << setw(fabs(before.size() - 6) + 4 + 7) << "Current" << endl;
	copy_character("-", before.size(), 0);
	cout << setw(5);
	copy_character("-", current.size(), 1);
	cout << before << " -> " << current;
};

void prompt_change_student_information(string i, string p, string c, string confirma, string mission) {
	cout << "The current " << mission << " of student" << "(" << i << ")" << " is :" << p << endl << endl;
	cout << "Enter a new to the student " << "(" << i << "): ";
	cin.ignore();
	getline(cin, c);

	cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

	cin >> confirma;
	cout << endl;
}

string name_upper(string name) {
	bool space = false;
	for (int i = 0; i < name.size(); i++) {
		if (space == false) {
			if (name[i] >= 'a' && name[i] <= 'z') {
				name[i] = toupper(name[i]);
			}
			if (name[i] == ' ') {
				space = true;
			}
		}
		else {
			// first name check
			if (name[i] >= 'a' && name[i] <= 'z' && name[i - 1] == ' ') {
				name[i] = toupper(name[i]);
			}
			if (name[i] >= 'A' && name[i] <= 'Z' && name[i - 1] != ' ') {
				name[i] = tolower(name[i]);
			}
		}
	}
	return name;
}

string major_upper(string major) {
	major[0] = major[0] - 'a' + 'A';

	for (int i = 1; i < major.size(); i++) {
		if (major[i - 1] == ' ') {
			major[i] = major[i] - 'a' + 'A';
		}
		if (major[i] >= 'A' && major[i] <= 'Z' && major[i - 1] != ' ') {
			major[i] = tolower(major[i]);
		}
	}
	return major;
}
void F4() {
	string inputed_ID = "";
	char option;
	bool valid_SID = false;
	int direct_object_location;

	cout << "Please input a StudentID for check: ";
	cin >> inputed_ID;
	vector <Student_record> student_record_collection_oringinal;

	// check for whether the studentID exits or not
	for (int i = 0; i < student_record_collection.size(); i++) {
		if (inputed_ID == student_record_collection[i].getS_ID()) {
			valid_SID = true;
			direct_object_location = 0;
		}
	}
	if (valid_SID == true) {
		do {
			string previous_data = "";
			string current_data = "";
			string confirmation = "";

			cout << "\n\n";
			cout << "Action	for Student ID: " << inputed_ID << endl;
			cout << "**** " << "Edit Student Menu" << " ****" << endl;
			menu_word_output(1, "Edit Student Name");
			menu_word_output(2, "Edit Major");
			menu_word_output(3, "Edit Subject List");
			menu_word_output(4, "Return to Main Menu");
			copy_character("*", 29, 1);
			cout << "Option (1-4): ";
			cin >> option;

			cout << "\n\n";

			switch (option) {
				//case '0': showInfo(); break;
			case '1':
				previous_data = student_record_collection[direct_object_location].getName();
				cout << "The current name of student" << "(" << inputed_ID << ")" << " is :" << endl << endl << previous_data << endl;
				copy_character("-", previous_data.length(), 1);
				cout << endl;
				cout << "Enter a new to the student " << "(" << inputed_ID << "): ";
				cin.ignore();
				getline(cin, current_data);

				cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

				cin >> confirmation;
				cout << endl << endl;

				if (confirmation == "Y" || confirmation == "y") {
					current_data = name_upper(current_data);
					student_record_collection[direct_object_location].setName(current_data);
					show_edited_information(previous_data, student_record_collection[direct_object_location].getName());
				}
				else if (confirmation == "N" || confirmation == "n") {
					cout << "The change is readly withdraw." << endl;
				}
				else {
					cout << "Invalid input!";
				}
				cout << endl;
				break;
			case '2':
				previous_data = student_record_collection[direct_object_location].getMajor();
				cout << "The current major of student" << "(" << inputed_ID << ")" << " is :" << endl << endl << previous_data << endl;
				copy_character("-", previous_data.length(), 1);
				cout << endl;
				cout << "Enter a new to the student " << "(" << inputed_ID << "): ";
				cin.ignore();
				getline(cin, current_data);

				cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

				cin >> confirmation;
				cout << endl;

				if (confirmation == "Y" || confirmation == "y") {
					current_data = major_upper(current_data);
					student_record_collection[direct_object_location].setMajor(current_data);
					show_edited_information(previous_data, student_record_collection[direct_object_location].getMajor());
				}
				else if (confirmation == "N" || confirmation == "n") {
					cout << "The change is readly withdraw." << endl;
				}
				else {
					cout << "Invalid input!";
				}
				break;
			case '3':
				//copy_object_data(student_record_collection_oringinal);
				break;
			case '4':
				cout << "You are returing to the Main Menu." << endl;
				//loading_animation();
				break;
			default:
				cout << "No such function option " << option << endl;
				break;
			}
		} while (option != '4');
	}
}

void F5() {

}

void F6() {

}

int main() {
	char prog_choice;
	bool loading_data = false;

	//loading_animation();

	//temporary data
	Student_record S243560;
	S243560.setRecord("CHAN Tai Man", "S243560", "Information Engineering", 1, 4.00);
	student_record_collection.push_back(S243560);


	cout << "Welcome to use Student Management System" << endl;

	do {
		cout << "\n\n";
		cout << "*** SMS Main Menu ***" << endl;
		menu_word_output(1, "Load Starting Data");
		menu_word_output(2, "Show Student Records");
		menu_word_output(3, "Add/Delete Students");
		menu_word_output(4, "Edit Students");
		menu_word_output(5, "Generate Transcript");
		menu_word_output(6, "Credits and Exit");
		copy_character("*", 21, 1);
		cout << "Option (1 - 6):" << endl;

		cout << "Enter function option number: ";
		cin >> prog_choice;
		cout << "\n\n";

		switch (prog_choice) {
			//case '0': showInfo(); break;
		case '1':
			loading_data = true;
			F1(); break;
		case '2':
			if (loading_data == false) break;
			F2(); break;
		case '3':
			if (loading_data == false) break;
			F3(); break;
		case '4':
			if (loading_data == false) break;
			F4(); break;
		case '5':
			if (loading_data == false) break;
			F5(); break;
		case '6':
			F6(); break;
		default:
			cout << "No such function option " << prog_choice << endl;
			break;
		}
	} while (true); //current condition is temporary ,the end loop statement will be designed by people who cope question 6

	cout << "The Student Management System terminates. Have a good day!  \v:)" << endl;
	return 0;
}