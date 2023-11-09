#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // cout << numRows / 2;
        // cout << numRows + (numRows / 2);
        for (int i = 0; i < s.size(); i = i + numRows + (numRows / 2)){
            cout << s[i];
        }

        return "a";
    }
};

int main() {
    Solution solution;
    solution.convert("PAYPALISHIRING", 3);
    
    system("pause");
    return 0;
}