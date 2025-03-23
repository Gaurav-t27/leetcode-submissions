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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cn1 = list1;
        ListNode* cn2 = list2;
        ListNode* cn = nullptr, *hd = nullptr;

        while (cn1 != nullptr && cn2 != nullptr)
        {
            ListNode* temp = nullptr;
            if (cn1->val < cn2->val)
            {
                temp = cn1;
                cn1 = cn1->next;
            }
            else
            {
                temp = cn2;
                cn2 = cn2->next;
            }

            if (cn == nullptr)
            {
                cn = temp;
                hd = cn;
            }
            else
            {
                cn->next = temp;
                cn = cn->next;
            }
        }

        if (cn1 != nullptr)
        {
            if (cn == nullptr)
                return list1;
            cn->next = cn1;
        }
        if (cn2 != nullptr)
        {
            if (cn == nullptr)
                return list2;
            cn->next = cn2;
        }
        return hd;
    }
};