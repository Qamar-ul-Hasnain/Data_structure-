#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

int maxSumPath(TreeNode* root, int& maxSum) {
    if (!root)
        return 0;

    int leftSum = maxSumPath(root->left, maxSum);
    int rightSum = maxSumPath(root->right, maxSum);

    int currentSum = max(root->data, max(root->data + leftSum, root->data + rightSum));

    maxSum = max(maxSum, max(currentSum, root->data + leftSum + rightSum));

    return currentSum;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(-4);
    root->right->right = new TreeNode(10);
    root->right->right->left = new TreeNode(7);

    int maxSum = INT_MIN;
    maxSumPath(root, maxSum);

    cout << "Maximum Sum Path from Leaf to Root: " << maxSum << endl;

    return 0;
}

