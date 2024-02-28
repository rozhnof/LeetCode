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
    bool isEmpty(array<int, 127>& chars, array<bool, 127>& chars_s2) {
        for (char i = 'A'; i <= 'z'; ++i) {
            if (chars_s2[i]) {
                if (chars[i] > 0) return false;
            }
        }
        return true;
    }

    string minWindow(string s1, string s2) {
        array<int, 127> chars = {0};
        array<bool, 127> chars_s2 = {false};

        for (int i = 0; i < ssize(s2); ++i) {
            chars_s2[s2[i]] = true;
            ++chars[s2[i]];
            --chars[s1[i]];
        }

        int min_window_size = ssize(s1);
        int window_start = 0;
        bool has_substr = false;
        for (int i = 0, window_size = ssize(s2); i <= ssize(s1) - window_size && window_size >= ssize(s2);) {
            if (!isEmpty(chars, chars_s2)) {
                ++window_size;
                --chars[s1[i + window_size - 1]];
                continue;
            } 
            has_substr = true;
            if (window_size < min_window_size) {
                min_window_size = window_size;
                window_start = i;
            }
            ++chars[s1[i]];
            ++i;
            --window_size;
        }
        if (!has_substr) {
            return "";
        }
        return s1.substr(window_start, min_window_size);
    }
};

int main() {
    Solution S;
    // cout << S.minWindow("bbaac", "baa") << endl;
    // cout << S.minWindow("CWAEFGC", "CC") << endl;
    cout << S.minWindow("tcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlx", "ozgzyywxvtublcl") << endl;
    // cout << S.minWindow("aa", "a") << endl;
    // cout << S.minWindow("a", "a") << endl;
    // cout << S.minWindow("ADOBECODEBANC", "ABC") << endl;


    return 0;
}
