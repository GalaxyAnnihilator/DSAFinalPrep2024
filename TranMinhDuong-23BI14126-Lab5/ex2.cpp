#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
using namespace std;

#define CAPACITY 100

typedef struct TreeNode{
    int val;
    struct TreeNode *parent;
    struct TreeNode *tleft;
    struct TreeNode *tright;
} TreeNode;

TreeNode* init(int val){
    TreeNode *node = new TreeNode;
    node->val = val;
    node->parent = nullptr;
    node->tleft = nullptr;
    node->tright=nullptr;
    return node;
}

void initializeArray(int arr[],int n){
    srand(time(0));
    for (int i = 0;i<n;i++){
        arr[i] = rand() % 100;
    }
}

TreeNode* buildBinarySearchTree(int arr[],int n){
    int h = ceil(log2(n))+1; //max height, example h = 4
    int total = pow(2,h)-1; //total nodes, example total = 15

    int E = arr[0];
    for (int i = 1;i<n;i++){
        if (E<arr[i]){
            E = arr[i];
        }
    }
    E = E+1; //example E = 42

    //using array to store pointers
    TreeNode** nodes = new TreeNode*[total];
    for (int i =0;i<total;i++){
        nodes[i] = nullptr;
    }

    //start filling bottom leaves with array values + empty nodes with E
    int leaf_start = pow(2,h-1)-1; //example: leaf_start = 7
    int num_leaves = 1 << (h - 1);

    //assign array elements to leaves
    for(int i = 0; i < n; ++i) {
        nodes[leaf_start + i] = init(arr[i]);
    }

    //fill remaining leaves with E
    for (int i = n; i < num_leaves; i++) {
        nodes[leaf_start + i] = init(E);
    }

    //bottom up
    for (int i = leaf_start-1;i>=0;i--){
        nodes[i] = init(0);
        nodes[i]->tleft = nodes[2*i+1];
        nodes[i]->tright = nodes[2*i+2];
        nodes[2*i+1]->parent = nodes[i];
        nodes[2*i+2]->parent = nodes[i];
        nodes[i]->val = min(nodes[i]->tleft->val, nodes[i]->tright->val);
    }

    TreeNode* root = nodes[0];
    
    return root;
}

// Queue for BFS
typedef struct {
    int capacity;
    int front, back;
    TreeNode **data;
} Queue;

Queue* initQueue(int N) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->back = 0;
    q->capacity = N;
    q->data = (TreeNode**)malloc(N * sizeof(TreeNode*));
    return q;
}

int isEmpty(Queue *q) {
    return (q->front == q->back);
}

int length(Queue *q) {
    return (q->back - q->front + q->capacity) % q->capacity;
}

int isFull(Queue *q) {
    return (length(q) == q->capacity - 1);
}

int enqueue(Queue *q, TreeNode* newValue) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return 0;
    }
    q->data[q->back] = newValue;
    q->back = (q->back + 1) % q->capacity; 
    return 1;
}

TreeNode* dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return nullptr;
    }
    TreeNode* val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity; 
    return val;
}

void freeQueue(Queue *q) {
    free(q->data);
    free(q);
}

void displayTreeBFS(TreeNode* root){
    if (!root) {
        cout << "Tree is empty." << endl;
        return;
    }

    Queue* q = initQueue(CAPACITY);
    enqueue(q, root);
    int level = 0;

    while (!isEmpty(q)) {
        int nodesInLevel = length(q);
        cout << "Level " << level << ": ";
        
        for (int i = 0; i < nodesInLevel; ++i) {
            TreeNode* node = dequeue(q);
            if (node) {
                cout << node->val << " ";
                if (node->tleft) enqueue(q, node->tleft);
                if (node->tright) enqueue(q, node->tright);
            } else {
                cout << "N ";  //ullptr
            }
        }
        cout << endl;
        level++;
    }

    freeQueue(q); 
}

TreeNode* search(TreeNode* node, int target) {
    if (node == nullptr || node->val == target) {
        return node;
    }
    TreeNode* leftResult = search(node->tleft, target);
    if (leftResult != nullptr) return leftResult;

    return search(node->tright, target);
}

void insert(TreeNode* root, int newValue, int E) {
    if (!root) return;

    // BFS-like search for an E node to replace with newValue
    Queue* q = initQueue(CAPACITY);
    enqueue(q, root);

    while (!isEmpty(q)) {
        TreeNode* node = dequeue(q);

        if (node->val == E) {
            node->val = newValue;
            // Update the tree
            TreeNode* current = node->parent;
            while (current != nullptr) {
                current->val = min(current->tleft->val, current->tright->val);
                current = current->parent;
            }
            freeQueue(q);
            return;
        }

        if (node->tleft) enqueue(q, node->tleft);
        if (node->tright) enqueue(q, node->tright);
    }

    freeQueue(q);
    cout << "No empty node found for insertion!" << endl;
}

// Remove a node from the tree
void remove(TreeNode* node) {
    if (!node || !node->parent) return;

    // Replace the node's value with its parent's value
    node->val = node->parent->val;

    // Update the tree upwards to maintain the minimum property
    TreeNode* current = node->parent;
    while (current != nullptr) {
        current->val = min(current->tleft->val, current->tright->val);
        current = current->parent;
    }
}

int main(){
    // int n;
    // cout << "Enter the number of elements: ";
    // cin >> n;

    // int* data = new int[n];
    // initializeArray(data, n);

    int data[] = {8,20,41,7,2};
    int n = sizeof(data)/sizeof(data[0]);
    cout << "Initial array: ";
    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    TreeNode* root = buildBinarySearchTree(data, n);

    cout << "Tree structure (DFS): " << endl;
    displayTreeBFS(root);

    // int searchValue = 7;
    // // cout << "Enter a value to search: ";
    // // cin >> searchValue;
    // TreeNode* result = search(root, searchValue);
    // if (result) {
    //     cout << "Found value: " << searchValue << endl;
    // } else {
    //     cout << "Value not found." << endl;
    // }

    // Insert a new value
    int newValue;
    cout << "Enter a new value to insert: ";
    cin >> newValue;
    insert(root, newValue, 42);  // Assuming E is greater than the max element
    displayTreeBFS(root);

    // Remove a node
    // int removeValue;
    // cout << "Enter a value to remove: ";
    // cin >> removeValue;
    // result = search(root, removeValue);
    // if (result) {
    //     remove(result);
    //     displayTreeBFS(root);
    // } else {
    //     cout << "Value not found, cannot remove." << endl;
    // }

    return 0;
}
