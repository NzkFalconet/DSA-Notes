/*
Logic:

1. Brute Force Approach:
- A simple approach would be to iterate through the linked list and store nodes in two separate arrays based on whether they are less than the target value `x` or greater than or equal to `x`.
- Combine the two arrays to form the partitioned list.

Time Complexity: O(N), where N is the number of nodes in the list.
Space Complexity: O(N), due to the additional space needed to store nodes in arrays.
*/

ListNode* partition(ListNode* head, int x) {
    vector<ListNode*> less;
    vector<ListNode*> great;
    ListNode* curr = head;

    // Traverse and separate nodes into less and great arrays
    while (curr) {
        if (curr->val < x) {
            less.push_back(curr);
        } else {
            great.push_back(curr);
        }
        curr = curr->next;
    }

    // Combine nodes from less and great arrays to form the partitioned list
    ListNode dummy(0);
    curr = &dummy;

    for (auto node : less) {
        curr->next = node;
        curr = node;
    }
    for (auto node : great) {
        curr->next = node;
        curr = node;
    }
    curr->next = nullptr;  // End the list

    return dummy.next;
}

/*
2. Optimal Approach:
- Instead of using extra space for arrays, use two pointers to create two separate linked lists: one for nodes with values less than `x` and one for nodes with values greater than or equal to `x`.
- Link the two lists at the end to form the partitioned list.

Time Complexity: O(N), where N is the number of nodes in the list.
Space Complexity: O(1), as it modifies the list in-place without additional space.
*/

ListNode* partition(ListNode* head, int x) {
    // Create two dummy nodes for less and great lists
    ListNode* less = new ListNode(0);
    ListNode* great = new ListNode(0);
    ListNode* lessNode = less;
    ListNode* greatNode = great;
    ListNode* curr = head;

    // Partition the list by rearranging nodes
    while (curr) {
        if (curr->val < x) {
            lessNode->next = curr;
            lessNode = lessNode->next;
        } else {
            greatNode->next = curr;
            greatNode = greatNode->next;
        }
        curr = curr->next;
    }

    // Ensure the end of the great list points to null
    greatNode->next = nullptr;
    // Link the end of the less list to the start of the great list
    lessNode->next = great->next;

    return less->next;  // The start of the partitioned list
}
