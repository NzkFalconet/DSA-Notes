/*
Logic:

1. Brute Force Approach:
- A straightforward approach would be to store all elements of the linked list in an array and then rotate the array by `k` positions.

Time Complexity: O(N), where N is the number of nodes in the list.
Space Complexity: O(N), due to the additional space needed for storing the linked list elements.

2. Optimal Approach:

a. I learned that we can also use a two-pointer technique for a more efficient solution.
b. The key question was how to implement this approach effectively.
c. For example, if we want to rotate the list by 2 positions:
   - The list [1, 2, 3, 4, 5] becomes [4, 5, 1, 2, 3] after rotation.
d. To identify the last `k` elements, we can use two pointers starting from the head node and move the `fast` pointer `k` positions ahead.
f. Now We start moving both pointers one step at a time until the `fast` pointer reaches the end of the list.
g. At that point, the `slow` pointer will be `k` nodes behind the `fast` pointer.
h. Now we have identified the portion of the list to rotate.
i. We can link `fast->next` to `dummy->next`, set `dummy->next` to `slow->next`, and then break the link by setting `slow->next` to `NULL`.
j. Finally, we return `dummy->next` as the new head of the rotated list.

Time Complexity: O(N), where N is the number of nodes in the list.
Space Complexity: O(1), as the operation is performed in-place without using extra space.
*/

 ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;

        // Create a dummy node pointing to the head
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = head;
        ListNode* fast = head;
        int size = 0;

        // Calculate the size of the linked list
        while (slow) {
            size++;
            slow = slow->next;
        }

        // Adjust k to be within the length of the list
        k = k % size;
        if (k == 0) return head;  // No rotation needed if k is 0

        // Move the fast pointer k positions ahead
        slow = head;
        while (k--) {
            fast = fast->next;
        }

        // Move both pointers until the fast pointer reaches the last node
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Perform the rotation
        fast->next = dummy->next;
        dummy->next = slow->next;
        slow->next = nullptr;

        return dummy->next;
    }
