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
        Node* current = head;
        while (current != nullptr) {
            if (current -> child == nullptr) {
                current = current -> next;
                continue;
            }
            Node* temp = current -> child;
            while (temp -> next != nullptr) {
                temp = temp -> next;
            }
            temp -> next = current -> next;
            if (current -> next != nullptr) current -> next -> prev = temp;
            current -> next = current -> child;
            current -> child -> prev = current;
            current -> child = nullptr;
        }
        return head;
    }
};

