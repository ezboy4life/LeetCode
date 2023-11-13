#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) 
                vowels.push_back(s[i]);
        }
        return "a";
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

    cout << ('0' == 49);

    system("pause");
    return 0;
}