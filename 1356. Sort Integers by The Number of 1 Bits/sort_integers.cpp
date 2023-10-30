#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int count, aux;
        vector<pair<int, int>> result;
        pair<int, int> p;
        for (int i = 0; i < arr.size(); i++) {
            count = 0;
            aux = arr[i];
            while (aux) {
                if (aux & 1) {
                    count++;
                }
                aux = aux >> 1;
            }
            p.first = count;
            p.second = arr[i];
            result.push_back(p);
        }
        sort(begin(result), end(result));

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = result[i].second;
        }

        return arr;
    }
};

int main() {
    Solution solution;
    vector<int> vetor = { 0,1,2,3,4,5,6,7,8 };

    solution.sortByBits(vetor);

    return 0;
}