/*
Logic:

1. Brute Force Approach:
- A simple approach is to use BFS and store the nodes in a vector.
- Use pointers to traverse and connect the elements in the vector.
Time Complexity: O(N), where N is the number of nodes in the list.
Space Complexity: O(N), due to the additional space needed to store nodes in arrays.


*/





/*

  

2. Optimal Approach:
- Initially, it may not be clear how to keep track of the right child of the root while processing the left child, as you cannot backtrack to the root and then move to the right child.
- So, how do we manage this?
- Consider the diagram below and how we can connect node 5 to node 6

        1
      /   \
     2 ---> 3
    / \    / \
   4   5  6   7
- The intuition is that if we connect node 2 to node 3, we can then connect the right child of node 2 to the left child of node 3.

Time Complexity: O(N), where N is the number of nodes in the list.
Space Complexity: O(1), as recursive space is told be ignored


*/
 Node* connect(Node* root) {
        if(!root || !root->left)return root;
        root->left->next = root->right;
        if(root->next){
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }

