/*
Logic:

1. Brute Force Approach:
   - The basic approach could involve traversing the list to find its length, then traversing again to remove the middle node.

Time Complexity:
Space Complexity:

2. Optimal Approach:
   - Use two pointers: `slow` and `fast`.
   - Move the `fast` pointer by two nodes at a time and the `slow` pointer by one node at a time.
   - When `fast` reaches the end of the list, `slow` will be pointing to the node just before the middle node.
   - Remove the middle node by adjusting the `next` pointer of `slow` to skip the middle node (`slow->next = slow->next->next`).

Time Complexity: O(N), where N is the number of nodes in the list.
Space Complexity: O(1), as the operation is done in-place without using extra space.
*/

ListNode *deleteMiddle(ListNode *head)
{
    // Edge case: if the list has only one node, return nullptr (empty list).
    if (!head || !head->next)
        return nullptr;

    // Create a dummy node to handle edge cases more easily.
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy;
    ListNode *fast = head;

    // Move `fast` by two nodes and `slow` by one node until `fast` reaches the end.
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // `slow` now points to the node just before the middle node. Remove the middle node.
    slow->next = slow->next->next;

    // Return the modified list, starting from the original head.
    return dummy->next;
}
