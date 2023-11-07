#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int eliminatedMonsters = 0;
        vector<double> time;

        for (int i = 0; i < dist.size(); i++) {
            time.push_back(double(dist[i]) / double(speed[i]));
        }
        sort(time.begin(), time.end());

        while (eliminatedMonsters != dist.size()) {
            time.erase(time.begin());
            eliminatedMonsters++;
            for (int i = 0; i < time.size(); i++) {
                time[i] -= 1;
                if (time[i] <= 0)
                    return eliminatedMonsters;
            }
        }
        return eliminatedMonsters;
    }
};

int main() {
    Solution solution;
    vector<int> d = {1,3,4};
    vector<int> s = {1,1,1};
    cout << solution.eliminateMaximum(d, s);


    system("pause");
    return 0;
}

/* A solução atual de momento FUNCIONA. Mas pros parâmetros do LeetCode aparentemente ele precisa ser mais eficiente. Vou ver o que faço depois :b */
