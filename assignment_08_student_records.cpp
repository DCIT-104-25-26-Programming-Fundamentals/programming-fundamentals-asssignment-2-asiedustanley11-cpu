// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// A struct groups related data together under one name, similar to a
// Python dictionary but with fixed, named fields declared up front.
struct Student {
    string name;
    int id;
    vector<double> scores;
};
 
// Prints the main menu.
void showMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}
 
// Returns the average of a list of scores. Returns 0 if the list is
// empty (avoids dividing by zero).
double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }
 
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}
 
// Prompts the user for a student's name, ID, and scores, then adds the
// new Student record to the students vector.
void addStudent(vector<Student>& students) {
    Student newStudent;
 
    cout << "Student name: ";
    getline(cin, newStudent.name);
 
    cout << "Student ID: ";
    cin >> newStudent.id;
    if (cin.fail()) {
        cout << "Invalid ID. Student was not added." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
 
    cout << "How many scores? ";
    int numScores;
    cin >> numScores;
    if (cin.fail() || numScores < 0) {
        cout << "Invalid number of scores. Student was not added." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
 
    for (int i = 1; i <= numScores; i++) {
        cout << "Enter score " << i << ": ";
        double score;
        cin >> score;
        if (cin.fail()) {
            cout << "Invalid score entered. Student was not added." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }
        newStudent.scores.push_back(score);
    }
 
    cin.ignore(); // discard leftover newline before any future getline() calls
 
    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}
 
// Prints a formatted table of all students: name, ID, scores, and
// average score.
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }
 
    cout << string(50, '-') << endl;
    cout << left << setw(15) << "Name"
         << setw(12) << "ID"
         << setw(18) << "Scores"
         << "Average" << endl;
    cout << string(50, '-') << endl;
 
    for (const Student& student : students) {
        // Build the "78, 85, 90" style scores string.
        string scoresText;
        for (size_t i = 0; i < student.scores.size(); i++) {
            if (i != 0) {
                scoresText += ", ";
            }
            scoresText += to_string(static_cast<int>(student.scores[i]));
        }
 
        double average = calculateAverage(student.scores);
 
        cout << left << setw(15) << student.name
             << setw(12) << student.id
             << setw(18) << scoresText
             << fixed << setprecision(2) << average << endl;
    }
 
    cout << string(50, '-') << endl;
}
 
// Searches the students vector for a record matching the given ID.
// Returns a pointer to the matching Student, or nullptr if not found.
Student* findStudentById(vector<Student>& students, int studentId) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == studentId) {
            return &students[i];
        }
    }
    return nullptr;
}
 
// Asks for a student ID, looks up that student, and prints their
// average score. Prints an error message if the ID is not found.
void showAverageForStudent(vector<Student>& students) {
    cout << "Enter student ID: ";
    int studentId;
    cin >> studentId;
 
    if (cin.fail()) {
        cout << "Invalid ID format." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
 
    Student* student = findStudentById(students, studentId);
 
    if (student == nullptr) {
        cout << "Error: no student found with ID " << studentId << "." << endl;
        return;
    }
 
    double average = calculateAverage(student->scores);
    cout << student->name << "'s average score: "
         << fixed << setprecision(2) << average << endl;
}
 
int main() {
    vector<Student> students; // dynamic list of all student records
 
    while (true) {
        showMenu();
        cout << "Enter your choice (1-4): ";
 
        int choice;
        cin >> choice;
 
        if (cin.fail()) {
            cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout << endl;
            continue;
        }
 
        if (choice == 1) {
            cin.ignore(); // discard leftover newline before getline() in addStudent
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            showAverageForStudent(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
 
        cout << endl;
    }
 
    return 0;
}