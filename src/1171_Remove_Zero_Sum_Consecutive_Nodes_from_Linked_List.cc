#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>


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
    using Node = ListNode;

    void remove(Node* fake_head, int start, int end) {
        auto prev = fake_head;
        for (int i = 0; i < start - 1; ++i) { 
            prev = prev->next;
        }

        auto cur = prev->next;
        for (int i = start; i <= end; ++i) { 
            if (cur) {
                cur = cur->next;
            }
        }

        prev->next = cur;
    }

    Node* removeZeroSumSublists(Node* head) {
        auto fake_node = Node(0, head);

        std::vector<int> prefix_sum(1001,0);
        std::unordered_map<int, int> prefix_sum_map;
        prefix_sum_map.emplace(0, 0);
        
        auto cur = head;
        for (int i = 1; cur; cur = cur->next) {
            if (cur->val == 0) {
                remove(&fake_node, i, i);
                continue;
            }

            prefix_sum[i] = prefix_sum[i-1] + cur->val;
            auto [it, inserted] = prefix_sum_map.emplace(prefix_sum[i], i);

            std::cout << prefix_sum[i] << std::endl;
            for (int j = 0; j <= i; ++j) {
                std::cout << prefix_sum[j] << ' ';
            }
            std::cout << std::endl;
            for (auto v: prefix_sum_map) {
                std::cout << v.first << ' ';
            }
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;


            if (!inserted || prefix_sum[i] == 0) {
                remove(&fake_node, it->second + 1, i);

                int k = it->second;
                for (int j = it->second+1; j < i; ++j) {
                    prefix_sum_map.erase(prefix_sum[j]);
                }
                i = k;
            }
            ++i;
        }

        return fake_node.next;
    }
};


int main() {
    Solution s;

    // ListNode* list = new ListNode(1, new ListNode(2, new ListNode(-3, new ListNode(3, new ListNode(1)))));
    ListNode* list = new ListNode(2, new ListNode(2, new ListNode(-2, new ListNode(1, new ListNode(-1, new ListNode(-1))))));
    // ListNode* list = new ListNode(1, new ListNode(3, new ListNode(2, new ListNode(-3, new ListNode(-2, new ListNode(5, new ListNode(5, new ListNode(-5, new ListNode(1)))))))));
    // ListNode* list = new ListNode(2, new ListNode(0));


    // s.remove(list, 0, 0);

    list = s.removeZeroSumSublists(list);
    for (auto it = list; it; it = it->next) {
        cout << it->val << ' ';
    }
    cout << endl;
}