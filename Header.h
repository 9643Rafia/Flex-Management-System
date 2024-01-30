#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<exception>

//Parent Class
class User
{
public:
	virtual bool signIn() = 0;
	virtual void addNewTeacher() = 0;
	virtual void addNewStudent() = 0;
	virtual void editStudent() = 0;
	virtual void editTeacher() = 0;
	virtual void viewAllStudents() = 0;
	virtual void viewAllTeachers() = 0;
};

//administrator class
class Administrator :public User
{
private:
	std::string username;
	std::string password;
	double salary;
	std::string TiD;

	std::string firstName;
	std::string lastName;
	std::string department;
	std::string registrationDate;
	std::string address;
	std::string qualification;

	std::string bloodGroup;
	std::string feeStatus;
	double marks;
	std::string SiD;

	char gender;
	int contactNo;
public:

	Administrator() :username("admin"), password("admin") {}

	bool signIn() override;

	void saveTeacherToFile(Administrator& teacher);
	std::string generateTiD(const std::string& department);
	friend std::ofstream& operator<<(std::ofstream& ofs, Administrator& teacher)
	{
		ofs << teacher.TiD << '\n';
		ofs << teacher.firstName << '\n';
		ofs << teacher.lastName << '\n';
		ofs << teacher.department << '\n';
		ofs << teacher.username << '\n';
		ofs << teacher.password << '\n';
		ofs << teacher.registrationDate << '\n';
		ofs << teacher.gender << '\n';
		ofs << teacher.contactNo << '\n';
		ofs << teacher.qualification << '\n';
		ofs << teacher.address << '\n';
		return ofs;
	}
	void addNewTeacher() override;

	void saveStudentToFile(const Administrator& student);
	std::string generateSiD(const std::string& department);

	friend std::ofstream& operator<< (std::ofstream& os, const Administrator& student)
	{
		os << student.SiD << '\n';
		os << student.firstName << '\n';
		os << student.lastName << '\n';
		os << student.department << '\n';
		os << student.registrationDate << '\n';
		os << student.gender << '\n';
		os << student.contactNo << '\n';
		os << student.bloodGroup << '\n';
		os << student.address << '\n';
		os << student.feeStatus << '\n';
		os << student.qualification << '\n';
		os << student.marks << '\n';

		return os;
	}
	void addNewStudent() override;
	std::string join(const std::vector<std::string>& items, std::string delimiter);

	void editStudent() override;
	void editTeacher() override;

	void viewAllStudents() override;
	void viewAllTeachers() override;

	void displayStudents(const std::vector<std::vector<std::string>>& students);
	void displayTeachers(const std::vector<std::vector<std::string>>& teacher);
};

class Student
{
private:
	std::string username;
	std::string password;
	std::string firstName;
	std::string lastName;
	std::string SiD;
	std::string courseId;
	std::string courseName;

public:

	Student() {}
	Student(std::string username, std::string password) :
		username(username), password(password) {}

	bool signIn();
	void displayAttendance(const std::vector<std::vector<std::string>>& attendanceRecords);
	void viewAttendance();
	void displayMarks(const std::vector<std::vector<std::string>>& marksRecords);
	void viewMarks();
	void displayGrades(const std::vector<std::vector<std::string>>& gradeRecords);
	void viewGrades();
	void viewRegisteredCourses();
	void viewFeeStatus();
};

class Teacher
{
private:
	std::string username;
	std::string password;
public:
	Teacher() {}
	Teacher(std::string username, std::string password) :
		username(username), password(password) {}
	bool signIn();
	void displayTimeTable();
	void assignMarks();
	void markAttendance();
	void assignGrades();
};
