#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

template<class K, class V>
struct AVLTreeNode {
    std::pair<K, V> kv;
    AVLTreeNode<K, V>* left;
    AVLTreeNode<K, V>* right;
    AVLTreeNode<K, V>* parent;
    int height; // 节点高度

    AVLTreeNode(const std::pair<K, V>& kv)
        : kv(kv), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
};

template<class K, class V>
class AVLTree {
public:
    typedef AVLTreeNode<K, V> Node;

    AVLTree() : root(nullptr) {}

    // 插入操作
    bool Insert(const std::pair<K, V>& kv) {
        root = Insert(root, kv);
        return true;
    }

    // 删除操作
    bool Erase(const K& key) {
        root = Erase(root, key);
        return true;
    }

    void InOrder() {
        InOrder(root);
        std::cout << std::endl;
    }

    bool IsBalance() {
        return IsBalance(root);
    }

    int Height() {
        return height(root);
    }

private:
    Node* root;

    // 获取节点高度
    int GetHeight(Node* node) {
        return node ? node->height : 0;
    }

    // 更新节点高度
    void UpdateHeight(Node* node) {
        if (node) {
            node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));
        }
    }

    // 获取平衡因子（通过高度计算）
    int GetBalanceFactor(Node* node) {
        if (!node) return 0;
        return GetHeight(node->left) - GetHeight(node->right);
    }

    // 左单旋
    Node* RotateL(Node* parent) {
        Node* subR = parent->right;
        Node* subRL = subR->left;

        subR->left = parent;
        parent->right = subRL;

        UpdateHeight(parent);
        UpdateHeight(subR);

        return subR;
    }

    // 右单旋
    Node* RotateR(Node* parent) {
        Node* subL = parent->left;
        Node* subLR = subL->right;

        subL->right = parent;
        parent->left = subLR;

        UpdateHeight(parent);
        UpdateHeight(subL);

        return subL;
    }

    // 左右双旋
    Node* RotateLR(Node* parent) {
        parent->left = RotateL(parent->left);
        return RotateR(parent);
    }

    // 右左双旋
    Node* RotateRL(Node* parent) {
        parent->right = RotateR(parent->right);
        return RotateL(parent);
    }

    // 平衡节点
    Node* Balance(Node* node) {
        if (node == nullptr) return nullptr;
        UpdateHeight(node);
        int bf = GetBalanceFactor(node);

        if (bf > 1) {
            if (GetBalanceFactor(node->left) >= 0) {
                return RotateR(node);
            } else {
                return RotateLR(node);
            }
        }

        if (bf < -1) {
            if (GetBalanceFactor(node->right) <= 0) {
                return RotateL(node);
            } else {
                return RotateRL(node);
            }
        }
        return node;
    }

    // 递归插入
    Node* Insert(Node* node, const std::pair<K, V>& kv) {
        if (!node) return new Node(kv);

        if (kv.first < node->kv.first) {
            node->left = Insert(node->left, kv);
        } else if (kv.first > node->kv.first) {
            node->right = Insert(node->right, kv);
        } else {
            return node; // 键已存在
        }

        return Balance(node);
    }

    // 递归删除
    Node* Erase(Node* node, const K& key) {
        if (!node) return nullptr;

        if (key < node->kv.first) {
            node->left = Erase(node->left, key);
        } else if (key > node->kv.first) {
            node->right = Erase(node->right, key);
        } else {
            // 找到要删除的节点
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp; // 拷贝内容
                }
                delete temp;
            } else {
                // 有两个孩子，找右子树最左节点
                Node* temp = FindMin(node->right);
                node->kv = temp->kv;
                node->right = Erase(node->right, temp->kv.first);
            }
        }

        return Balance(node);
    }

    // 找最小节点
    Node* FindMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    void InOrder(Node* root) {
        if (root == nullptr) return;
        InOrder(root->left);
        std::cout << root->kv.first << ":" << root->kv.second << " ";
        InOrder(root->right);
    }

    int height(Node* root) {
        if (root == nullptr) return 0;
        return root->height;
    }

    bool IsBalance(Node* root) {
        if (root == nullptr) return true;

        int balanceFactor = GetBalanceFactor(root);
        if (balanceFactor > 1 || balanceFactor < -1) {
            std::cout << "不平衡节点:" << root->kv.first << " 平衡因子:" << balanceFactor << std::endl;
            return false;
        }

        return IsBalance(root->left) && IsBalance(root->right);
    }
};

int main() {
    AVLTree<int, int> tree;

    std::cout << "AVL树插入测试:" << std::endl;
    std::vector<int> testData = {10, 20, 30, 40, 50, 25, 5, 15, 35, 45};

    for (int val : testData) {
        tree.Insert(std::make_pair(val, val * 10));
        std::cout << "插入 " << val << " 后树高: " << tree.Height() << std::endl;
    }

    std::cout << "\n中序遍历结果: ";
    tree.InOrder();
    std::cout << "树是否平衡: " << (tree.IsBalance() ? "是" : "否") << std::endl;

    std::cout << "\n删除测试:" << std::endl;
    tree.Erase(30);
    std::cout << "删除30后中序遍历: ";
    tree.InOrder();
    std::cout << "树是否平衡: " << (tree.IsBalance() ? "是" : "否") << std::endl;

    tree.Erase(40);
    std::cout << "删除40后中序遍历: ";
    tree.InOrder();
    std::cout << "树是否平衡: " << (tree.IsBalance() ? "是" : "否") << std::endl;

    std::cout << "\n最终树高: " << tree.Height() << std::endl;

    return 0;
}
