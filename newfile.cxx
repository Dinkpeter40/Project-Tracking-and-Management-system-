#include <iostream>
#include <fstream>  // For file handling
#include <string>   // For string usage

using namespace std;

// Maximum number of tasks we can store
const int MAX_TASKS = 50;

// Defines what a Task looks like
struct Task {
    string title;
    string description;
    string assignedTo;
    string dueDate;
    int progress; // 0 to 100
};

// Global variables 
Task tasks[MAX_TASKS];
int taskCount = 0;

// Function Prototypes (telling the compiler these functions exist)
void loadTasks();
void saveTasks();
void addTask();
void viewTasks();
void updateProgress();

int main() {
    // 1. Load existing tasks from file when program starts
    loadTasks();

    int choice;
    
    do {
        // Display Menu
        cout << "\n==============================\n";
        cout << "   TASK ASSIGNMENT MODULE\n";
        cout << "==============================\n";
        cout << "1. Add New Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Update Task Progress\n";
        cout << "4. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user choice
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                updateProgress();
                break;
            case 4:
                saveTasks();
                cout << "Tasks saved. Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

//definition function
// Adds a new task to the array
void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Error: Task list is full (Max 50).\n";
        return;
    }

    // Clear the input buffer so getline works correctly after 'cin'
    cin.ignore(); 

    cout << "\n--- Add New Task ---\n";
    
    cout << "Enter Task Title: ";
    getline(cin, tasks[taskCount].title);

    cout << "Enter Description: ";
    getline(cin, tasks[taskCount].description);

    cout << "Assigned To (Member Name): ";
    getline(cin, tasks[taskCount].assignedTo);

    cout << "Due Date (e.g., 2023-12-31): ";
    getline(cin, tasks[taskCount].dueDate);

    // New tasks start at 0% progress
    tasks[taskCount].progress = 0;

    // Increase the counter
    taskCount++;
    cout << "Task added successfully!\n";
}

// Displays all tasks in the array
void viewTasks() {
    if (taskCount == 0) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n--- Current Tasks ---\n";
    for (int i = 0; i < taskCount; i++) {
        cout << "ID: " << (i + 1) << endl; // Show 1-based index
        cout << "Title:       " << tasks[i].title << endl;
        cout << "Description: " << tasks[i].description << endl;
        cout << "Assigned To: " << tasks[i].assignedTo << endl;
        cout << "Due Date:    " << tasks[i].dueDate << endl;
        cout << "Progress:    " << tasks[i].progress << "%" << endl;
        cout << "------------------------\n";
    }
}

// Updates the progress percentage of a specific task
void updateProgress() {
    if (taskCount == 0) {
        cout << "\nNo tasks to update.\n";
        return;
    }

    // First show the list so user knows the ID
    viewTasks(); 

    int id;
    cout << "Enter the ID of the task to update: ";
    cin >> id;

    // Validate ID (User sees 1 to taskCount, array is 0 to taskCount-1)
    if (id < 1 || id > taskCount) {
        cout << "Invalid Task ID.\n";
        return;
    }

    int newProgress;
    cout << "Enter new progress (0-100): ";
    cin >> newProgress;

    // Validate percentage
    if (newProgress < 0 || newProgress > 100) {
        cout << "Invalid progress! Must be between 0 and 100.\n";
    } else {
        // Update the specific task in the array
        tasks[id - 1].progress = newProgress;
        cout << "Progress updated successfully!\n";
    }
}

// Saves all array data to "tasks.txt"
void saveTasks() {
    ofstream outFile("tasks.txt"); // Open file for writing

    if (outFile.is_open()) {
        // Write the total count first (optional, but helps with loops)
        // However, for this simple logic, we will just write the data directly.
        
        for (int i = 0; i < taskCount; i++) {
            outFile << tasks[i].title << endl;
            outFile << tasks[i].description << endl;
            outFile << tasks[i].assignedTo << endl;
            outFile << tasks[i].dueDate << endl;
            outFile << tasks[i].progress << endl;
        }
        outFile.close();
    } else {
        cout << "Error: Could not save to file.\n";
    }
}

// Loads data from "tasks.txt" into the array
void loadTasks() {
    ifstream inFile("tasks.txt"); // Open file for reading

    if (inFile.is_open()) {
        taskCount = 0; // Reset count
        
        // Loop while we can read a title and haven't filled the array
        // We use string temporary variables or read directly into struct
        while (taskCount < MAX_TASKS && getline(inFile, tasks[taskCount].title)) {
            
            getline(inFile, tasks[taskCount].description);
            getline(inFile, tasks[taskCount].assignedTo);
            getline(inFile, tasks[taskCount].dueDate);
            
            inFile >> tasks[taskCount].progress;
            
            // IMPORTANT: After reading an int (progress), the newline character 
            // remains in the buffer. We must ignore it before reading the 
            // next Task's title string.
            inFile.ignore(); 

            taskCount++;
        }
        inFile.close();
        cout << "Data loaded. " << taskCount << " tasks found.\n";
    } else {
        cout << "No saved file found. Starting with empty list.\n";
    }
}
