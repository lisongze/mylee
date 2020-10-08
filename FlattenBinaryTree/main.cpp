#include <iostream>
#include <memory>

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* f(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode* left_link = f(root->left);
        TreeNode* right_link = f(root->right);

        if (left_link != nullptr)
        {
            // if (right_link != nullptr)
            left_link->right = root->right;
            left_link->left = nullptr;
            root->right = root->left;
            root->left = nullptr;
        }

        if (right_link != nullptr)
            return right_link;
        else if (right_link == nullptr && left_link != nullptr)
            return left_link;
        else
            return root;
    }
    void flatten(TreeNode* root) {
        f(root);
    }
};

TreeNode* ConstructBinaryTree()
{
    // [1,2,5,3,4,null,6]
    // 1
    TreeNode* root = new TreeNode(1);

    // 1->left = 2, 1->right = 5
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(5);
    root->left = node2;
    root->right = node5;

    // 2->left = 3, 2->right = 4
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    node2->left = node3;
    node2->right = node4;

    // 5->right = 6
    TreeNode* node6 = new TreeNode(6);
    node5->right = node6;

    return root;
}

void DFSPrint(TreeNode* root)
{
    if (root != nullptr)
    {
        std::cout << root->val << std::endl;
    }
    else
    {
        return;
    }

    DFSPrint(root->left);
    DFSPrint(root->right);
}

int main(int argc, char* argv[])
{
    TreeNode* root = ConstructBinaryTree();
    // DFSPrint(root);

    Solution solution;
    solution.flatten(root);

    DFSPrint(root);

    return 0;
}