#include <iostream>
#include <string>

using namespace std;

struct Node {
    string task_name;
    string deadline;
    string result;
    int penalty;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void addTask(string task_name, string deadline, string result) {
    Node* newTask = new Node;
    newTask->task_name = task_name;
    newTask->deadline = deadline;
    newTask->result = result;
    newTask->penalty = 0;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
        tail = newTask;
        newTask->prev = NULL;
    }
    else {
        tail->next = newTask;
        newTask->prev = tail;
        tail = newTask;
    }
}

void printList() {
    Node* current = head;
    while (current != NULL) {
        cout << "Task: " << current->task_name << endl;
        cout << "Deadline: " << current->deadline << endl;
        cout << "Result: " << current->result << endl;
        if (current->penalty > 0) {
            cout << "Penalty: " << current->penalty << endl;
        }
        cout << endl;
        current = current->next;
    }
}

void calculatePenalties() {
    Node* current = head;
    while (current != NULL) {
        if (current->result != "completed") {
            int penalty = 0;
            if (current->deadline < "2023-04-20") {
                penalty = 30;
            }
            else if (current->deadline < "2023-04-25") {
                penalty = 10;
            }
            else if (current->deadline < "2023-04-30") {
                penalty = 20;
            }
            else {
                penalty = 40;
            }
            current->penalty = penalty;
        }
        current = current->next;
    }
}
void createUncompletedTasksList() {
    Node* current = head;
    Node* new_head = NULL;
    Node* new_tail = NULL;
    while (current != NULL) {
        if (current->result != "completed") {
            Node* new_node = new Node;
            new_node->task_name = current->task_name;
            new_node->result = current->result;
            new_node->penalty = current->penalty;
            new_node->next = NULL;
            if (new_head == NULL) {
                new_head = new_node;
                new_node->prev = NULL;
                new_tail = new_node;
            }
            else {
                new_tail->next = new_node;
                new_node->prev = new_tail;
                new_tail = new_node;
            }
        }
        current = current->next;
    }
    head = new_head;
}

int main() {
    addTask("Buy groceries", "2023-04-30", "completed");
    addTask("Finish project", "2023-04-25", "not completed");
    addTask("Pay bills", "2023-04-20", "not completed");

    cout << "Input list:" << endl;
    printList();

    calculatePenalties();

    createUncompletedTasksList();

    cout << "Output list:" << endl;
    printList();

    return 0;
}
