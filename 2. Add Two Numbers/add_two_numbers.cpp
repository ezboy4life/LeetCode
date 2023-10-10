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
        ListNode* result = new ListNode();
        ListNode* aux = result;
        bool carry = 0;
        int sum;

        while (l1 || l2 || carry) {
            
            sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (carry) {
                sum += carry;
                carry = 0;
            }

            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            
            ListNode* newNode = new ListNode(sum);
            aux->next = newNode;
            aux = newNode;
        }

        return result->next;
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

    [9]
    [1,9,9,9,9,X,9,9,9,9]

*/

int main() {


    cout << stod("9999999991");

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

    // ListNode ln7;
    // ln7.val = 9;
    // ListNode ln8;
    // ln8.val = 9;
    // ListNode ln9;
    // ln9.val = 9; 
    // ListNode ln10;
    // ln10.val = 9;

    // ListNode ln11;
    // ln11.val = 9;

    ln1.next = &ln2;
    ln2.next = &ln3;
    // ln3.next = &ln4;
    ln4.next = &ln5;
    ln5.next = &ln6;
    // ln6.next = &ln7;
    // ln7.next = &ln8;
    // ln8.next = &ln9;
    // ln9.next = &ln10;
    


    ListNode* resultado = solution.addTwoNumbers(&ln1,&ln4);

    system("pause");
    return 0;
}

/*
    O problema consiste em somar os números 1 por 1 e ir criando os ListNodes dessa maneira, não fazend a soma de força bruta e depois convertendo ele em um ListNode! =)
*/