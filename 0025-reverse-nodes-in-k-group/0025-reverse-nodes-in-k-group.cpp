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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: if list is empty or k is 1, no modification needed
        if (!head || k == 1) return head;
        
        // Use a dummy node to ease head modifications
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevGroupTail = dummy;
        ListNode* curr = head;
        
        while (curr) {
            // Check if there are at least k nodes left in the current group
            ListNode* groupTail = prevGroupTail;
            for (int i = 0; i < k; ++i) {
                groupTail = groupTail->next;
                if (!groupTail) {
                    // Less than k nodes left; keep them as they are
                    ListNode* actualHead = dummy->next;
                    delete dummy;
                    return actualHead;
                }
            }
            
            // Track the start of the next group
            ListNode* nextGroupHead = groupTail->next;
            
            // Reverse the current group of k nodes
            ListNode* prev = nextGroupHead; 
            ListNode* groupHead = curr;
            while (curr != nextGroupHead) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            
            // Connect the reversed group back to the main list
            prevGroupTail->next = prev;
            prevGroupTail = groupHead;
        }
        
        ListNode* actualHead = dummy->next;
        delete dummy; // Free dummy node memory
        return actualHead;
    }
};
