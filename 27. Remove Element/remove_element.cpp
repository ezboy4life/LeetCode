#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int notEqual = 0;
            vector<int> indexesToBeRemoved;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == val) {
                    indexesToBeRemoved.push_back(i);
                } else {    
                    notEqual++;
                }
            }
            vector<int>::iterator ptr = nums.begin();
            for (int i = 0; i < indexesToBeRemoved.size(); i++) {
                nums.erase(ptr + indexesToBeRemoved[i] - i);
            }
            return notEqual;
        };
};

int main() {
    Solution solution;
    vector<int> vetor = {0,1,2,2,3,0,4,2};

    cout << solution.removeElement(vetor, 2) << endl << "Vetor: ";

    for (int i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl << endl;

    vetor = {3,2,2,3};

    cout << solution.removeElement(vetor, 3) << endl << "Vetor: ";

    for (int i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }

    system("pause");

    return 0;
}