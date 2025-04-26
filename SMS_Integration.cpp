#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cctype>
using namespace std;

/*
course_information_collection is a 2D vector arrary, in each inside arrary
the data store like below:
{"Subject Code","Subject Name","Credit"}
*/
vector<vector <string>> course_information_collection = {
	{"ENG2042","Introduction to C++","3"}
};

/*
grade_point_collection is a 2D vector arrary, in each inside arrary
the data store like below:
{"Grade","Grade Point"}
*/
vector<vector<string>> grade_point_collection = {
	{"A+","4.3"}, {"A","4.0"}, {"A-","3.7"},
	{"B+","3.3"}, {"B","3.0"}, {"B-","2.7"},
	{"C+","2.3"}, {"C","2.0"}, {"C-","1.7"},
	{"D+","1.3"}, {"D","1.0"}, {"F","0.0"}
};

vector <string> major_collection = {
	"Information Engineering"
};

void menu_word_output(int order, string word) {
	// this is menu word design interface
	if (order == -1) {
		cout << word << endl;
	}
	else {
		cout << "[" << order << "] " << word << endl;
	}
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
	void setSubject_information(const vector<vector<string>>& subject_i) {
		// this is use to set value in the beginning
		for (int i = 0; i < subject_i.size(); i++) {
			// 确保 subject_i[i] 至少有 2 个元素
			if (subject_i[i].size() < 2) {
				continue; // 或者抛出异常
			}
			if (i >= subject_information.size()) {
				subject_information.push_back(vector<string>(2)); // 假设每行 2 列
			}
			subject_information[i][0] = subject_i[i][0];
			subject_information[i][1] = subject_i[i][1];
		}
	}
	void addSubject_information(string subject_name, string subject_grade) {
		int lastest_number = subject_information.size();
		subject_information.push_back({ subject_name,subject_grade });
	}

	void changeSubject_information(string aim_subject, string change_subject, int code_or_grade) {
		for (int i = 0; i < subject_information.size(); i++) {
			if (subject_information[i][0] == aim_subject) {
				subject_information[i][code_or_grade] = change_subject;
				break;
			}
		}
	}

	void printData() {
		cout << name << "  " << S_ID << "  " << major << "  " << year << "  " << GPA;
	}

	void copySubjectInformation(vector<vector<string>>& target) {
		target.clear();  // 清空目标数组
		for (const auto& row : subject_information) {
			if (row.size() >= 2) {
				target.push_back({ row[0], row[1] });  // 复制前两列
			}
		}
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
	vector<vector <string>> subject_information; // should use 2-D arrary store subject-code and Grade

	int year;		// student's year
	float GPA;		// student's gpa
};
vector <Student_record> student_record_collection;//this vector use to contain all object inside

void showInfo() {
	vector<vector <string>> student_info = {
		{"Wu Jiacheng","24127656A","B07A"}
	};
	menu_word_output(-1, "Group Number: 7");
	cout << endl;
	for (int i = 0; i < student_info.size(); i++) {
		cout << "Name      : " << student_info[i][0] << endl;
		cout << "Student ID: " << student_info[i][1] << endl;
		cout << "Class     : " << student_info[i][2] << endl;
		cout << endl;
	}
}

void F1() {

}

void F2() {

}

void F3() {

}


void F4() {

}

void F5() {
}


void F6() {

}

void F7() {
	string sequence = "";
	vector <vector <string>> major_ouput;
	int sum = 0, order = 0;
	menu_word_output(-1, "Show major by total number of attendance by ASC or DESC: ");
	getline(cin, sequence);

	for (int i = 0; i < major_collection.size(); i++) {
		sum = 0;
		for (int j = 0; j < student_record_collection.size(); j++) {
			if (major_collection[i] == student_record_collection[j].getMajor()) {
				sum++;
			}
		}
		major_ouput.push_back({ major_collection[i],to_string(sum) });
	}

	//show_all_vector_information(major_ouput);
	/*if (sequence == "ASC") {

	}
	else if (sequence == "DESC") {

	}
	else {
		menu_word_output(-1, "In valid input!");
	}*/
}

int main() {
	char prog_choice;
	bool loading_data = false;

	//loading_animation();

	//temporary data
	Student_record S243560;

	menu_word_output(-1, "Welcome to use Student Management System");

	do {
		cout << "\n\n";
		cout << "*** SMS Main Menu ***" << endl;
		menu_word_output(1, "Load Starting Data");
		menu_word_output(2, "Show Student Records");
		menu_word_output(3, "Add/Delete Students");
		menu_word_output(4, "Edit Students");
		menu_word_output(5, "Generate Transcript");
		menu_word_output(6, "Credits and Exit");
		menu_word_output(7, "Show total number of people in different major");
		copy_character("*", 21, 1);
		cout << "Option (1 - 7):" << endl;

		cout << "Enter function option number: ";
		cin >> prog_choice;
		cout << "\n\n";

		switch (prog_choice) {
		case '0': showInfo(); break;
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
		case '7':
			if (loading_data == false) break;
			F7(); break;
		default:
			cout << "No such function option " << prog_choice << endl;
			break;
		}
	} while (true); //current condition is temporary ,the end loop statement will be designed by people who cope question 6

	cout << "The Student Management System terminates. Have a good day!  \v:)" << endl;
	return 0;
}