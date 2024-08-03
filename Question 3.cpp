#include <iostream>


using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

bool isBSTUtil(TreeNode* root, int minValue, int maxValue) {
    if (!root)
        return true;

    if (root->data < minValue || root->data > maxValue)
        return false;

    return isBSTUtil(root->left, minValue, root->data - 1) && isBSTUtil(root->right, root->data + 1, maxValue);
}

bool isBinarySearchTree(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    if (isBinarySearchTree(root))
        cout << "The tree is a binary search tree.\n";
    else
        cout << "The tree is not a binary search tree.\n";

    return 0;
}

