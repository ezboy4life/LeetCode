#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int substr_len = 0, lst_index;
        unordered_map<char, int> unmp;

        for (int i = 0; i < s.length(); i++) {
            if (unmp.count(s[i])) {
                if (unmp.size() > substr_len) 
                    substr_len = unmp.size();
                unmp.clear();
                i = lst_index;
            }
            if (!unmp.size())
                lst_index = i + 1;
            unmp.insert({s[i], 1});
        }

        if (unmp.size() > substr_len) 
            substr_len = unmp.size();
        return substr_len;
    }
};

/*
--- Testes ---
    


*/

int main() {
    Solution solution;
    unordered_map<char, int> unmp_test;
    unmp_test.insert({'a', 1});


    cout << "Size: " << solution.lengthOfLongestSubstring("bbbbb") << endl;
    system("pause");
    return 0;
}