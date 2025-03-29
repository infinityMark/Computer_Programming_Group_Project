#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
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
	void setRecord(string n, string m, string s_id, int y, float gpa) {
		name = n;
		S_ID = s_id;
		major = m;
		year = y;
		GPA = gpa;
	}

	void getData() {
		cout << name << "  " << S_ID << "  " << major << "  " << year << "  " << GPA;
	}
private:
	string name;	// student's name
	string S_ID;	// student's id
	string major;	// student's major
	vector <string> course;

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

void copy_object_data(vector <Student_record> move_to_arrary) {
	// this function use to copy obejct vector
	for (int i; i < student_record_collection.size(); i++) {
		move_to_arrary.push_back(student_record_collection[i]);
	}
}
void F4() {
	
}

void F5() {

}

void F6() {

}

int main() {
	char prog_choice;
	bool loading_data = false;

	loading_animation();
	Student_record S232210;
	S232210.setRecord("CHAN Tai Man", "S243560", "Information Engineering", 1, 4.00);
	student_record_collection.push_back(S232210);


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