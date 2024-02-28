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
        for (auto node = head; node->next; node = node->next) {
            ++group_count;
        }
        group_count /= k;

        // if (k > 0) {
            auto [head_first, head_last] = reverseList(head, k);
            head = head_first;

            // for (int i = 1; i < k; ++i) {
                // auto [first, last] = reverseList(head_last->next, k);
                // head_last->next = first;
                // head_last = last;
            // }
        // }
        return head;
    }

    pair<ListNode*, ListNode*> reverseList(ListNode* head, int k) {
        auto prev = head;
        auto cur = head->next;
        prev->next = nullptr;
        while (k >= 0) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            --k;
        }
        cur->next = prev;

        return {cur, head};
    }
};

int main() {
    Solution s;

    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    auto res = s.reverseKGroup(list1, 2);

    while (res) {
        std::cout << res->val << ' ';
        res = res->next;
    }
}