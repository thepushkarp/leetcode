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
    ListNode* middleNode(ListNode* head) {
        int count = 1;
        ListNode* node = head;
        while(node->next != nullptr) {
            count++;
            node = node->next;
        }
        int middle = count/2;
        node = head;
        while (middle--) {
            node = node->next;
        }
        return node;
    }
};
