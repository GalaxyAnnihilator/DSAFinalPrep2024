#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool condition(int a, int b, int result) {
    if (a*a + b*b == result*result) {
        return true;
    }
    return false;
}

void loop(Node *head, int ind_a, int ind_b, int ind_c, int length) {
    Node *temp = head;
    int a, b, c;
    for (int i = 0; i < ind_a; i++) {
        temp = temp->next;
    }
    a = temp->data;
    for (int i = 0; i < ind_b - ind_a; i++) {
        temp = temp->next;
    }
    b = temp->data;
    for (int i = 0; i < ind_c - ind_b; i++) {
        temp = temp->next;
    }
    c = temp->data;
    if ((condition(a, b, c) == 1) || (condition(b, c, a) == 1) || (condition(c, a, b) == 1)) {
        cout << a << " " << b << " " << c << endl;
    }
    if (ind_c < length - 1) {
        loop(head, ind_a, ind_b, ind_c + 1, length);
    } else if (ind_b < length - 2) {
        loop(head, ind_a, ind_b + 1, ind_b + 2, length);
    } else if (ind_a < length - 3) {
        loop(head, ind_a + 1, ind_a + 2, ind_a + 3, length);
    }
}
// T(n) = O(n^3)

int main()
{
  Node *head = NULL;
  insertNode(&head, 4);
  insertNode(&head, 15);
  insertNode(&head, 28);
  insertNode(&head, 45);
  insertNode(&head, 40);
  insertNode(&head, 9);
  insertNode(&head, 53);
  insertNode(&head, 41);
  insertNode(&head, 8);
  insertNode(&head, 17);
  insertNode(&head, 3);
  insertNode(&head, 5);
  printList(head);
  loop(head, 0, 1, 2, 12);
}