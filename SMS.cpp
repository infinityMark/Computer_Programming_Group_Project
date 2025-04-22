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
vector<vector <string>> grade_point_collection = {
	{"A+","4.3"}
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

int returnCourse_information_collection_location(string code) {
	// Q4 FUNCTION
	for (int i = 0; i < course_information_collection.size(); i++) {
		if (course_information_collection[i][0] == code) {
			return i;
		}
	}
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
	void printSubject_information() {
		/*int largest_width;
		for (int i = 0; i <= subject_information.size(); i++) {
			if (i == 0) {
				largest_width = subject_information[0][1].length();
			}
			else {
				if (subject_information[i][1].length() > largest_width) {
					largest_width = subject_information[0][1].length();
				}
			}
		}*/
		cout << "Code" << setw(18) << "Subject title" << setw(15) << "Grade" << setw(7) << "Credit" << endl;
		for (int i = 0; i < subject_information.size(); i++) {
			cout << subject_information[i][0] << "  " << course_information_collection[returnCourse_information_collection_location(subject_information[i][0])][1] << setw(7) << subject_information[i][1] << setw(8) << course_information_collection[returnCourse_information_collection_location(subject_information[i][0])][2] << endl;
		}
		copy_character("-", 7, 0);
		copy_character(" ", 2, 0);
	}
	int returnSubject_information_exist(string check) {
		for (int i = 0; i < subject_information.size(); i++) {
			if (subject_information[i][0] == check) {
				return i;
			}
		}
		return -1;
	}
	string getSubject_grade(string code) {
		return subject_information[returnSubject_information_exist(code)][1];
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

bool returnCourse_information_collection_exist(string check) {
	for (int i = 0; i < course_information_collection.size(); i++) {
		if (course_information_collection[i][0] == check) {
			return true;
		}
	}
	return false;
}

void addCourse_information_collection(string code, string course_name, string credit) {
	course_information_collection.push_back({code,course_name,credit});
}

bool subject_code_valid_check(string code) {
	int capital_letter = 0;
	int number_digits = 0;

	if (code.length() == 7) {
		for (int i = 0; i < 7; i++) {
			if (code[i] >= 'A' && code[i] <= 'Z') {
				capital_letter++;
			}
			if (code[i] >= '0' && code[i] <= '9') {
				number_digits++;
			}
		}
	}
	if (capital_letter == 3 && number_digits == 4) {
		return true;
	}
	else {
		return false;
	}
}

void show_all_vector_information( vector<vector <string>> element) {
	for (int i = 0; i < element.size(); i++) {
		for (int j = 0; j < element[i].size(); j++) {
			cout << element[i][j] << "  ";
		}
		cout << endl;
	}
}

void F4() {
	string inputed_ID = "";
	char option;
	bool valid_SID = false;
	int trial_time = 0;
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
			vector <vector<string>> previous_data_arrary;
			string current_data = "";
			string confirmation = "";

			cout << "\n\n";
			cout << "Action	for Student ID: " << inputed_ID << endl;
			cout << "**** " << "Edit Student Menu" << " ****" << endl;
			menu_word_output(1, "Edit Student Name");
			menu_word_output(2, "Edit Major");
			menu_word_output(3, "Edit Subject List");
			menu_word_output(4, "Return to Main Menu");
			menu_word_output(5, "Show all subject provided");
			menu_word_output(6, "Show the grade point");
			copy_character("*", 29, 1);
			cout << "Option (1-4): ";
			cin >> option;
			cin.ignore();

			cout << "\n\n";

			switch (option) {
			case '1':
				previous_data = student_record_collection[direct_object_location].getName();
				cout << "The current name of student" << "(" << inputed_ID << ")" << " is :" << endl << endl << previous_data << endl;
				copy_character("-", previous_data.length(), 1);
				cout << endl;
				cout << "Enter a new name to the student " << "(" << inputed_ID << "): ";
				cin.ignore();
				getline(cin, current_data);

				cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

				cin.ignore();
				cin >> confirmation;
				cout << endl << endl;

				if (confirmation == "Y" || confirmation == "y") {
					current_data = name_upper(current_data);
					student_record_collection[direct_object_location].setName(current_data);
					show_edited_information(previous_data, student_record_collection[direct_object_location].getName());
					cout << "The change is successfully." << endl;
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
				cout << "Enter a new major to the student " << "(" << inputed_ID << "): ";
				cin.ignore();
				getline(cin, current_data);

				cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

				cin.ignore();
				cin >> confirmation;
				cout << endl;

				if (confirmation == "Y" || confirmation == "y") {
					current_data = major_upper(current_data);
					student_record_collection[direct_object_location].setMajor(current_data);
					show_edited_information(previous_data, student_record_collection[direct_object_location].getMajor());
					cout << "The change is successfully." << endl;
				}
				else if (confirmation == "N" || confirmation == "n") {
					cout << "The change is readly withdraw." << endl;
				}
				else {
					cout << "Invalid input!";
				}
				break;
			case '3':
				//student_record_collection[direct_object_location].copySubjectInformation(previous_data_arrary);
				cout << "The current subject of student" << "(" << inputed_ID << ")" << " is :" << endl << endl;
				student_record_collection[direct_object_location].printSubject_information();
				trial_time = 0;
				cout << endl;
				cout << "Which subject do you want to change" << endl;
				do {
					cout << "Enter subject code: " << endl << endl;
					getline(cin, previous_data); // the subject name or code the user want to change
					if (subject_code_valid_check(previous_data) == true) {
						menu_word_output(-1, previous_data);
						break;
					}
					else {
						trial_time++;
					}
					menu_word_output(-1, previous_data);

					cout << "You still have " << (3 - trial_time) << " chance." << endl;
				} while (trial_time < 3);
				
				if (subject_code_valid_check(previous_data) == true && trial_time < 3) {
					if (student_record_collection[direct_object_location].returnSubject_information_exist(previous_data)!=-1) {
						// 1st case
						cout << "Now you can change the student " << inputed_ID << "'s " << previous_data << "'s grade: " << endl;
						getline(cin,current_data); //grade value

						if (student_record_collection[direct_object_location].getSubject_grade(previous_data)!="--" && current_data == "--") {
							// can't change the grade condition
							menu_word_output(-1, "Sorry you can't change the value, bacause the subject's code is continuous.");
						}
						else {
							cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

							cin >> confirmation;
							cout << endl;

							if (confirmation == "Y" || confirmation == "y") {
								current_data = name_upper(current_data);
								student_record_collection[direct_object_location].changeSubject_information(previous_data, current_data, 1);
								//show_edited_information(previous_data, student_record_collection[direct_object_location].getMajor());
								cout << "The change is successfully." << endl;
							}
							else if (confirmation == "N" || confirmation == "n") {
								cout << "The change is readly withdraw." << endl;
							}
							else {
								cout << "Invalid input!";
							}
						}
					}
					else if (student_record_collection[direct_object_location].returnSubject_information_exist(previous_data) == -1 && returnCourse_information_collection_exist(previous_data) == true) {
						// 2nd case
						menu_word_output(-1, "The subject is going to add into the student's subject lists");
						menu_word_output(-1, "Please input the subject's grade:");
						cin.ignore();
						getline(cin, current_data);

						cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";
						cin >> confirmation;
						cout << endl;

						if (confirmation == "Y" || confirmation == "y") {
							current_data = name_upper(current_data);
							student_record_collection[direct_object_location].addSubject_information(previous_data, current_data);
							//show_edited_information(previous_data, student_record_collection[direct_object_location].getMajor());
							cout << "The change is successfully." << endl;
						}
						else if (confirmation == "N" || confirmation == "n") {
							cout << "The change is readly withdraw." << endl;
						}
						else {
							cout << "Invalid input!";
						}
					}
					else {
						// 3rd case
						string temp = "";
						menu_word_output(-1, "The subject is going to add into the student's subject lists");
						menu_word_output(-1, "Please input the new subject's title");
						getline(cin, current_data);
						menu_word_output(-1, "Please input the new subject's credit:");
						getline(cin, temp);

						cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";
						getline(cin, confirmation);
						cout << endl;

						if (confirmation == "Y" || confirmation == "y") {
							current_data = major_upper(current_data);
							addCourse_information_collection(previous_data, current_data, temp);
							//show_edited_information(previous_data, student_record_collection[direct_object_location].getMajor());

							menu_word_output(-1, "The subject is going to add into the student's subject lists");
							menu_word_output(-1, "Please input the subject's grade to the student:");
							getline(cin, current_data);
							student_record_collection[direct_object_location].addSubject_information(previous_data, current_data);

							cout << "The change is successfully." << endl;
						}
						else if (confirmation == "N" || confirmation == "n") {
							cout << "The change is readly withdraw." << endl;
						}
						else {
							cout << "Invalid input!";
						}
					}
				}
				break;
			case '4':
				cout << "You are returing to the Main Menu." << endl;
				//loading_animation();
				break;
			case '5':
				show_all_vector_information(course_information_collection);
				break;
			case '6':
				cout << "Grade" << "  " << "Point represent" << endl;
				show_all_vector_information(grade_point_collection);
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
	S243560.setSubject_information({{"ENG2042","A+"}});
	student_record_collection.push_back(S243560);


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
		copy_character("*", 21, 1);
		cout << "Option (1 - 6):" << endl;

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
		default:
			cout << "No such function option " << prog_choice << endl;
			break;
		}
	} while (true); //current condition is temporary ,the end loop statement will be designed by people who cope question 6

	cout << "The Student Management System terminates. Have a good day!  \v:)" << endl;
	return 0;
}