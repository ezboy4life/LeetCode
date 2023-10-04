#include <iostream>
#include <string>
#include <algorithm>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string numStr = "", numStr1 = "";
        ListNode* nextVar, prevVar;
        
        do {
            numStr = to_string(l1->val) + numStr;
            l1 = l1->next;
        } while (l1 != 0);

        cout << numStr << " ";

        do {
            numStr1 = to_string(l2->val) + numStr1;
            l2 = l2->next;
        } while (l2 != 0);

        cout << numStr1 << " ";

        return nullptr;
    }
};

/*
--- Testes ---
    
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    Input: l1 = [0], l2 = [0]
    Output: [0]

    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]

*/

int main() {
    Solution solution;
    ListNode ln1;
    ln1.val = 2;
    ListNode ln2;
    ln2.val = 4; 
    ListNode ln3;
    ln3.val = 3;
    ListNode ln4;
    ln4.val = 5;
    ListNode ln5;
    ln5.val = 6; 
    ListNode ln6;
    ln6.val = 4;
    ln1.next = &ln2;
    ln2.next = &ln3;
    ln4.next = &ln5;
    ln5.next = &ln6;

    solution.addTwoNumbers(&ln1,&ln4);

    ListNode* nextVar;

    nextVar = &ln1;
    string numStr = "", numStr1 = "";

    do {
        numStr = to_string(nextVar->val) + numStr;
        nextVar = nextVar->next;
    } while (nextVar != 0);

    cout << numStr << endl;

    nextVar = &ln4;
    do {
        numStr1 = to_string(nextVar->val) + numStr1;
        nextVar = nextVar->next;
    } while (nextVar != 0);

    cout << numStr1 << endl;

    int sum = stoi(numStr) + stoi(numStr1);

    numStr = to_string(sum);

    ListNode* prevVar = NULL;

    for (int i = 0; i < numStr.size() ; i++) {
        nextVar = new ListNode(numStr[i] - '0', prevVar); //ASCII 51 - 48 
        prevVar = nextVar;
    }

    system("pause");
    return 0;
}