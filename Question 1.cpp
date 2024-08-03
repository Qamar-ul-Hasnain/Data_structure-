#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    return (root1->data == root2->data) && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    if (areIdentical(root1, root2))
        cout << "The two binary trees are identical.\n";
    else
        cout << "The two binary trees are not identical.\n";

    return 0;
}

