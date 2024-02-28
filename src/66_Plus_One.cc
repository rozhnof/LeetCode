#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> plus_one_digits(digits);
        
        int last_index = plus_one_digits.size() - 1;
        while (last_index > 0 && plus_one_digits[last_index] >= 9) {
            plus_one_digits[last_index] = 0;
            --last_index;
            ++plus_one_digits[last_index];
        }

        if (last_index == 0 && plus_one_digits[0] == 0) {
            plus_one_digits.insert(plus_one_digits.begin(), 1);
        }

        return plus_one_digits;
    }
};

int main() {
    vector<int> num = {8,9,0};
    Solution S;

    auto vec = S.plusOne(num);

    for (const auto &it : vec) {
        cout << it;
    }

}