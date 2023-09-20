#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> uniqueNums = {};

        for (vector<int>::iterator i = nums.begin(); i != nums.end();) {
            if (find(uniqueNums.begin(), uniqueNums.end(), *i) == uniqueNums.end()) {   //se tem
                cout << " + ADC: " << *i << endl;
                uniqueNums.push_back(*i);
                i++;
            } else {
                cout << " - REM: " << *i << endl;
                i = nums.erase(i);
            }
            system("pause");
        }
        cout << endl << "Vetor: ";
        for (int i = 0; i < uniqueNums.size(); i++) {
            cout << uniqueNums[i] << " ";
        }
        return uniqueNums.size();
    }
};

int main() {
    Solution solution;
    vector<int> vetor = {1,2,2};
    int qtdNums = solution.removeDuplicates(vetor);
    cout << endl << "Qtd de n unicos: " << qtdNums << endl;
    vetor = {0,0,1,1,1,2,2,3,3,4};
    qtdNums = solution.removeDuplicates(vetor);
    cout << endl << "Qtd de n unicos: " << qtdNums << endl;
    system("pause");
}