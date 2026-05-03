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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* prev = head, * curr = head->next;

        while(curr != nullptr) {
            if(curr->val == prev->val) {
                ListNode* temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete temp;
                continue;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return head;
    }
};