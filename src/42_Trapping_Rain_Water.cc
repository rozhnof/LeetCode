#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
    struct Bar {
        int start;
        int height;
    };
public:
    int trap(vector<int>& h) {
        int summary_area = 0, left_max = 0, right_max = 0;

        for (int left = 0, right = std::ssize(h) - 1; left < right;  ) {
            if (h[left] > left_max) left_max = h[left];
            if (h[right] > right_max) right_max = h[right];

            int min_max = min(right_max, left_max);
            if (h[left] < min_max) summary_area += (min_max - h[left]);
            if (h[right] < min_max) summary_area += (min_max - h[right]);

            if (h[left] <= h[right]) ++left;
            else --right;
        }
        return summary_area;
    }
};

int main() {
    Solution S;

    vector<int> v = {4,2,0,3,2,5};

    cout << S.trap(v);
}