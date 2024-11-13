/*
Exercise 1:
 Implement one of the three elementary sorting algorithms (Selection, Bubble,
or Insert Sort) in C/C++.
 Implement the selected sorting algorithm using a recursive function.
 Implement the selected sorting algorithm using a data structure (List, Stack,
or Queue). Justify your choice.
*/

#include <iostream>
using namespace std;

//Choosing bubble sort + implement with List data structure

void bubbleRecursive(int* arr, int n, int j){
    if (j+1>=n){
        return;
    }
    if (arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
    }
    bubbleRecursive(arr,n,j+1);
}

void displayArray(int *arr,int n){
    for (int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0;i<n;i++){
        bubbleRecursive(arr,n,0);
    }

    displayArray(arr,n);
    return 0;
}

/*
#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0}; 

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSortIterative(Node* head) {
    if (head == nullptr) {
        return;
    }
    
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr; //last pointer
    
    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

bool bubbleSortRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    
    Node* current = head;
    bool swapped = false;

    while (current->next != nullptr) {
        if (current->data > current->next->data) {
            swap(current->data, current->next->data);
            swapped = true; 
        }
        current = current->next;
    }

    return swapped;
}

void bubbleSort(Node* head) {
    if (!bubbleSortRecursive(head)) {
        return;
    }
    bubbleSort(head);
}

int main() {
    Node* head = nullptr;

    insertEnd(&head, 9);
    insertEnd(&head, 8);
    insertEnd(&head, 7);
    insertEnd(&head, 6);
    insertEnd(&head, 5);
    insertEnd(&head, 4);
    insertEnd(&head, 3);
    insertEnd(&head, 2);
    insertEnd(&head, 1);
    insertEnd(&head, 0);

    cout << "Before Sorting: ";
    displayList(head);

    bubbleSortIterative(head);

    cout << "After Sorting: ";
    displayList(head);

    return 0;
}


#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // eft subarray
    int n2 = right - mid;    // right subarray

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // middle point

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "After Sorting: ";
    printArray(arr, arr_size);

    return 0;
}


// #include <iostream>
// using namespace std;

// // Node structure
// struct Node {
//     int data;
//     Node* next;
// };

// // Function to insert nodes at the end of the list
// void insertEnd(Node** head, int data) {
//     Node* newNode = new Node();
//     newNode->data = data;
//     newNode->next = nullptr;
    
//     if (*head == nullptr) {
//         *head = newNode;
//         return;
//     }
    
//     Node* temp = *head;
//     while (temp->next != nullptr) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// // Function to display the linked list
// void displayList(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// // Function to find the middle of the linked list
// Node* getMiddle(Node* head) {
//     if (head == nullptr) return head;
    
//     Node* slow = head;
//     Node* fast = head->next;
    
//     while (fast != nullptr && fast->next != nullptr) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
    
//     return slow; // slow is the middle node
// }

// // Function to merge two sorted linked lists
// Node* mergeSortedLists(Node* left, Node* right) {
//     if (left == nullptr) return right;
//     if (right == nullptr) return left;
    
//     Node* result = nullptr;
    
//     if (left->data <= right->data) {
//         result = left;
//         result->next = mergeSortedLists(left->next, right);
//     } else {
//         result = right;
//         result->next = mergeSortedLists(left, right->next);
//     }
    
//     return result;
// }

// // Recursive Merge Sort function for linked list
// void mergeSort(Node** head) {
//     if (*head == nullptr || (*head)->next == nullptr) {
//         return; // Base case: list is empty or has a single node
//     }
    
//     // Split the list into two halves
//     Node* middle = getMiddle(*head);
//     Node* left = *head;
//     Node* right = middle->next;
//     middle->next = nullptr; // Split the list into two halves
    
//     // Recursively sort both halves
//     mergeSort(&left);
//     mergeSort(&right);
    
//     // Merge the sorted halves
//     *head = mergeSortedLists(left, right);
// }

// int main() {
//     Node* head = nullptr;

//     // Insert elements into the linked list
//     insertEnd(&head, 38);
//     insertEnd(&head, 27);
//     insertEnd(&head, 43);
//     insertEnd(&head, 3);
//     insertEnd(&head, 9);
//     insertEnd(&head, 82);
//     insertEnd(&head, 10);

//     cout << "Before Sorting: ";
//     displayList(head);

//     // Perform Merge Sort on the linked list
//     mergeSort(&head);

//     cout << "After Sorting: ";
//     displayList(head);

//     return 0;
// }



#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to rearrange the array based on the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Move the smaller element index forward
            swap(&arr[i], &arr[j]); // Swap the elements
        }
    }

    // Swap the pivot element with the element at index (i + 1)
    swap(&arr[i + 1], &arr[high]);

    return (i + 1); // Return the partitioning index
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    printArray(arr, arr_size);

    // Perform quick sort
    quickSort(arr, 0, arr_size - 1);

    cout << "After Sorting: ";
    printArray(arr, arr_size);

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
     int n, num, digit, rev = 0;

     cout << "Enter a positive number: ";
     cin >> num;

     n = num;

     do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     cout << " The reverse of the number is: " << rev << endl;

     if (n == rev and n > 0)  // Negative numbers are not palindromic
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}

123320
N = 7
s = Stack();
push 6/2 = 3 phan tu
S = [1 2 3]
pop 3 phan tu
S = [ 1 2]
S = [ 1]
S = []



*/