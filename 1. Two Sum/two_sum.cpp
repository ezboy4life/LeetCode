#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        return {i, j};
                    }
                }
            }
        }
        return nums;    //só pra satisfazer o compilador
    }
};

/*
--- Testes ---
    
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]

    Input: nums = [3,2,4], target = 6
    Output: [1,2]

    Input: nums = [3,3], target = 6
    Output: [0,1]

*/

int main() {
    Solution solution;
    vector<int> vetor = {2,7,11,15};    
    vector<int> arr = solution.twoSum(vetor, 9);    //retorno = [0,1]

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    vetor = {3,2,4};
    arr = solution.twoSum(vetor, 6);

    vetor = {3,3};
    arr = solution.twoSum(vetor, 6);
    //show de bola ! ;) 
    system("pause");
    return 0;
}