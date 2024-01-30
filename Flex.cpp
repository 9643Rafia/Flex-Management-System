#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<exception>
#include "Header.h"

using namespace std;

bool Administrator::signIn()
{
	while (true)
	{
		try
		{
			string inputUsername, inputPassword;
			std::cout << "\n\nADMIN SIGN IN" << endl;
			std::cout << "Username: ";
			std::cin >> inputUsername;
			std::cout << "Password: ";
			std::cin >> inputPassword;

			if (inputUsername != username && inputPassword != password)
			{
				throw runtime_error("Log-in failed");
			}

			std::cout << "Successfull sign-in";
			return true;
			break;
		}
		catch (runtime_error& e)
		{
			std::cout << e.what() << endl;
		}

	}
}

void Administrator::saveTeacherToFile(Administrator& teacher)
{
	ofstream TeacherFile("Teacher.txt", ios::app);
	if (TeacherFile.is_open())
	{
		TeacherFile << teacher; // Using the operator overloading
		std::cout << "Teacher added successfully!" << endl;
		TeacherFile.close();
	}
	else
	{
		std::cout << "Error: File could not be opened." << endl;
	}
}
string Administrator::generateTiD(const string& department)
{
	static int count = 0;
	string tid;
	string prefix;

	if (department == "Computer Science")
		prefix = "CS";
	else if (department == "Electric Engineer")
		prefix = "EE";
	else if (department == "Software Engineer")
		prefix = "SE";
	else if (department == "Business")
		prefix = "BBA";
	else if (department == "Social Sciences")
		prefix = "SS";

	tid = prefix + "-" + to_string(count++);

	return tid;
}

void Administrator::addNewTeacher()
{
	Administrator teach;
	std::cout << "Adding new teacher" << endl;

	std::cout << "First Name: ";
	std::cin >> teach.firstName;

	std::cout << "Last Name: ";
	std::cin >> teach.lastName;

	std::cout << "Department Name: ";
	std::cin >> teach.department;

	teach.TiD = generateTiD(department);

	std::cout << "Username: ";
	std::cin >> teach.username;

	std::cout << "Password: ";
	std::cin >> teach.password;

	std::cout << "Registration Date: ";
	std::cin >> teach.registrationDate;

	std::cout << "Gender: ";
	std::cin >> teach.gender;

	std::cout << "Contact Number: ";
	std::cin >> teach.contactNo;

	std::cout << "Qualification: ";
	std::cin >> teach.qualification;

	std::cout << "Address: ";
	std::cin >> teach.address;

	saveTeacherToFile(teach);
}

void Administrator::saveStudentToFile(const Administrator& student)
{
	ofstream studentFile("Student.txt", ios::app);
	if (studentFile.is_open())
	{
		studentFile << student;
		std::cout << "Student added successfully!" << std::endl;
		studentFile.close();
	}
	else
	{
		std::cout << "Error: File could not be opened." << std::endl;
	}
}

string Administrator::generateSiD(const string& department)
{
	static int studentCount = 1;
	string prefix;
	string sid;

	if (department == "Computer Science")
		prefix = "CS";
	else if (department == "Electric Engineer")
		prefix = "EE";
	else if (department == "Software Engineer")
		prefix = "SE";
	else if (department == "Business")
		prefix = "BBA";
	else if (department == "Social Sciences")
		prefix = "SS";

	sid = prefix + "-" + to_string(studentCount++);

	return sid;
}


void Administrator::addNewStudent()
{
	Administrator ad;
	std::cout << "\n\nAdding new Student" << endl;

	std::cout << "First Name: ";
	std::cin >> ad.firstName;

	std::cout << "Last Name: ";
	std::cin >> ad.lastName;

	std::cout << "Department Name: ";
	std::cin >> ad.department;

	ad.SiD = generateSiD(department);

	std::cout << "Registration Date: ";
	std::cin >> ad.registrationDate;

	std::cout << "Gender: ";
	std::cin >> ad.gender;

	std::cout << "Contact Number: ";
	std::cin >> ad.contactNo;

	std::cout << "Blood Group: ";
	std::cin >> ad.bloodGroup;

	std::cout << "Address: ";
	std::cin >> ad.address;

	std::cout << "Fee Status: ";
	std::cin >> ad.feeStatus;

	std::cout << "Qualification: ";
	std::cin >> ad.qualification;

	std::cout << "Marks: ";
	std::cin >> ad.marks;

	saveStudentToFile(ad);
}


string Administrator::join(const vector<string>& items, string delimiter)
{
	string results;
	for (int i = 0; i < items.size(); ++i)
	{
		results += items[i];
		if (i < items.size() - 1)
		{
			results += delimiter;
		}
	}

	return results;
}

void Administrator::editStudent()
{
	ifstream stFile("Student.txt");
	int rollNum;

	if (stFile.is_open())
	{
		string line;
		vector<string>students;

		while (getline(stFile, line))
		{
			students.push_back(line);
		}

		stFile.close();

		if (students.empty())
		{
			std::cout << "Sorry! no student records found" << endl;
			return;
		}

		std::cout << "\n\nLIST OF STUDENTS" << endl;
		for (int i = 0; i < students.size(); ++i)
		{
			std::cout << (i + 1) << ") " << students[i] << endl;
		}

		std::cout << "Enter roll number of student: ";
		std::cin >> rollNum;

		if (rollNum >= 1 && rollNum <= static_cast<int>(students.size()))
		{
			int index = rollNum - 1;
			stringstream ss(students[index]);
			vector<string>studentInfo;
			string item;

			while (getline(ss, item, ' '))
			{
				studentInfo.push_back(item);
			}
			firstName = studentInfo[1];
			lastName = studentInfo[2];
			feeStatus = studentInfo[3];
			address = studentInfo[4];
			contactNo = stoi(studentInfo[5]);

			std::cout << "Update the details: " << endl;

			std::cout << "First Name: ";
			std::cin >> firstName;

			std::cout << "Last Name: ";
			std::cin >> lastName;

			std::cout << "Fee Status: ";
			std::cin >> feeStatus;

			std::cout << "Address: ";
			std::cin >> address;

			std::cout << "Contact Number: ";
			std::cin >> contactNo;

			students[index] = join(studentInfo, " ");

			ofstream file("Students.txt");

			if (file.is_open())
			{
				for (const auto& student : students)
				{
					file << student << endl;
				}
				file.close();
				std::cout << "Student information updated successfully" << endl;
			}
			else
				std::cout << "Error:File could not be opened!" << endl;
		}
		else
			std::cout << "Error:Roll Number out of bounds!" << endl;
	}
	else
		std::cout << "Error:File could not be opened!" << endl;
}


void Administrator::editTeacher()
{
	ifstream tFile("Teacher.txt");
	int tID;

	if (tFile.is_open())
	{
		string line;
		vector<string>teacher;

		while (getline(tFile, line))
		{
			teacher.push_back(line);
		}

		tFile.close();

		if (teacher.empty())
		{
			std::cout << "Sorry! no teacher records found" << endl;
			return;
		}

		std::cout << "\n\nLIST OF TEACHERS" << endl;
		for (int i = 0; i < teacher.size(); ++i)
		{
			std::cout << (i + 1) << ") " << teacher[i] << endl;
		}

		std::cout << "Enter roll number of student: ";
		std::cin >> tID;

		if (tID >= 1 && tID <= static_cast<int>(teacher.size()))
		{
			int index = tID - 1;
			stringstream ss(teacher[index]);
			vector<string>teacherInfo;
			string item;

			while (getline(ss, item, ' '))
			{
				teacherInfo.push_back(item);
			}

			address = teacherInfo[8];
			contactNo = stoi(teacherInfo[7]);
			qualification = teacherInfo[9];
			salary = stoi(teacherInfo[10]);

			std::cout << "Update the details: " << endl;

			std::cout << "Address: ";
			std::cin >> address;

			std::cout << "Contact Number: ";
			std::cin >> contactNo;

			std::cout << "Qualification: ";
			std::cin >> qualification;

			std::cout << "Salary: ";
			std::cin >> salary;

			teacher[index] = join(teacherInfo, ",");

			ofstream file("Students.txt");

			if (file.is_open())
			{
				for (const auto& teacher : teacher)
				{
					file << teacher << endl;
				}
				file.close();
				std::cout << "Teacher information updated successfully" << endl;
			}
			else
				std::cout << "Error:File could not be opened!" << endl;
		}
		else
			std::cout << "Error:Teacher ID number out of bounds!" << endl;
	}
	else
		std::cout << "Error:File could not be opened!" << endl;
}

void Administrator::displayStudents(const vector<vector<string>>& students)
{
	std::cout << "-----------------------------------------------------------------\n";
	std::cout << "| Student ID |   Name   | Department | Fee Status |  Qualification  |\n";
	std::cout << "-----------------------------------------------------------------\n";

	for (const auto& studentInfo : students)
	{
		if (studentInfo.size() >= 5)
		{
			std::cout << "| " << studentInfo[0] << " | " << studentInfo[1] << " " << studentInfo[2]
				<< " | " << studentInfo[3] << " | " << studentInfo[9] << " | "
				<< studentInfo[10] << " |\n";
		}

	}
	std::cout << "-----------------------------------------------------------------\n";
}

void Administrator::displayTeachers(const vector<vector<string>>& teacher)
{
	std::cout << "-----------------------------------------------------\n";
	std::cout << "|     Name    | Gender | Qualification | Contact No | Username |\n";
	std::cout << "-----------------------------------------------------\n";

	for (const auto& teacherInfo : teacher)
	{
		if (teacherInfo.size() >= 9)
		{
			std::cout << "| " << teacherInfo[1] << " " << teacherInfo[2]
				<< " | " << teacherInfo[7] << " | " << teacherInfo[9]
				<< " | " << teacherInfo[8] << " | " << teacherInfo[4] << " |\n";
		}
	}

	std::cout << "-----------------------------------------------------\n";
}

void Administrator::viewAllStudents()
{
	ifstream file("Student.txt");
	if (file.is_open()) {
		string line;
		vector<vector<string>> students;
		vector<string> studentInfo;

		while (getline(file, line))
		{
			if (!line.empty())
			{
				studentInfo.push_back(line);
			}
			else
			{
				students.push_back(studentInfo);
				studentInfo.clear();
			}

		}
		if (!studentInfo.empty())
			students.push_back(studentInfo);

		file.close();

		if (students.empty())
		{
			std::cout << "Sorry! no student records found" << endl;
			return;
		}
		std::cout << "STUDENT LIST: " << endl;
		displayStudents(students);
	}
	else
	{
		std::cout << "Error:File could not be opened" << endl;
	}
}

void Administrator::viewAllTeachers()
{
	ifstream file("Teacher.txt", ios::app);

	if (file.is_open())
	{
		string line;
		vector<vector<string>> teacher;
		vector<string> teacherInfo;

		while (getline(file, line))
		{
			if (!line.empty())
				teacherInfo.push_back(line);
			else
			{
				teacher.push_back(teacherInfo);
				teacherInfo.clear();
			}
		}

		if (!teacherInfo.empty())
			teacher.push_back(teacherInfo);

		file.close();

		if (teacher.empty())
		{
			std::cout << "Sorry! no student records found" << endl;
			return;
		}
		std::cout << "TEACHER LIST: " << endl;
		displayTeachers(teacher);
	}
	else
	{
		std::cout << "Error:File could not be opened" << endl;
	}

}

bool Student::signIn()
{
	std::vector<Student>Credentials;
	std::ifstream file("readme.txt");

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::string username, password;
			std::istringstream iss(line);

			if (iss >> username >> password)
			{
				Student student;
				student.username = username;
				student.password = password;
				Credentials.push_back(student);
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Error: Unable to open the readme file.\n";
		return 1;
	}

	string inputUsername, inputPassword;
	std::cout << "\n\nSTUDENT SIGN IN" << endl;
	std::cout << "Username: ";
	std::cin >> inputUsername;
	std::cout << "Password: ";
	std::cin >> inputPassword;

	bool found = false;

	for (const auto& student : Credentials)
	{
		if (student.username == inputUsername)
		{
			found = true;
			if (student.password == inputPassword)
			{
				std::cout << "Sign in successful!\n";
				return true;
			}
			else
				std::cout << "Invalid password. Sign in failed.\n";
			break;
		}
	}
	if (!found)
	{
		cout << "Invalid username and password.";
		return false;
	}
}

void Student::displayAttendance(const vector<vector<string>>& attendanceRecords)
{
	std::cout << "---------------------------------------\n";
	std::cout << "|  Status  |   Date   |    Day    |\n";
	std::cout << "---------------------------------------\n";

	for (const auto& recordInfo : attendanceRecords)
	{
		if (recordInfo[0] == SiD)
		{
			std::cout << "|   " << recordInfo[2] << "   | "
				<< recordInfo[3] << " | "
				<< recordInfo[4] << " |\n";
		}
	}

	std::cout << "---------------------------------------\n";
}

void Student::viewAttendance()
{
	ifstream file("Attendance.txt");
	if (file.is_open())
	{
		string line;
		vector<vector<string>> attendanceRecords;

		while (getline(file, line))
		{
			vector<string> recordInfo;
			stringstream ss(line);
			string item;

			while (getline(ss, item, ' '))
			{
				recordInfo.push_back(item);
			}

			attendanceRecords.push_back(recordInfo);
		}

		file.close();

		if (attendanceRecords.empty())
		{
			std::cout << "Sorry. No attendance records found" << endl;
			return;
		}
		std::cout << "ATTENDANCE RECORDS\n";
		displayAttendance(attendanceRecords);
	}
	else
	{
		std::cout << "Error:File could not be opened\n";
	}
}

void Student::displayMarks(const vector<vector<string>>& marksRecords)
{
	std::cout << "---------------------------------------\n";
	std::cout << "|  Course Code  |   Course Name   |    Marks    |\n";
	std::cout << "---------------------------------------\n";

	for (const auto& recordInfo : marksRecords)
	{
		if (recordInfo[0] == SiD)
		{
			std::cout << "|   " << recordInfo[2] << "   | "
				<< recordInfo[3] << " | "
				<< recordInfo[4] << " |\n";
		}
	}

	std::cout << "---------------------------------------\n";
}

void Student::viewMarks()
{
	ifstream file("Marks.txt");
	if (file.is_open())
	{
		string line;
		vector<vector<string>> marksRecords;

		while (getline(file, line))
		{
			vector<string> recordInfo;
			stringstream ss(line);
			string item;

			while (getline(ss, item, ' '))
			{
				recordInfo.push_back(item);
			}

			marksRecords.push_back(recordInfo);
		}

		file.close();

		if (marksRecords.empty())
		{
			std::cout << "Sorry! no marks records found!\n";
			return;
		}
		std::cout << "Marks Records:\n";
		displayMarks(marksRecords);
	}
	else
	{
		std::cout << "Error:File could not be opened\n";
	}
}

void Student::displayGrades(const vector<vector<string>>& gradeRecords)
{
	std::cout << "-------------------------------------\n";
	std::cout << "| Course Name |     Grade     |\n";
	std::cout << "-------------------------------------\n";

	for (const auto& recordInfo : gradeRecords)
	{
		if (recordInfo[0] == SiD)
		{
			std::cout << "| " << recordInfo[1] << " | "
				<< recordInfo[2] << " |\n";
		}
	}

	std::cout << "-------------------------------------\n";
}

void Student::viewGrades()
{
	ifstream file("Grades.txt");
	if (file.is_open())
	{
		string line;
		vector<vector<string>> gradeRecords;

		while (getline(file, line))
		{
			vector<string> recordInfo;
			stringstream ss(line);
			string item;

			while (getline(ss, item, ' '))
			{
				recordInfo.push_back(item);
			}
			gradeRecords.push_back(recordInfo);
		}

		file.close();

		if (gradeRecords.empty())
		{
			std::cout << "No grade records found.\n";
			return;
		}
		std::cout << "Grade Records:\n";
		displayGrades(gradeRecords);
	}
	else
	{
		std::cout << "Error: Unable to open the file.\n";
	}
}

void Student::viewRegisteredCourses()
{
	ifstream file("RegisteredCourses.txt");
	if (file.is_open())
	{
		string line;
		vector<string> registeredCourses;

		while (getline(file, line))
		{
			istringstream iss(line);
			if (iss >> courseId >> courseName && courseId == SiD)
			{
				registeredCourses.push_back(courseName);
			}
		}
		file.close();

		if (registeredCourses.empty())
		{
			std::cout << "Sorry no record of registered courses found!\n";
			return;
		}

		std::cout << "REGISTERED COURSES\n";
		for (const string& course : registeredCourses)
		{
			std::cout << course << "\n";
		}
	}
	else
	{
		std::cout << "Error:File could not be opened\n";
	}
}

void Student::viewFeeStatus()
{
	vector<string>feeStatus;
	ifstream file("FeeStatus.txt");
	if (file.is_open())
	{
		string line;

		while (getline(file, line))
		{
			feeStatus.push_back(line);
		}

		file.close();

		if (feeStatus.empty())
		{
			std::cout << "Sorry no record of fee status found!\n";
			return;
		}
		std::cout << "FEE STATUS:\n";
		for (const string& record : feeStatus)
		{
			std::cout << record << "\n";
		}
	}
	else
	{
		std::cout << "Error:File could not be opened\n";
	}
}

bool Teacher::signIn()
{
	std::vector<Teacher>Credentials;
	std::ifstream file("readme.txt");

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::string username, password;
			std::istringstream iss(line);

			if (iss >> username >> password)
			{
				Teacher teacher;
				teacher.username = username;
				teacher.password = password;
				Credentials.push_back(teacher);
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Error: Unable to open the readme file.\n";
		return 1;
	}

	string inputUsername, inputPassword;
	std::cout << "\n\nTEACHER SIGN IN" << endl;
	std::cout << "Username: ";
	std::cin >> inputUsername;
	std::cout << "Password: ";
	std::cin >> inputPassword;

	bool found = false;

	for (const auto& teacher : Credentials)
	{
		if (teacher.username == inputUsername)
		{
			found = true;
			if (teacher.password == inputPassword)
				std::cout << "Sign in successful!\n";
			else
				std::cout << "Invalid password. Sign in failed.\n";
			break;
		}
	}
	if (!found)
	{
		cout << "Invalid username and password.";
	}
}

void Teacher::displayTimeTable()
{
	std::cout << "Time Table:\n";
	std::cout << "Monday: Algebra (9:00-11:00), Geometry (12:00-2:00)\n";
	std::cout << "Wednesday: Calculus (9:00-11:00), Statistics (12:00-2:00)\n";
	std::cout << "Friday: Trigonometry (9:00-11:00), Differential Equations (12:00-2:00)\n";
}
void Teacher::assignMarks()
{
	string studentId;
	string subject;
	double marks;

	std::cout << "Assign Marks\n";
	std::cout << "Enter Student ID: ";
	std::cin >> studentId;
	std::cout << "Enter Subject: ";
	std::cin >> subject;
	std::cout << "Enter Marks: ";
	std::cin >> marks;

	ofstream file("Marks.txt", std::ios::app);
	if (file.is_open())
	{
		file << studentId << "\n";
		file << subject << "\n";
		file << marks << "\n";
		std::cout << "Student marks assigned successfully!" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Error: File could not be opened." << std::endl;
	}
}

void Teacher::markAttendance()
{
	string studentId;
	string subject;
	string attendanceStatus;

	std::cout << "Mark Attendance\n";
	std::cout << "Enter Student ID: ";
	std::cin >> studentId;
	std::cout << "Enter Subject: ";
	std::cin >> subject;
	std::cout << "Enter Attendance Status (P/A): ";
	std::cin >> attendanceStatus;

	ofstream file("Attendance.txt", std::ios::app);
	if (file.is_open())
	{
		file << studentId << "\n";
		file << subject << "\n";
		file << attendanceStatus << "\n";
		std::cout << "Student attendance marked successfully!" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Error: File could not be opened." << std::endl;
	}
}

void Teacher::assignGrades()
{
	string studentId;
	string Grade;
	string subject;

	std::cout << "Assign Grades\n";
	std::cout << "Enter Student ID: ";
	std::cin >> studentId;
	std::cout << "Enter Subject: ";
	std::cin >> subject;
	std::cout << "Enter Grade: ";
	std::cin >> Grade;

	ofstream file("Grades.txt", std::ios::app);
	if (file.is_open())
	{
		file << studentId << "\n";
		file << subject << "\n";
		file << Grade << "\n";
		std::cout << "Student grades marked successfully!" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Error: File could not be opened." << std::endl;
	}
}
