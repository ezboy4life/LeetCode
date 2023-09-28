#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                arr.insert(arr.begin() ,nums[i]);
            } else {
                arr.push_back(nums[i]);
            }
        }
        return arr;
    }

    /* solução mais performática (tanto em memória quanto em runtime) -> não sabia que podia usar a função "sort" ୧(๑•̀ᗝ•́)૭ */

    vector<int> _sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return (a % 2) < (b % 2);
        });
        return move(nums);
    }
};

int main() {
    Solution solution;
    vector<int> vetor = {3,1,2,4};
    vector<int> result = solution._sortArrayByParity(vetor);

    vetor = {0};
    result = solution._sortArrayByParity(vetor);

    vetor = {1,2,5,20,7,3,9,13,27,2,8,10};
    result = solution._sortArrayByParity(vetor);

    return 0;
}