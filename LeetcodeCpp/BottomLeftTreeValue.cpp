#include <iostream>
#include <queue>
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftValue;

        while (!q.empty()) {
            int levelSize = q.size();
            bool firstInLevel = true;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (firstInLevel) {
                    leftValue = node->val;
                    firstInLevel = false;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return leftValue;
    }
};

// Function to create a new node
TreeNode* newNode(int val) {
    TreeNode* temp = new TreeNode(val);
    return temp;
}

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(3);
    cout << "Output for Example 1: " << solution.findBottomLeftValue(root1) << endl; // Output: 1

    // Example 2
    TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->right->left = newNode(5);
    root2->right->right = newNode(6);
    root2->right->left->left = newNode(7);
    cout << "Output for Example 2: " << solution.findBottomLeftValue(root2) << endl; // Output: 7

    return 0;
}
