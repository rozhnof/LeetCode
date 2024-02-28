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
    bool isEmpty(array<int, 26>& c) {
        for (auto val: c) if (val != 0) return false;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        array<int, 26> chars = {0};
        int window_size = ssize(s1);

        if (s2.size() < window_size) return false;

        for (int i = 0; i < window_size; ++i) {
            ++chars[s1[i] - 'a'];
            --chars[s2[i] - 'a'];
        }
        if (isEmpty(chars)) return true;

        for (int i = 1; i <= ssize(s2) - window_size; ++i) {
            ++chars[s2[i-1] - 'a'];
            --chars[s2[i+window_size-1] - 'a'];
            if (isEmpty(chars)) return true;
        }
        return false;
    }
};

int main() {
    Solution S;

    // cout << S.checkInclusion("cedf", "abcdefg");
    // cout << S.checkInclusion("ab", "eidbaooo");
    // cout << S.checkInclusion("dcfe", "abcdefg");
    // cout << S.checkInclusion("a", "ab");
    cout << S.checkInclusion("ab", "a");
    // cout << S.checkInclusion("b", "ab");
    // cout << S.checkInclusion("adc", "dcda");

    // cout << endl;

    // cout << S.checkInclusion("ab", "eidboooo");

    return 0;
}
