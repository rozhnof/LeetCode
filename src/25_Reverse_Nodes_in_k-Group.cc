#include <vector>
#include <iostream>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int group_count = 0;
        for (auto node = head; node; node = node->next) {
            ++group_count;
        }
        group_count /= k;

        if (group_count > 0) {
            auto [new_head, old_head] = reverseList(head, k);
            head = new_head;

            for (int i = 1; i < group_count; ++i) {
                auto [new_head_i, old_head_i] = reverseList(old_head->next, k);
                old_head->next = new_head_i;
                old_head = old_head_i;
            }
        }
        return head;
    }

    pair<ListNode*, ListNode*> reverseList(ListNode* head, int k) {
        auto [new_head, old_head] = reverse(nullptr, head, k - 1);
        head->next = old_head;
        return {new_head, head};
    }
   
    pair<ListNode*, ListNode*> reverse(ListNode* prev, ListNode*& head, int k) {
        ListNode* new_head = head;
        ListNode* next = head->next;

        if (k > 0) {
            auto [new_head_1, next_1] = reverse(head, head->next, k - 1);
            new_head = new_head_1;
            next = next_1;
        } 
        
        head->next = prev;
        return {new_head, next};
    }
};

int main() {
    Solution s;

    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    // ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    // ListNode* list1 = new ListNode(1, new ListNode(2));

    auto res = s.reverseKGroup(list1, 2);

    while (res) {
        std::cout << res->val << ' ';
        res = res->next;
    }
}