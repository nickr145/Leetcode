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
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < lists.size(); ++i) {
            while (lists[i]) {
                minHeap.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while (!minHeap.empty()) {
            int value = minHeap.top();
            minHeap.pop();

            current->next = new ListNode(value);
            current = current->next;

        }

        return dummy->next;
    }
};
