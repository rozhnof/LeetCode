#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <array>
#include <map>

using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 91> chars = {0};
        int left = 0, right = 0, max_count = 0;

        while (right < ssize(s)) {
            ++chars[s[right]];
            auto [max_letter, letter_count] = GetMaxLetter(chars);
            ++right;

            if (letter_count - max_letter <= k) {
                max_count = max(max_count, letter_count);
            } else {
                --chars[s[left]];
                ++left;
            }
        }
        return max_count;
    }

    std::pair<int, int> GetMaxLetter(array<int, 91>& chars) {
        int max_letter = 0;
        int total_count = 0;
        for (char i = 'A'; i <= 'Z'; ++i) {
            max_letter = max(max_letter, chars[i]);
            total_count += chars[i];
        }
        return {max_letter, total_count};
    }
};

int main() {
    Solution S;

    cout << S.characterReplacement("AABABBA", 1) << " (Expected: 4)" << endl;
    // cout << S.characterReplacement("bbbbb") << " (Expected: 1)" << endl;
    // cout << S.characterReplacement("abcabcbb") << " (Expected: 3)" << endl;
    // cout << S.characterReplacement("dvdf") << " (Expected: 3)" << endl;

    return 0;
}
