#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums2.size(); i++ ) {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        if (nums1.size() % 2 == 0) 
            return double(nums1[nums1.size() / 2] + nums1[(nums1.size() / 2) - 1]) / 2;
        else 
            return nums1[nums1.size() / 2];
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2};
    vector<int> b = {3,4,5,21,2,56,1,24,5};
    cout << s.findMedianSortedArrays(a, b);


    system("pause");
    return 0;
}

/*
    A solução dessa foi na pura intuição mesmo, eu só adicionei os valores do vetor num2 no vetor num1, ordenei, e após isso peguei o centro do vetor.
    Caso o vetor fosse par, ele soma os dois elementos do centro e divide por 2, caso fosse impar ele apenas pega o elemento do centro.

    A solução que o editorial dá (consideravelmente mais inteligente) é de que já que ambos os vetor já estão ordenados não precisamos unir eles
    e ordená-los novamente, basta apenas termos o tamanho de ambos os vetores (m + n) que assim conseguiremos iterar sobre eles e achar seu(s) mediano(s)
    sem ter de utilizar da função sort 
*/