#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(): ListNode(0) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode* next): val(val), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        ListNode* head;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        for (ListNode* cur = head; list1 || list2; cur = cur->next) {
            if (!list1) {
                cur->next = list2;
                break;
            } else if (!list2) {
                cur->next = list1;
                break;
            } else if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
        }
        return head;
    }
};


int main() {
    // auto list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    // auto list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    auto list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    auto list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution s;

    auto res = s.mergeTwoLists(list1, list2);

    while (res) {
        std::cout << res->val << ' ';
        res = res->next;
    }
}