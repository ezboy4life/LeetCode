#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int count = 0;
        int num;

        /*
            --- TESTES ---
 
            Input: nums = [1,1,4,2,3], x = 5
            Output: 2
            - pegou 3
            - 5 - 3 >= 0 == true
            - true: x == 2 | count = 1
            - pegou 2
            - 2 - 2 >= 0 == true
            - true: x == 0 | count = 2
            sai do while e retorna 2


            Input: nums = [5,6,7,8,9], x = 4
            Output: -1
            - pegou 9
            - 4 - 9 >= 0 == false
            - else: pegou 5
            - 4 - 5 >= 0 == false
            - Retorna -1
            ~ Errado pois pode ter o 4 no index 1. Ou talvez esteja certo ? 

            Input: nums = [3,2,20,1,1,3], x = 10
            Output: 5
            - pegou 3 (esquerda)
            - 10 - 3 >= 0 == true
            - true: x == 7 | count == 1
            - pegou 3 (direita)
            - 7 - 3 >= 0 == true
            - true: x == 4 | count == 2
            - pegou 2 (esquerda)
            - 4 - 2 >= 0 == true
            - true: x == 2 | count == 3
            - pegou 20 (esquerda)
            - 2 - 20 >= 0 == false
            - false: deixa o 20 e pega o 1 (direita)
            - 2 - 1 >= 0 == true
            - true: x == 1 | count == 4
            - pegou 20 (esquerda)
            - 1 - 20 >= 0 == false
            - false: deixa o 20 e pega 1 (direita)
            - 1 - 1 >= 0 == true
            - x == 0 | count == 5
            - Sai do While e retorna 5
            ~ Correto também aparentemente.

            Input: nums [300], x = 200
            Output: -1;
            - pega 300 (dir/esq)
            - 250 - 300 >= 0 == false;
            - false: pega 300 de novo pois ser o único
            - 250 - 300 >= 0 == false;
            - false: Retorna -1. Correto tbm aparentemente

            Input: nums [10,1,10,10,10], x = 40
            Output: 4
            - pega 10 (direita)
            - 40 - 10 >= 0 == true
            - true: x == 30 | count == 1
            - pega 10 (direita)
            - 30 - 10 >= 0 == true;
            - true: x == 20 | count == 2
            - pega 10 (direita)
            - 20 - 10 >= 0 == true
            - true: x == 10 | count == 3
            - pega 10 (esquerda)
            - 10 - 10 >= 0 == true
            - true: x == 0; count == 4
            - Retorna 4 (aparentemente certo)

            Input: nums [2,2,2,2,2,9], x == 10
            Output: 5
            - pega 9 (direita)
            - 10 - 9 >= 0 == true
            - true: x == 1 | count == 1;
            - pega 2 (direita)
            - 1 - 2 >= 0 == false
            - pega 2 (direita) ~ Comportamento errado
            - 1 - 2 >= 0 == false
            - retorna -1
            ~ Deveria ter retornado 5
        */

        while (x > 0) {
            if (nums.front() > nums.back()) {
                num = nums.front();
                nums.erase(nums.begin());
            } else {
                num = nums.back();
                nums.erase(nums.end());
            }

            if (x - num >= 0) {
                x -= num;
                count++;
            } else {
                num = nums.back();
                if (x - num >= 0) {
                    x -= num;
                    count++;
                } else {
                    return -1;
                }
            }

        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> vetor = {1,1,4,2,3};    //retorno 2
    int qtd = solution.minOperations(vetor, 5);
    cout << "Qtd de Operacoes: " << qtd << endl << endl;

    vetor = {5,6,7,8,9};    //retorno -1
    qtd = solution.minOperations(vetor, 4);
    cout << "Qtd de Operacoes: " << qtd << endl << endl;

    vetor = {3,2,20,1,1,3};    //retorno 5
    qtd = solution.minOperations(vetor, 10);
    cout << "Qtd de Operacoes: " << qtd << endl << endl;

    vetor = {10,1,10,10,10};    //retorno 4
    qtd = solution.minOperations(vetor, 40);
    cout << "Qtd de Operacoes: " << qtd << endl << endl;

    vetor = {2,2,2,2,2,9};    //retorno -1 => deveria ser 5
    qtd = solution.minOperations(vetor, 40);
    cout << "Qtd de Operacoes: " << qtd << endl << endl;


    system("pause");
    return 0;
}