#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <array>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto chars = vector<bool>(255);
        int left = 0, right = 0, max_len = 0;

        while (right < ssize(s)) {
            if (!chars[s[right]]) {
                if (int len = right - left + 1; len > max_len) {
                    max_len = len;
                }

                chars[s[right]] = true;
                ++right;
            } else {
                chars[s[left]] = false;
                ++left;
            }
        }
        return max_len;
    }
};

int main() {
    Solution S;

    cout << S.lengthOfLongestSubstring("pwwkew") << " (Expected: 3)" << endl;
    cout << S.lengthOfLongestSubstring("bbbbb") << " (Expected: 1)" << endl;
    cout << S.lengthOfLongestSubstring("abcabcbb") << " (Expected: 3)" << endl;
    cout << S.lengthOfLongestSubstring("dvdf") << " (Expected: 3)" << endl;

    return 0;
}
