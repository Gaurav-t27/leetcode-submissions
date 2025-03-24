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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int,
            ListNode*>> > minHeap;

        for (ListNode* list : lists)
        {
            if (list)
            {
                minHeap.push({ list->val, list });
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!minHeap.empty())
        {
            pair<int, ListNode*> minPair = minHeap.top();
            minHeap.pop();

            int minVal = minPair.first;
            ListNode* minNode = minPair.second;

            tail->next = minNode;
            tail = tail->next;

            if (minNode->next)
            {
                minHeap.push({ minNode->next->val,minNode->next });
            }
        }

        ListNode* res = dummy->next;
        delete dummy;

        return res;
    }
};