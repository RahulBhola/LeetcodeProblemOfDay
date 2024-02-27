#include <iostream>
#include <algorithm> // for max function

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameter(root, res);
        return res;
    }
private:
    int diameter(TreeNode* curr, int &res){
        if(!curr){
            return 0;
        }
        int left = diameter(curr->left, res);
        int right = diameter(curr->right, res);

        res = max(res, left + right);

        return max(left, right) + 1;
    }
};

// Example usage:
int main() {
    Solution sol;

    // Example 1:
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    cout << "Example 1: " << sol.diameterOfBinaryTree(root1) << endl;

    // Example 2:
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    cout << "Example 2: " << sol.diameterOfBinaryTree(root2) << endl;

    return 0;
}
