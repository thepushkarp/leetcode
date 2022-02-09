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
    void bubbleDown(ListNode* slow, ListNode* fast) {
        ListNode* first = slow;
        ListNode* second = slow -> next;
        int lastVal = first-> val;
        while (first != fast) {
            int temp = second -> val;
            second -> val = lastVal;
            lastVal = temp;
            first = first -> next;
            second = second -> next;
        }
        slow -> val = lastVal;
    }
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (fast == nullptr) break;
            bubbleDown(slow, fast);
        }
        return head;
    }
};
