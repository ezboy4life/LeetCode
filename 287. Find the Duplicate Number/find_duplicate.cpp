#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i != j && nums[i] == nums[j]) {
                return nums[j];
            }
        }
    }
    return 0;
}

int main() {
    vector<int> vetor = {3,1,3,4,2};
    cout << findDuplicate(vetor) << endl << endl;
    system("pause");
    return 0;
}