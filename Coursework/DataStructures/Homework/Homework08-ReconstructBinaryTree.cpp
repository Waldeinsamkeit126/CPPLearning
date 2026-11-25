#include <iostream>
#include <vector>
using namespace std;

// 二叉树节点定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class PreInToTree {
public:
    TreeNode* buildTree(vector<int>& prevect, vector<int>& invect) {
        return build(prevect, 0, prevect.size() - 1,
                    invect, 0, invect.size() - 1);
    }

private:
    TreeNode* build(vector<int>& prevect, int preStart, int preEnd,
                   vector<int>& invect, int inStart, int inEnd) {
      // Q: 根据先序序列prevect和中序序列invect，构造一棵二叉树。
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        int rootVal = prevect[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = inStart;

        while (rootIndex <= inEnd && invect[rootIndex] != rootVal) {
            rootIndex++;
        }
        int leftSize = rootIndex - inStart;
        root->left = build(
            prevect,
            preStart + 1,
            preStart + leftSize,
            invect,
            inStart,
            rootIndex - 1
        );
        root->right = build(
            prevect,
            preStart + leftSize + 1,
            preEnd,
            invect,
            rootIndex + 1,
            inEnd
        );

        return root;
    }
};

// 辅助函数：打印二叉树（前序遍历）
void printPreOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// 辅助函数：打印二叉树（中序遍历）
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // 测试用例
    vector<int> prevect = {3, 9, 20, 15, 7};
    vector<int> invect = {9, 3, 15, 20, 7};

    PreInToTree pitt;
    TreeNode* root = pitt.buildTree(prevect, invect);

    cout << "重建后的二叉树前序遍历: ";
    printPreOrder(root);
    cout << endl;

    cout << "重建后的二叉树中序遍历: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
