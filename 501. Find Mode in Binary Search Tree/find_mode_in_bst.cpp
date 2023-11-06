#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int,int> ump;
    vector<int> findMode(TreeNode* root) {
        vector<int> aux;
        if (!root) {
            return {0}; /* só pra satisfazer o compilador */
        }
        if (ump.count(root->val)) {
            ump[root->val]++;
        } else {
            ump.insert({root->val, 1});
        }
        findMode(root->left);
        findMode(root->right);
        int max = 0;
        for (auto kv : ump) {
            if (kv.second > max)
                max = kv.second;
        }
        for (auto kv : ump) {
            if (kv.second == max) {
                if (find(aux.begin(), aux.end(), kv.first) == aux.end()) {
                    aux.push_back(kv.first);
                }
            }
        }
        return aux;
    }
};

/*
--- Testes ---
    

*/

int main() {
    Solution solution;
    TreeNode node1, node2, node3;
    node1.val = 1;
    node2.val = 2;
    node3.val = 2;

    node1.right = &node2;
    node2.left = &node3;

    solution.findMode(&node1);

    system("pause");
    return 0;
}
