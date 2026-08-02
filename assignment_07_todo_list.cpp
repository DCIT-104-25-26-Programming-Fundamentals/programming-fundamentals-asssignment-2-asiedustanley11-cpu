// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Prints the main menu.
void showMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}
 
// Prompts the user for a task description and adds it to the tasks vector.
// "tasks" is passed by reference (&) so this function modifies the
// original vector in main(), not a copy of it.
void addTask(vector<string>& tasks) {
    cout << "Enter task: ";
    string description;
    getline(cin, description);
 
    if (description.empty()) {
        cout << "Task cannot be empty. Nothing was added." << endl;
        return;
    }
 
    tasks.push_back(description);
    cout << "Task added: \"" << description << "\"" << endl;
}
 
// Displays all tasks, numbered starting at 1. If there are no tasks,
// prints a friendly message instead.
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty. Add a task to get started!" << endl;
        return;
    }
 
    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}
 
// Shows the current tasks, asks which one to delete by number, and
// removes it. Prints an error message if the number is invalid.
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your task list is empty. Nothing to delete." << endl;
        return;
    }
 
    viewTasks(tasks);
 
    cout << "Enter task number to delete: ";
    int taskNumber;
    cin >> taskNumber;
    cin.ignore(); // discard the leftover newline so future getline() calls work
 
    if (cin.fail()) {
        cout << "Please enter a valid task number." << endl;
        cin.clear();
        cin.ignore(10000, '\n'); // clear the bad input from the buffer
        return;
    }
 
    // Task numbers shown to the user start at 1, but vector positions
    // (indices) start at 0, so we subtract 1 to find the right item.
    int index = taskNumber - 1;
 
    if (index < 0 || index >= static_cast<int>(tasks.size())) {
        cout << "Error: that task number does not exist." << endl;
        return;
    }
 
    string removedTask = tasks[index];
    tasks.erase(tasks.begin() + index);
    cout << "Task \"" << removedTask << "\" has been removed." << endl;
}
 
int main() {
    vector<string> tasks; // dynamic list that stores all task descriptions
 
    // Keep showing the menu until the user chooses to quit.
    while (true) {
        showMenu();
        cout << "Enter your choice (1-4): ";
 
        int choice;
        cin >> choice;
        cin.ignore(); // discard the leftover newline before any getline() calls
 
        if (cin.fail()) {
            cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
            cin.clear();
            cin.ignore(10000, '\n'); // clear the bad input from the buffer
            cout << endl;
            continue;
        }
 
        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break; // exits the while loop, ending the program
        } else {
            cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
 
        cout << endl; // blank line for readability before the menu repeats
    }
 
    return 0;
}