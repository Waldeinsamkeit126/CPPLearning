#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class BinarySearchTree {
private:
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    void insertHelper(TreeNode*& node, const T& val) {
        if (!node) {
            node = new TreeNode(val);
        } else if (val < node->data) {
            insertHelper(node->left, val);
        } else if (val > node->data) {
            insertHelper(node->right, val);
        }
    }

    void destroyTree(TreeNode* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { destroyTree(root); }

  TreeNode* getRoot(){ return root; }

    void insert(const T& val) { insertHelper(root, val); }

    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

   int depth(TreeNode* node){
     // Q1: 求树的深度
     if (node == nullptr) return 0;
     int leftDepth = depth(node->left);
     int rightDepth = depth(node->right);
     return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
   }

  int average(TreeNode* node){
    // Q2: 求树上所有节点值的平均值
    if (node == nullptr){
        return 0;
    }
    int sum = 0;
    int count = 0;
    stack<TreeNode*> s;
    s.push(node);
    while (!s.empty()){
        TreeNode* p = s.top();
        s.pop();
        sum += p->data;
        count++;
        if (p->left != nullptr) s.push(p->left);
        if (p->right != nullptr) s.push(p->right);
    }
    return sum/count;
  }
};

int main() {
    BinarySearchTree<int> bst;
    int values[] = {5, 12, 4, 45, 32, 8, 10, 50, 32, 3};

    for (int val : values) {
        bst.insert(val);
    }

    // 中序遍历验证有序性
    std::cout << "Inorder traversal: ";
    bst.inorderTraversal(bst.getRoot());
    cout << endl;

    cout << "The depth of the tree is: " << bst.depth(bst.getRoot()) << endl;

    cout << "The average of the tree is: " << bst.average(bst.getRoot()) << endl;
    return 0;
}
