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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        else if (head -> next == nullptr) {
            if (head -> val == val) {
                head = head -> next;
            }
            return head;
        }
        while (head != nullptr and head -> val == val) {
            head = head -> next;
        }
        ListNode* curr = head;
        ListNode* prev = head;
        while (curr != nullptr) {
            if (curr -> val == val) {
                prev -> next = curr -> next;
            }
            else {
                prev = curr;
            }
            curr = curr -> next;
        }
        return head;
    }
};
