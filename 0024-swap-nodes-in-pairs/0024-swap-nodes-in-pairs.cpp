/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if the list is empty or has only one node, no swaps are needed
        if (!head || !head->next) {
            return head;
        }
        
        // Initialize a dummy node to easily track and return the new head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Traverse the list while there are at least two nodes left to swap
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Perform the pointer adjustments to swap 'first' and 'second'
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move 'prev' forward by two positions for the next pair
            prev = first;
        }
        
        return dummy.next;
    }
};
