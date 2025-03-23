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
    ListNode* reverseList(ListNode* head) {
        ListNode* cn=head;
        ListNode* prev=nullptr;

        while(cn!=nullptr)
        {
            ListNode* nn=cn->next;
            cn->next=prev;
            prev=cn;
            cn=nn;
        }

        return prev;
    }
};