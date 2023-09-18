#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0 && n > 0) {
            nums1 = nums2;
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (nums1[j] >= nums2[i]) {
                        nums1.insert(nums1.begin() + j, nums2[i]);
                        nums1.pop_back();
                        m++;
                        break;
                    }
                    if (j == m - 1 && !(nums1[j] >= nums2[i])) {
                        nums1.insert(nums1.begin() + (j + 1), nums2[i]);
                        nums1.pop_back();
                        m++;
                        break;
                    }
                }
            }
        }

        for (int i : nums1) {
            cout << i << " ";
        }
    }
};

int main() {
    // testando -- just testing
    Solution solution;
    vector<int> numbers1 {1,2,2,3,5,6,0,0,0};
    vector<int> numbers2 {2,5,6};
    solution.merge(numbers1, 6, numbers2, 3);
    char a;
    cin >> a;
    return 0;
}