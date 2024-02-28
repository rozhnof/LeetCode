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
    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;

        for (int i = 0; i < ssize(lists); ++i) {
            if (lists[i]) {
                q.push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }

        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while (!q.empty()) {
            auto top = q.top();
            auto next = top->next;

            q.pop();
            if (next) {
                q.push(next);
            }

            if (!head) {
                head = top;
                cur = top;
            } else {
                cur->next = top;
                cur = cur->next;
            }
        }
        return head;
    }
};


int main() {
    Solution s;

    auto list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    auto list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    auto list3 = new ListNode(2, new ListNode(6));
    std::vector<ListNode*> v = {list1, list2, list3};

    auto res = s.mergeKLists(v);

    while (res) {
        std::cout << res->val << ' ';
        res = res->next;
    }
}