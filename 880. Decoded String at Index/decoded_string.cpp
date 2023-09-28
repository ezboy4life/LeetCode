#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string tape;
        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i])) {
                tape.push_back(s[i]);
            } else {
                string currentTape = tape;
                for (int j = 0; j < int(s[i]) - 49; j++) {
                    tape += currentTape;
                } 
            }
        }
        tape = tape[k - 1];
        return tape;
    }
};

/*  --- Testes ---

    Input: s = "leet2code3", k = 10
    Output: "o"
    OK

    Input: s = "ha22", k = 5
    Output: "h"
    OK

    Input: s = "a2345678999999999999999", k = 1
    Output: "a"
    ~ excede limite de memória do leetcode 

    OBS: Ao invés de simplesmente fazer na força bruta eu acho que esse desafio é mais uma questão de enteder as relações entre o tamanho da string e a qtd de vezes que ela repete

*/

int main() {
    Solution solution;
    string str = "leet2code3";
    int num = 10;
    string result = solution.decodeAtIndex(str, num);   //retorno: 'o'.

    system("pause");
    return 0;
}