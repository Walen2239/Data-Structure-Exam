#include <iostream>
#include <string>
#include <limits>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;


// sll queue
class Node {
    public:
        int ID;
        string Name;
        int Age;
        Node* next;
    };
    
    class SLL {
    public:
        Node* head;
        Node* tail;
        Node* current;
    
        // 1. Initialize
        SLL() : head(nullptr), tail(nullptr), current(nullptr) {}
    
        // 2. ENQUEUE (Add to front)
        void Queue(int id, const string& name, int age) {
            Node* Queue = new Node();
            Queue->ID = id;
            Queue->Name = name;
            Queue->Age = age;
            Queue->next = nullptr;
    
            if (head == nullptr) {
                head = Queue;
                tail = Queue;
                current = Queue; // Initialize current when the first node is added
            } else {
                tail->next = Queue;
                tail = Queue;
                current = Queue;
            }
        }
    
        // 3. Dequeue (Remove by Current) Remove
       bool Dequeue(){
            if (head == nullptr){
                cout << "Cannot Dequeue, Nothing in Queue"<<endl;
            return false;
            }
    
            Node* temp = head;
            head = head->next;
    
            if (head == nullptr){
                current = nullptr;
                tail = nullptr;
            } else {
                current = head;
            }
            delete temp;
            cout <<"Head is dequeued"<<endl;
            return true;
            }
    
        // 4. Move Next
        void moveNext() {
            if (current != nullptr && current->next != nullptr) {
                current = current->next;
            cout<< "Current has move to next"<< endl;
            }else{
            cout << "Cannot move to next" << endl;
            }
        }
    
        // 5. Move Previous
        void movePrevious() {
            cout << "In SLL moving to previous is not supported."<<endl;
        }
    
    
        // 6. Print Head
        void printHead() {
            if (head != nullptr) {
                cout << "Head: ID=" << head->ID << ", Name=" << head->Name << ", Age=" << head->Age << endl;
            } else {
                cout << "List is empty." << endl;
            }
        }
    
        // 7. Print Tail
        void printTail() {
            if (tail != nullptr) {
                cout << "Tail: ID=" << tail->ID << ", Name=" << tail->Name << ", Age=" << tail->Age << endl;
            } else {
                cout << "List is empty." << endl;
            }
        }
    
        // 8. Print Current
        void printCurrent() {
            if (current != nullptr) {
                cout << "Current: ID=" << current->ID << ", Name=" << current->Name << ", Age=" << current->Age << endl;
            } else {
                cout << "Current is not pointing to any node." << endl;
            }
        }
    
        // 9. Print All
        void printAll() {
            if (head == nullptr) {
                cout << "List is empty." << endl;
                return;
            }
            Node* traverser = head;
            while (traverser != nullptr) {
                cout << "ID=" << traverser->ID << ", Name=" << traverser->Name << ", Age=" << traverser->Age << endl;
                traverser = traverser->next;
            }
        }
    };
// sll queue

// get array
void getarray(int*& arr, int& length) {
    cout << "Enter the number of elements: ";
    cin >> length;

    if (length <= 0) {
        cout << "Invalid array size." << endl;
        arr = nullptr;
        return;
    }

    arr = new int[length];

    cout << "Enter " << length << " numbers:" << endl;
    for (int i = 0; i < length; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// get array

// quicksort

void quicksort(int array[], int length, bool ascending = true);
void quicksort_recursion(int array[], int low, int high, bool ascending);
int partition(int array[], int low, int high, bool ascending);

void quicksort(int array[], int length, bool ascending) {
    srand(time(NULL));  // seed for RNG
    quicksort_recursion(array, 0, length - 1, ascending);
}

void quicksort_recursion(int array[], int low, int high, bool ascending) {
    if (low < high) {
        int pivot_index = partition(array, low, high, ascending);
        quicksort_recursion(array, low, pivot_index - 1, ascending);
        quicksort_recursion(array, pivot_index + 1, high, ascending);
    }
}

int partition(int array[], int low, int high, bool ascending) {
    int pivot_index = low + (rand() % (high - low + 1));
    swap(array[pivot_index], array[high]);  

    int pivot_value = array[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if ((ascending && array[j] <= pivot_value) || (!ascending && array[j] >= pivot_value)) {
            swap(array[i], array[j]);
            i++;
        }
    }

    swap(array[i], array[high]);  
    return i;  
}
//quick sort

//linear

int linear_search(const int array[], int length, int target);

int linear_search(const int array[], int length, int target) {
    for (int i = 0; i < length; i++) {
        if (array[i] == target) {
            return i;
        }
        cout << endl;
    }
    return -1;
}
// linear

//binary search

int binary_search(const int array[], int length, int target, bool ascending = true);

int binary_search(const int array[], int length, int target, bool ascending) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;  // Found it!
        }

        // Adjust based on sorting order
        if (ascending) {
            if (target < array[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > array[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    

    return -1;  // Not found
}
// binary search


int main() {
    SLL myList;
    int choice;
    int newID;
    string newName;
    int newAge;
    int idToRemove;

    do {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Initialize List\n";
        cout << "2. Queue Node\n";
        cout << "3. Dequeue Node\n";
        cout << "4. Move Next\n";
        cout << "5. Move Previous\n";
        cout << "6. Print Head\n";
        cout << "7. Print Tail\n";
        cout << "8. Print Current\n";
        cout << "9. Print All\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.clear();

        switch (choice) {
            case 1:
                myList = SLL();
                cout << "List initialized." << endl;
                break;
            case 2:
                cout << "Enter ID: ";
                cin >> newID;
                cout << "Enter Name: ";
                getline(cin >> ws, newName); // Read the whole line for name
                cout << "Enter Age: ";
                cin >> newAge;
                myList.Queue(newID, newName, newAge);
                cout << "Node added." << endl;
                break;
            case 3:
                myList.Dequeue();
                break;
            case 4:
                myList.moveNext();
                break;
            case 5:
                myList.movePrevious();
                break;
            case 6:
                myList.printHead();
                break;
            case 7:
                myList.printTail();
                break;
            case 8:
                myList.printCurrent();
                break;
            case 9:
                myList.printAll();
                break;
            case 10:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 10);

    int* userArray = nullptr;
    int arrayLength = 0;

    getarray(userArray, arrayLength); // Get array from user

    if (userArray == nullptr || arrayLength <= 0) {
        cout << "Array input failed. Exiting..." << endl;
        return 1;
    }

    cout << "quicksort" << endl;
    quicksort(userArray, arrayLength, true);  // Sort ascending
    cout << "Sorted array: ";
    for (int i = 0; i < arrayLength; ++i) {
        cout << userArray[i] << " ";
    }
    cout << endl;
    int searchoption;
    cout << "1 for binary search, 2 for linear search: ";
    cin >> searchoption;

    int result;
    if (searchoption == 1) {
        int userTarget;
        cout << "Enter target: ";
        cin >> userTarget;
        result = binary_search(userArray, arrayLength, userTarget);
        cout << "Position " << result;
    } else if (searchoption == 2) {
        int userTarget;
        cout << "Enter target: ";
        cin >> userTarget;
        result = linear_search(userArray, arrayLength, userTarget);
        cout << "Position " << result;
    } else {
        cout << "Error: only 1 or 2, please!";
    }

    return 0;
}