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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        return reverse(nullptr, head);
    }
   
    ListNode* reverse(ListNode* prev, ListNode* head) {
        ListNode* new_head = head;

        if (head->next) {
            new_head = reverse(head, head->next);
        }
         
        head->next = prev;
        return new_head;
    }
};

int main() {
    Solution s;

    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    auto res = s.reverseList(list1);

    while (res) {
        std::cout << res->val << ' ';
        res = res->next;
    }
}