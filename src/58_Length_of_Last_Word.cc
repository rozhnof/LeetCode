#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string &s) {
        int index = s.size() - 1;
        while(index >= 0 && s[index] == ' ') {
            --index;
        }

        int size = index;
        while(index >= 0 && s[index] != ' ') {
            --index;
        }

        return size - index;
    }
};


int main() {
    string s = "  b  abob ";
    Solution S;

    cout << S.lengthOfLastWord(s);
}