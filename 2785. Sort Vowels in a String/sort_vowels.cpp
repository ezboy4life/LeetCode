#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> indexes;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i]))  {
                vowels.push_back(s[i]);
                indexes.push_back(i);
            }
        }

        sort(vowels.begin(), vowels.end()); 

        for (int i = 0; i < indexes.size(); i++)
            s[indexes[i]] = vowels[i];

        return s;
    }

    bool isVowel(char c) {
        c = tolower(c);
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }
};

int main() {
    Solution solution;
    solution.sortVowels("lEetcOde");

    // system("pause");
    return 0;
}