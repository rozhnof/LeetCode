#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {

        int size_a = a.size();
        int size_b = b.size();

        if (size_a > size_b) {
            b = string(size_a - size_b, '0').append(b);
        } else if (size_b > size_a) {
            a = string(size_b - size_a, '0').append(a);
        }

        int size = a.size();
        string result(size, '0');

        int last_index = size - 1;
        bool rem = false;

        for (; last_index >= 0; --last_index) {
            if (a[last_index] == b[last_index]) {
                if (rem == false) {
                    result[last_index] = '0';
                } else {
                    result[last_index] = '1';
                    rem = false;
                }

                if (a[last_index] == '1') {
                    rem = true;
                }
            } else {
                if (rem == false) {
                    result[last_index] = '1';
                } else {
                    result[last_index] = '0';
                }
            }
        }

        if (rem) {
            result.append("1");
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    Solution S;
    string a = "1";
    string b = "111";

    cout << S.addBinary(a, b);
}