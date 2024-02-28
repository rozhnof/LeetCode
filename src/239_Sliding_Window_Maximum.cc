#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <array>
#include <map>
#include <deque>

using namespace std;


class Solution {
public:
    void foo(vector<int>& n, deque<int>& deque_of_max, int i) {
        while (!deque_of_max.empty() && deque_of_max.back() < n[i]) {
            deque_of_max.pop_back();
        }
        deque_of_max.push_back(n[i]);
    }

    vector<int> maxSlidingWindow(vector<int>& n, int k) {
        if (ssize(n) < k || ssize(n) <= 0) return {};
        
        vector<int> result;
        deque<int> deque_of_max;

        for (int i = 0; i < k; ++i) {
            foo(n, deque_of_max, i);
        }
        result.push_back(deque_of_max.front());

        for (int i = 1; i + k <= ssize(n); ++i) {
            if (deque_of_max.front() == n[i-1]) {
                deque_of_max.pop_front();
            }
            foo(n, deque_of_max, i + k - 1);
            result.push_back(deque_of_max.front());
        }
        
        return result;
    }
};

int main() {
    Solution S;

    // std::vector v = {1,3,-1,-3,5,3,6,7};
    // auto res = S.maxSlidingWindow(v, 3);

    // std::vector v = {1,3,-1,-3,5,3,6,7};
    // auto res = S.maxSlidingWindow(v, 3);

    std::vector v = {1, -1};
    auto res = S.maxSlidingWindow(v, 1);

    for (auto val: res) {
        cout << val << ' ';
    }


    return 0;
}
