/*
- This is the R-L-N traversal, lets call the function visit()
function visit(node):
    visit(node->right)
    visit(node->left)
    print(node)


- We start at the root by calling visit(root) {the node with the value 40}
    + Visit the right subtrue: visit(root->right) {the subtree by node 61}
        + Visit the right subtree by node 310
            + Node 310 has no more child to visit
            + Print 310
        + Visit the left subtree by node 45
            + Node 45 has no more child to visit
            + Print 45
        + Print 61    
    + Visit the left subtree: visit(root->left) {the subtree of node 4}
        + Visit the right subtree by node 9
            + Node 9 has no more child to visit
            + Print 9
        + Visit the left subtree by node 1
            + Node 1 has no more child to visit
            + Print 1
        + Print 4
    + Print the root 40

=> The printing order is 310, 45, 61, 9, 1, 4, 40        

*/