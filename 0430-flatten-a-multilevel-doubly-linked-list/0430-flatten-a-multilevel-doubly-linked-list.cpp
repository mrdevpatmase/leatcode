class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr != nullptr) {
            // If there is no child, just move to the next node
            if (!curr->child) {
                curr = curr->next;
                continue;
            }
            
            // If there is a child, find the tail of the child list
            Node* childHead = curr->child;
            Node* childTail = childHead;
            while (childTail->next != nullptr) {
                childTail = childTail->next;
            }
            
            // Connect childTail to curr->next (if it exists)
            childTail->next = curr->next;
            if (curr->next != nullptr) {
                curr->next->prev = childTail;
            }
            
            // Connect curr to childHead
            curr->next = childHead;
            childHead->prev = curr;
            
            // Clear the child pointer
            curr->child = nullptr;
            
            // Move forward
            curr = curr->next;
        }
        
        return head;
    }
};
