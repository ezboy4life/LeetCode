#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<vector<char>> matrix(numRows);
        int j = 0, inc = 1;
        string result;
        for (int i = 0; i < s.size(); i++){
            matrix[j].push_back(s[i]);
            if (j == numRows - 1) 
                inc = -1;
            if (!j) 
                inc = 1;
            j = j + inc;
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                result.push_back(matrix[i][j]);
            }
        }

        return result;
    }
};

/*
    --- Testes ---
    -> 01

    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"
    
    -> 02

    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:
    P     I    N
    A   L S  I G
    Y A   H R
    P     I

*/

int main() {
    Solution solution;
    solution.convert("AB", 1);
    
    system("pause");
    return 0;
}