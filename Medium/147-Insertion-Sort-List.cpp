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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<ListNode*> list;
        ListNode* h = head;

        while (h) {
            list.push_back(h);
            h = h->next;
        }

        sort(list.begin(),list.end(),[&](ListNode* a,ListNode* b){
            return a->val < b->val;
        });

        for (int i = 0; i < list.size() - 1; ++i) {
            list[i]->next = list[i + 1];
        }
        list.back()->next = nullptr;

        return list[0];
    }
};
