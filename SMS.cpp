#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

/*
course_information_collection is a 2D vector arrary, in each inside arrary
the data store like below:
{"Subject Code","Subject Name","Credit"}
*/
vector<vector <string>> course_information_collection = {
	{"ENG2042","Introduction to C++","3"},
	{"ENG2219", "Signal Processing", "3"},
	{"LCH1302", "Professional English Writing", "2"},
	{"LCH1019", "Japanese I", "2"},
	{"ENG1113", "Structural Fundamental", "3"},
	{"ENG2250", "Engineering Mathematics", "3"},
	{"ENG2041", "Applied Computing", "3"},
	{"BUS1021", "Personal Financial Planning", "3"},
	{"BUS1021", "Personal Financial Planning", "3"},
	{"BUS2002", "Introduction to Economics", "3"},
	{"BUS3006", "Understanding Globalization", "3"},
	{"BUS4510", "Business Project Management", "4"},
	{"BUS5523", "Final Year Project", "5"},
	{"LCH1019", "Japanese I", "2"},
	{"PSY1234", "Introduction to Psychology", "2"},
	{"PSY2233", "Sociology", "3"},
	{"PSY2190", "Human Behavior", "3"}
};

/*
grade_point_collection is a 2D vector arrary, in each inside arrary
the data store like below:
{"Grade","Grade Point"}
*/
vector<vector <string>> grade_point_collection = {
	{"A+","4.3"}, {"A","4.0"}, {"A-","3.7"},
	{"B+","3.3"}, {"B","3.0"}, {"B-","2.7"},
	{"C+","2.3"}, {"C","2.0"}, {"C-","1.7"},
	{"D+","1.3"}, {"D","1.0"}, {"F","0.0"}
};

vector <string> major_collection = {
	"Information Engineering",
	"Civil Engineering",
	"Global Business",
	"Educational Psychology"
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
	void setGPA(float gpa) {
		GPA = 0.0;
		GPA = gpa;
	}
	void setYear(int y) {
		year = 0;
		year = y;
	}
	void setStudentID(string sid) {
		S_ID = sid;
	}

	int calculateCredits() {
		int credits = 0;
		for (size_t i = 0; i < subject_information.size(); i++) {
			if (subject_information[i][1] == "--" || subject_information[i][1] == "F")
				continue;
			// 查找课程学分
			for (size_t j = 0; j < course_information_collection.size(); j++) {
				if (course_information_collection[j][0] == subject_information[i][0]) {
					credits += atoi(course_information_collection[j][2].c_str());
					break;
				}
			}
		}
		return credits;
	}
	void printSortedSubjects() {
		// 冒泡排序按科目代码排序
		if (subject_information.size() <= 0) {
			cout << "Code     Subject Title                          Grade  Credit\n";
			cout << "-------------------------------------------------------------\n";
			menu_word_output(-1, "No any subject");
		}
		else {
			for (size_t i = 0; i < subject_information.size() - 1; i++) {
				for (size_t j = 0; j < subject_information.size() - i - 1; j++) {
					if (subject_information[j][0] > subject_information[j + 1][0]) {
						swap(subject_information[j], subject_information[j + 1]);
					}
				}
			}
			cout << "Code     Subject Title                          Grade  Credit\n";
			cout << "-------------------------------------------------------------\n";
			for (size_t i = 0; i < subject_information.size(); i++) {
				string code = subject_information[i][0];
				string grade = subject_information[i][1];
				string title = "";
				string credit = "";
				// 查找课程信息
				for (size_t j = 0; j < course_information_collection.size(); j++) {
					if (course_information_collection[j][0] == code) {
						title = course_information_collection[j][1];
						credit = course_information_collection[j][2];
						break;
					}
				}
				cout << left << setw(8) << code
					<< " " << setw(40) << title
					<< " " << setw(5) << grade
					<< " " << credit << endl;
			}
			cout << "-------------------------------------------------------------\n";
		}
	}
	float calculateGPA() {
		float total = 0.0;
		int total_credit = 0;
		for (size_t i = 0; i < subject_information.size(); i++) {
			if (subject_information[i][1] == "--") continue;
			// 获取绩点
			float  point = 0.0;
			for (size_t j = 0; j < grade_point_collection.size(); j++) {
				if (grade_point_collection[j][0] == subject_information[i][1]) {
					point = atof(grade_point_collection[j][1].c_str());
					break;
				}
			}
			// 获取学分
			int credit = 0;
			for (size_t j = 0; j < course_information_collection.size(); j++) {
				if (course_information_collection[j][0] == subject_information[i][0]) {
					credit = atoi(course_information_collection[j][2].c_str());
					break;
				}
			}
			total += point * credit;
			total_credit += credit;
		}
		return (total_credit > 0) ? total / total_credit : 0.0;
	}
	void setSubject_information(const vector<vector<string>>& subject_i) {
		// this is use to set value in the beginning
		for (int i = 0; i < subject_i.size(); i++) {
			// Ensure that subject_i[i] has at least 2 elements
			if (subject_i[i].size() < 2) {
				continue; // Or throw an exception
			}
			if (i >= subject_information.size()) {
				subject_information.push_back(vector<string>(2)); // Assume 2 columns per row
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
		cout << "student: " << name << " ID: " << S_ID << " Major: " << major << " Year" << year;
		if (GPA < 0.001)
		{
			cout << " GPA: N/A";
		}
		else {
			cout <<" GPA: " << fixed << setprecision(2) << GPA;
		}
	}

	void copySubjectInformation(vector<vector<string>>& target) {
		target.clear();  // clean aim target
		for (const auto& row : subject_information) {
			if (row.size() >= 2) {
				target.push_back({ row[0], row[1] });  // Copy the first two columns
			}
		}
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
	string getS_ID() const {
		return S_ID;
	}
	string getName() const {
		return name;
	}
	string getMajor() const {
		return major;
	}
	int getYear() const {
		return year;
	}

	float getGPA() const {
		return GPA;
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
		{"WU Jiacheng","24127656A","B07A"},
		{"HUANG Haixiang","24037915A","B07A"},
		{"YIM Chun Hei","24004908A","B07A"}
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
	major[0] = toupper(major[0]);

	for (int i = 1; i < major.size(); i++) {
		if (major[i - 1] == ' ') {
			major[i] = toupper(major[i]);
		}
		if (major[i] >= 'A' && major[i] <= 'Z' && major[i - 1] != ' ') {
			major[i] = tolower(major[i]);
		}
	}
	return major;
}

void F1() {
	student_record_collection.clear();

	Student_record chan;
	chan.setRecord("CHAN Tai Man", "S243560", "Information Engineering", 1, 4.0);
	vector<vector<string>> chanSubjects = {
		{"ENG2042", "A"},
		{"ENG2219", "A"},
		{"LCH1302", "A"},
		{"LCH1019", "--"}
	};
	chan.setSubject_information(chanSubjects);
	chan.calculateGPA();
	student_record_collection.push_back(chan);

	Student_record cheung;
	cheung.setRecord("CHEUNG Jacky", "S232210", "Civil Engineering", 2, 2.48);
	vector<vector<string>> cheungSubjects = {
		{"ENG1113", "B"},
		{"ENG2250", "B+"},
		{"ENG2041", "F"},
		{"LCH1302", "A-"},
		{"LCH1019", "B"},
		{"BUS1021", "--"},
		{"ENG2042", "--"}
	};
	cheung.setSubject_information(cheungSubjects);
	cheung.calculateGPA();
	student_record_collection.push_back(cheung);

	Student_record pan;
	pan.setRecord("PAN Peter", "S222343", "Global Business", 3, 3.42);
	vector<vector<string>> panSubjects = {
		{"BUS1021", "A"},
		{"BUS2002", "A+"},
		{"BUS3006", "B-"},
		{"BUS4510", "A-"},
		{"BUS5523", "B+"},
		{"LCH1019", "C"}
	};
	pan.setSubject_information(panSubjects);
	pan.calculateGPA();
	student_record_collection.push_back(pan);

	Student_record wong;
	wong.setRecord("WONG Kam", "S244617", "Educational Psychology", 1, 2.86);
	vector<vector<string>> wongSubjects = {
		{"PSY1234", "C"},
		{"PSY2233", "B"},
		{"PSY2190", "B+"}
	};
	wong.setSubject_information(wongSubjects);
	wong.calculateGPA();
	student_record_collection.push_back(wong);

	cout << "Starting data loaded successfully!\n";
}



void F2() {
	int sortChoice;
	cout << "Choose sorting method:\n";
	menu_word_output(1, "Sort by Name (Ascending)");
	menu_word_output(2, "Sort by GPA (Descending)");
	cout << "Option (1-2): ";
	cin >> sortChoice;

	if (cin.fail() || (sortChoice != 1 && sortChoice != 2)) {
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Invalid choice. Returning to Main Menu.\n";
		return;
	}

	vector<Student_record> sortedStudents = student_record_collection;

	if (sortChoice == 1) {
		sort(sortedStudents.begin(), sortedStudents.end(), [](const Student_record& a, const Student_record& b) {
			return a.getName() < b.getName();
		});
	}
	else {
		sort(sortedStudents.begin(), sortedStudents.end(), [](const Student_record& a, const Student_record& b) {
			return a.getGPA() > b.getGPA();
		});
	}

	// Display table header
	cout << "\n" << left << setw(25) << "Student Name"
		<< setw(12) << "Student ID"
		<< setw(30) << "Major"
		<< setw(6) << "Year"
		<< "GPA\n";
	cout << string(75, '-') << endl;

	for (const auto& student : sortedStudents) {
		cout << left << setw(25) << student.getName()
			<< setw(12) << student.getS_ID()
			<< setw(30) << student.getMajor()
			<< setw(6) << student.getYear();

		float gpa = student.getGPA();
		if (gpa < 0.001) {
			cout << "N/A" << endl;
		}
		else {
			cout << fixed << setprecision(2) << gpa << endl;
		}
	}
	cout << endl;
}



void F3() {
	string student_id;
	bool exists = false;
	int index = -1;

	cout << "Enter Student ID: ";
	cin.ignore();
	getline(cin, student_id);
	student_id[0] = toupper(student_id[0]);
	// Check if student exists
	for (size_t i = 0; i < student_record_collection.size(); i++) {
		if (student_record_collection[i].getS_ID() == student_id) {
			exists = true;
			index = i;
			break;
		}
	}

	if (exists) {
		// Delete student process (unchanged)
		cout << "Student found:" << endl;
		student_record_collection[index].printData();
		cout << endl;

		char confirm;
		cout << "Confirm deletion (Yes/No): ";
		cin >> confirm;

		if (toupper(confirm) == 'Y') {
			student_record_collection.erase(student_record_collection.begin() + index);
			cout << "Student deleted successfully." << endl;
		}
		else {
			cout << "Deletion canceled." << endl;
		}
	}
	else {
		// Add student process
		string name, major, cohort_str;
		int cohort_num = 0;
		int retries = 0;
		bool valid = false;

		// Input name with retries
		while (retries < 3) {
			cout << "\nEnter student name (SURNAME First, max 30 chars): ";
			getline(cin, name);
			name = name_upper(name);
			if (!(name.empty()) && name.length() <= 30) {
				valid = true;
				break;
			}
			else {
				retries++;
				cout << "Invalid name. Attempts left: " << (3 - retries) << endl;
			}
		}
		if (!valid) {
			cout << "Too many invalid attempts. Operation canceled." << endl;
			return;
		}

		// Reset for cohort input
		valid = false;
		while (retries < 3) {
			cout << "Enter cohort year (21-24, e.g., 23 for 2023): ";
			getline(cin, cohort_str);
			if (cohort_str.size() == 2 && isdigit(cohort_str[0]) && isdigit(cohort_str[1])) {
				cohort_num = stoi(cohort_str);
				if (cohort_num >= 21 && cohort_num <= 24) {
					valid = true;
					break;
				}
			}
			retries++;
			cout << "Invalid cohort. Attempts left: " << (3 - retries) << endl;
		}
		if (!valid) {
			cout << "Too many invalid attempts. Operation canceled." << endl;
			return;
		}

		// Input major with retries
		valid = false;
		int major_choice;
		while (retries < 3) {
			cout << "Choose Major:\n";
			menu_word_output(1, "Information Engineering");
			menu_word_output(2, "Civil Engineering");  // Corrected typo
			menu_word_output(3, "Global Business");
			menu_word_output(4, "Educational Psychology");  // Corrected typo
			menu_word_output(5, "Add New Major");
			cout << "Option (1-5): ";
			cin >> major_choice;
			cin.ignore();

			switch (major_choice) {
			case 1: major = "Information Engineering"; break;
			case 2: major = "Civil Engineering"; break;  // Corrected
			case 3: major = "Global Business"; break;
			case 4: major = "Educational Psychology"; break;  // Corrected
			case 5:
				cout << "Enter new major (max 30 chars): ";
				getline(cin, major);
				major = major_upper(major);
				if (!(major.empty()) && major.length() <= 30) {
					major_collection.push_back(major);
				}
				else {
					retries++;
					cout << "Invalid major length. Attempts left: " << (3 - retries) << endl;
					continue;
				}
				break;
			default:
				retries++;
				cout << "Invalid choice. Attempts left: " << (3 - retries) << endl;
				continue;
			}
			valid = true;
			break;
		}
		if (!valid) {
			cout << "Too many invalid attempts. Operation canceled." << endl;
			return;
		}

		// Generate Student ID (existing code)
		srand(static_cast<unsigned int>(time(0)));
		int random_num = rand() % 1000;
		string random_str = to_string(random_num);
		while (random_str.length() < 3) random_str = "0" + random_str;
		string id_body = cohort_str + random_str;
		int sum = 0;
		for (char c : id_body) sum += c - '0';
		int check_digit = sum % 10;
		string generated_id = "S" + id_body + to_string(check_digit);

		// Calculate year (2025 is current year)
		int year = 2025 - (2000 + cohort_num); // Adjust based on current academic year

		// Create and add student
		Student_record new_student;
		new_student.setName(name);
		new_student.setMajor(major);
		new_student.setStudentID(generated_id);
		new_student.setYear(year);
		new_student.setGPA(0.0); // GPA calculated later
		student_record_collection.push_back(new_student);

		cout << "Student added successfully.  "<< name << "'s Student ID: " << generated_id << "  Year" <<year << endl;
	}
}

void copy_object_data(vector <Student_record> student_record_collection_oringinal) {
	// this function use to copy obejct vector
	for (int i = 0; i < student_record_collection.size(); i++) {
		student_record_collection_oringinal.push_back(student_record_collection[i]);
	}
}

void show_edited_information(string before, string current) {
	//int margin = abs(current.size() - before.size());
	cout << "Before" << setw(before.size() + 5) << "Current" << endl;
	copy_character("-", before.size(), 0);
	cout << setw(5);
	copy_character("-", current.size(), 1);
	cout << before << " -> " << current << endl;
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

bool returnMajor_information_collection_exist(string check) {
	for (int i = 0; i < major_collection.size(); i++) {
		if (major_collection[i] == check) {
			return true;
		}
	}
	return false;
}

bool returnExist(string check, vector <vector <string>>list, int position) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i][position] == check) {
			return true;
		}
	}
	return false;
}

void addCourse_information_collection(string code, string course_name, string credit) {
	course_information_collection.push_back({ code,course_name,credit });
}

bool subject_code_valid_check(string code) {
	int capital_letter = 0;
	int number_digits = 0;

	if (code.length() == 7) {
		for (int i = 0; i < 7; i++) {
			if (code[i] >= 'A' && code[i] <= 'Z' && i >= 0 && i <= 2) {
				capital_letter++;
			}
			if (code[i] >= '0' && code[i] <= '9' && i >= 3 && i <= 6) {
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

void show_all_vector_information(vector<vector <string>> element, int space) {
	for (int i = 0; i < element.size(); i++) {
		for (int j = 0; j < element[i].size(); j++) {
			cout << left << setw(space) << element[i][j];
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
	inputed_ID[0] = toupper(inputed_ID[0]);
	vector <Student_record> student_record_collection_oringinal;

	// check for whether the studentID exits or not
	for (int i = 0; i < student_record_collection.size(); i++) {
		if (inputed_ID == student_record_collection[i].getS_ID()) {
			valid_SID = true;
			direct_object_location = i;
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
				getline(cin, current_data);

				cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

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
				getline(cin, current_data);

				cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

				cin >> confirmation;
				cout << endl;

				if (confirmation == "Y" || confirmation == "y") {
					current_data = major_upper(current_data);
					if (returnMajor_information_collection_exist(current_data)) {
						student_record_collection[direct_object_location].setMajor(current_data);
						show_edited_information(previous_data, student_record_collection[direct_object_location].getMajor());
						cout << "The change is successfully." << endl;
					}
					else {
						menu_word_output(-1, "No such Major!");
					}
				}
				else if (confirmation == "N" || confirmation == "n") {
					cout << "The change is readly withdraw." << endl;
				}
				else {
					cout << "Invalid input!";
				}
				break;
			case '3':
				cout << "The current subject of student" << "(" << inputed_ID << ")" << " is :" << endl << endl;
				student_record_collection[direct_object_location].printSortedSubjects();
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
					if (student_record_collection[direct_object_location].returnSubject_information_exist(previous_data) != -1) {
						// 1st case
						cout << "Now you can change the student " << inputed_ID << "'s " << previous_data << "'s grade: " << endl;
						getline(cin, current_data); //grade value

						if (student_record_collection[direct_object_location].getSubject_grade(previous_data) != "--" && current_data == "--") {
							// can't change the grade condition
							menu_word_output(-1, "Sorry you can't change the value, bacause the subject's code is continuous.");
						}
						else {
							if (returnExist(current_data, grade_point_collection, 0)) {
								cout << "Do you confirm the change? Put Y or y for yes, put N or n for no: ";

								cin >> confirmation;
								cout << endl;

								if (confirmation == "Y" || confirmation == "y") {
									current_data = name_upper(current_data);
									student_record_collection[direct_object_location].changeSubject_information(previous_data, current_data, 1);
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
								menu_word_output(-1, "Invalid GPA Code");
							}
						}
					}
					else if (student_record_collection[direct_object_location].returnSubject_information_exist(previous_data) == -1 && returnExist(previous_data, course_information_collection, 0) == true) {
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

						if (temp >= "2" && temp <= "5") {
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
								if (returnExist(current_data, grade_point_collection, 0)) {
									student_record_collection[direct_object_location].addSubject_information(previous_data, current_data);

									cout << "The change is successfully." << endl;
								}
								else {
									menu_word_output(-1, "You enter invalid grade point!");
								}
							}
							else if (confirmation == "N" || confirmation == "n") {
								cout << "The change is readly withdraw." << endl;
							}
							else {
								cout << "Invalid input!";
							}
						}
						else {
							menu_word_output(-1, "You type invalid credit");
						}
					}
				}
				break;
			case '4':
				cout << "You are returing to the Main Menu." << endl;
				//loading_animation();
				break;
			case '5':
				show_all_vector_information(course_information_collection, 40);
				break;
			case '6':
				cout << "Grade" << "  " << "Point represent" << endl;
				show_all_vector_information(grade_point_collection, 10);
				break;
			default:
				cout << "No such function option " << option << endl;
				break;
			}
		} while (option != '4');
	}
	else {
		menu_word_output(-1, "No such student ID");
	}
}

void F5() {
	string sid;
	cout << "Enter Student ID: ";
	cin >> sid;
	sid[0] = toupper(sid[0]);
	cin.ignore();

	// 查找学生
	int index = -1;
	for (size_t i = 0; i < student_record_collection.size(); i++) {
		if (student_record_collection[i].getS_ID() == sid) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Student not found!\n";
		return;
	}

	Student_record s = student_record_collection[index];

	// 打印头部信息
	cout << "\nName: " << s.getName() << endl
		<< "Student ID: " << sid << endl
		<< "Major: " << s.getMajor() << endl
		<< "Year: " << s.getYear() << endl;

	// 打印排序后的科目
	s.printSortedSubjects();

	// 计算学分和GPA
	int credits = s.calculateCredits();
	float gpa = s.calculateGPA();

	cout << "Credits attained: " << credits << endl;
	if (gpa > 0.001) {
		cout << fixed << setprecision(2) << "GPA: " << gpa << endl;
	}
	else {
		cout << "GPA: N/A" << endl;
	}
}

void F6() {
	char confirm;
	do {
		cout << "Confirm exit (Y/N): ";
		cin >> confirm;
		cin.ignore();
	} while (toupper(confirm) != 'Y' && toupper(confirm) != 'N');
	if (toupper(confirm) == 'Y') {
		cout << "Group Members:\n";
		cout << "Name: John DOE, ID: S123456, Tutorial Group: A\n";
		cout << "Name: Jane SMITH, ID: S123457, Tutorial Group: A\n";
		exit(0);
	}
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

	show_all_vector_information(major_ouput, 30);
}

int main() {
	char prog_choice;
	bool loading_data = false;

	//loading_animation();

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
		cout << endl;
		//cout << "Option (1 - 7):" << endl;

		cout << "Enter function option number (1 - 7): ";
		cin >> prog_choice;
		cout << "\n\n";

		switch (prog_choice) {
		case '0': showInfo(); break;
		case '1':
			loading_data = true;
			F1(); break;
		case '2':
			if (loading_data == false) {
				menu_word_output(-1, "Data does not be loaded");
				menu_word_output(-1, "Please input 1 to load data");
				break;
			}
			F2();
			break;
		case '3':
			if (loading_data == false) {
				menu_word_output(-1, "Data does not be loaded");
				menu_word_output(-1, "Please input 1 to load data");
				break;
			}
			F3(); break;
		case '4':
			if (loading_data == false) {
				menu_word_output(-1, "Data does not be loaded");
				menu_word_output(-1, "Please input 1 to load data");
				break;
			}
			F4(); break;
		case '5':
			if (loading_data == false) {
				menu_word_output(-1, "Data does not be loaded");
				menu_word_output(-1, "Please input 1 to load data");
				break;
			}
			F5(); break;
		case '6':
			F6(); break;
		case '7':
			if (loading_data == false) {
				menu_word_output(-1, "Data does not be loaded");
				menu_word_output(-1, "Please input 1 to load data");
				break;
			}
			F7(); break;
		default:
			cout << "No such function option " << prog_choice << endl;
			break;
		}
	} while (true); //current condition is temporary ,the end loop statement will be designed by people who cope question 6

	cout << "The Student Management System terminates. Have a good day!  \v:)" << endl;
	return 0;
}