#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int low, int hight) {
        int mid = low + (hight - low) / 2;

        if (mid > hight || mid < low) return mid;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return binarySearch(nums, target, low, mid - 1);
        } else if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, hight);
        } 

        return -1;
    }
};


int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    Solution s;

    cout << s.searchInsert(nums, -1) << endl;
}