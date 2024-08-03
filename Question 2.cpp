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

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s)
        return false;

    if (areIdentical(s, t))
        return true;

    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);

    if (isSubtree(root1, root2))
        cout << "The first tree is a subtree of the second one.\n";
    else
        cout << "The first tree is not a subtree of the second one.\n";

    return 0;
}

