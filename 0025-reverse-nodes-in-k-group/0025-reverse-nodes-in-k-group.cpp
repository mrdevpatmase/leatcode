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
        // Step 1: Check if there are at least k nodes left in the list
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If we found k nodes, reverse them
        if (count == k) {
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;
            curr = head;
            
            // Step 2: Standard linked list reversal for k nodes
            for (int i = 0; i < k; i++) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            
            // Step 3: 'head' is now the tail of the reversed group.
            // Recurse for the remaining list and connect it.
            if (nextNode != nullptr) {
                head->next = reverseKGroup(nextNode, k);
            }
            
            // 'prev' is the new head of this reversed group
            return prev;
        }
        
        // If there are fewer than k nodes, return head as-is
        return head;
    }
};
