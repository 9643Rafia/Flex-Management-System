#include<iostream>
#include<string>
#include <iomanip>
#include<fstream>
#include<vector>
#include<sstream>
#include<exception>
#include "Header.h"

using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
}

void centerText(const string& text)
{
    int width = 80; // Adjust the width as needed
    int spaces = (width - text.length()) / 2;
    cout << setw(spaces + text.length()) << text << endl;
}

void displayMenuTitle(const string& title)
{
    clearScreen();
    cout << endl;
    centerText("===================================");
    centerText(title);
    centerText("===================================");
    cout << endl;
}

void displaySubMenuTitle(const string& title)
{
    cout << endl;
    centerText("------ " + title + " ------");
    cout << endl;
}

void displayMenuOptions(const vector<string>& options)
{
    cout << endl;
    for (size_t i = 0; i < options.size(); ++i)
    {
        cout << " " << i + 1 << ". " << options[i] << endl;
    }
}

int getUserChoice(const string& prompt, int minChoice, int maxChoice)
{
    int choice;
    while (true)
    {
        cout << endl << prompt;
        cin >> choice;
        if (choice >= minChoice && choice <= maxChoice)
        {
            return choice;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void pauseScreen()
{
    cout << endl << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main()
{
    int ch;

    clearScreen();
    displayMenuTitle("FLEX MANAGEMENT SYSTEM");

    cout << "1. Admin Mode" << endl;
    cout << "2. Student Mode" << endl;
    cout << "3. Teacher Mode" << endl;

    ch = getUserChoice("Enter your choice: ", 1, 3);

    if (ch == 1)
    {
        int choice;
        Administrator admin;

        do {
            displayMenuTitle("ADMIN MODE");
            displayMenuOptions({ "Sign in", "Add a new teacher", "Add a new student",
                "Edit a student", "Edit a teacher", "View all students", "View all teachers", "Exit" });

            choice = getUserChoice("Enter your choice: ", 1, 8);

            switch (choice)
            {
            case 1:
                displaySubMenuTitle("Sign in");
                admin.signIn();
                pauseScreen();
                break;
            case 2:
                displaySubMenuTitle("Add a new teacher");
                admin.addNewTeacher();
                pauseScreen();
                break;
            case 3:
                displaySubMenuTitle("Add a new student");
                admin.addNewStudent();
                pauseScreen();
                break;
            case 4:
                displaySubMenuTitle("Edit a student");
                admin.editStudent();
                pauseScreen();
                break;
            case 5:
                displaySubMenuTitle("Edit a teacher");
                admin.editTeacher();
                pauseScreen();
                break;
            case 6:
                displaySubMenuTitle("View all students");
                admin.viewAllStudents();
                pauseScreen();
                break;
            case 7:
                displaySubMenuTitle("View all teachers");
                admin.viewAllTeachers();
                pauseScreen();
                break;
            case 8:
                cout << "Exiting..." << endl;
                pauseScreen();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 8);
    }
    else if (ch == 2)
    {
        int choice;
        Student student;

        do {
            displayMenuTitle("STUDENT MODE");
            displayMenuOptions({ "Sign in", "View attendance", "View marks", "View grades",
                "View registered courses", "View fee status", "Exit" });

            choice = getUserChoice("Enter your choice: ", 1, 7);

            switch (choice)
            {
            case 1:
                displaySubMenuTitle("Sign in");
                student.signIn();
                pauseScreen();
                break;
            case 2:
                displaySubMenuTitle("View attendance");
                student.viewAttendance();
                pauseScreen();
                break;
            case 3:
                displaySubMenuTitle("View marks");
                student.viewMarks();
                pauseScreen();
                break;
            case 4:
                displaySubMenuTitle("View grades");
                student.viewGrades();
                pauseScreen();
                break;
            case 5:
                displaySubMenuTitle("View registered courses");
                student.viewRegisteredCourses();
                pauseScreen();
                break;
            case 6:
                displaySubMenuTitle("View fee status");
                student.viewFeeStatus();
                pauseScreen();
                break;
            case 7:
                cout << "Exiting..." << endl;
                pauseScreen();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 7);
    }
    else if (ch == 3)
    {
        int choice;
        Teacher teacher;

        do {
            displayMenuTitle("TEACHER MODE");
            displayMenuOptions({ "Sign in", "Display timetable", "Mark attendance",
                "Assign marks", "Assign grades", "Exit" });

            choice = getUserChoice("Enter your choice: ", 1, 6);

            switch (choice)
            {
            case 1:
                displaySubMenuTitle("Sign in");
                teacher.signIn();
                pauseScreen();
                break;
            case 2:
                displaySubMenuTitle("Display timetable");
                teacher.displayTimeTable();
                pauseScreen();
                break;
            case 3:
                displaySubMenuTitle("Mark attendance");
                teacher.markAttendance();
                pauseScreen();
                break;
            case 4:
                displaySubMenuTitle("Assign marks");
                teacher.assignMarks();
                pauseScreen();
                break;
            case 5:
                displaySubMenuTitle("Assign grades");
                teacher.assignGrades();
                pauseScreen();
                break;
            case 6:
                cout << "Exiting..." << endl;
                pauseScreen();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 6);
    }
    else
    {
        cout << "Invalid choice!" << endl;
        pauseScreen();
    }

    return 0;
}
