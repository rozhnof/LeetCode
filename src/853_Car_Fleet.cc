#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


class Solution {
    struct Car {
        int position;
        int speed;

        bool operator<(const Car& other) const {
            return position > other.position;
        }
    };

  public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<Car> cars;
        for (int i = 0; i < pos.size(); ++i) {
            cars.push_back(Car{pos[i], speed[i]});
        }
        std::sort(cars.begin(), cars.end());

        int fleets = cars.size();
        for (int i = 1; i < cars.size(); ++i) {
            double rem_distance_cur = target - cars[i].position;
            double rem_distance_prev = target - cars[i-1].position;

            if (rem_distance_cur / cars[i].speed <= rem_distance_prev / cars[i-1].speed) {
                cars[i].position = cars[i-1].position;
                cars[i].speed = cars[i-1].speed;
                --fleets;
            }
        }

        return fleets;
    }
};


int main() {
    Solution s;
    vector<int> pos = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};

    // vector<int> pos = {0,2,4};
    // vector<int> speed = {4,2,1};


    cout << s.carFleet(12, pos, speed);
}