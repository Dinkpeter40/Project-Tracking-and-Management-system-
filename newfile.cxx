#include <iostream>
#include <fstream>

using namespace std;

const int MAX_TASKS = 50;

struct Task {
    string title;
    string description;
    string assignedTo;
    string dueDate;
    int progress;
};

Task tasks[MAX_TASKS];
int taskCount = 0;
void loadTasks();
void saveTasks();
void addTask();
void viewTasks();
void updateProgress();
void deleteTask();

int main() {

    loadTasks();

    int choice;

    do {
        cout << "\n==============================\n"<< "   TASK ASSIGNMENT MODULE\n";
        cout << "==============================\n";
        cout << "1. Add New Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Update Task Progress\n";
        cout << "4. Delete Task\n";        
        cout << "5. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
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
             case 4: deleteTask();
                break;    
            case 5:
                saveTasks();
                cout << "Tasks saved. Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Error: Task list is full (Max 50).\n";
        return;
    }

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

    tasks[taskCount].progress = 0;

    taskCount++;
    cout << "Task added successfully!\n";
}

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

void updateProgress() {
    if (taskCount == 0) {
        cout << "\nNo tasks to update.\n";
        return;
    }

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
    if (newProgress < 0 || newProgress > 100) {
        cout << "Invalid progress! Must be between 0 and 100.\n";
    } else {
        tasks[id - 1].progress = newProgress;
        cout << "Progress updated successfully!\n";
    }
}

void saveTasks() {
    ofstream outFile("tasks.txt");

    if (outFile.is_open()) {

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


void loadTasks() {
    fstream inFile("tasks.txt");
    if (inFile.is_open()) {
        taskCount = 0;
        while (taskCount < MAX_TASKS && getline(inFile, tasks[taskCount].title)) {

            getline(inFile, tasks[taskCount].description);
            getline(inFile, tasks[taskCount].assignedTo);
            getline(inFile, tasks[taskCount].dueDate);

            inFile >> tasks[taskCount].progress;

            inFile.ignore();

            taskCount++;
        }
        inFile.close();
        cout << "Data loaded. " << taskCount << " tasks found.\n";
    } else {
        cout << "No saved file found. Starting with empty list.\n";
    }
}
void deleteTask() {
    if (taskCount == 0) {
        cout << "\nNo tasks to delete.\n";
        return;
    }

    viewTasks();

    int id;
    cout << "Enter the ID of the task to delete: ";
    cin >> id;

    if (id < 1 || id > taskCount) {
        cout << "Invalid Task ID.\n";
        return;
    }

    for (int i = id - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    taskCount--;

    cout << "Task deleted successfully!\n";
}

