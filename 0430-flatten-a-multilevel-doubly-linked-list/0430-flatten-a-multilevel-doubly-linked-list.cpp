/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        flattenTail(head);
        return head;
    }

private:
    // Helper function that flattens the list and returns the TAIL node
    Node* flattenTail(Node* node) {
        Node* curr = node;
        Node* tail = node;
        
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            tail = curr; // Keep track of the last non-null node
            
            if (curr->child != nullptr) {
                Node* childHead = curr->child;
                // Recursively flatten the child list and get its tail
                Node* childTail = flattenTail(childHead);
                
                // Rewire: Connect curr to childHead
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr; // Clear child pointer
                
                // Rewire: Connect childTail to nextNode
                childTail->next = nextNode;
                if (nextNode != nullptr) {
                    nextNode->prev = childTail;
                }
                
                // Update the tail tracking to the end of the child list
                tail = childTail;
            }
            
            // Advance to the next node
            curr = nextNode;
        }
        
        return tail;
    }
};
