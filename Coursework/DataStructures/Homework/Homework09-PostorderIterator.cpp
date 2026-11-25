#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

// 前向声明
template <class Type> class BinaryTree;
template <class Type> class BinTreeNode;

// ==================== 抽象迭代器基类 ====================
template <class Type>
class TreeIterator {
public:
    virtual ~TreeIterator() = default;

    virtual void First() = 0;
    virtual void operator++() = 0;

    // 显式转换为 bool：判断是否有效
    explicit operator bool() const { return current != nullptr; }

    // 返回当前节点数据
    Type& operator()() {
        if (!current) {
            throw runtime_error("WRONG");
        }
        return current->GetData();
    }

protected:
    BinaryTree<Type>& T;
    BinTreeNode<Type>* current;  // 当前节点指针

    // 禁止拷贝
    TreeIterator(const TreeIterator&) = delete;
    TreeIterator& operator=(const TreeIterator&) = delete;

    // 保护构造函数，只能被派生类调用
    TreeIterator(BinaryTree<Type>& bt) : T(bt), current(nullptr) {}
};

// ==================== 二叉树节点定义 ====================
template <class Type>
class BinTreeNode {
private:
    Type data;
    BinTreeNode* left;
    BinTreeNode* right;

public:
    BinTreeNode(const Type& d, BinTreeNode* l = nullptr, BinTreeNode* r = nullptr)
        : data(d), left(l), right(r) {}

    Type& GetData() { return data; }
    BinTreeNode* GetLeft() { return left; }
    BinTreeNode* GetRight() { return right; }

    friend class BinaryTree<Type>;
};

// ==================== 二叉树类定义 ====================
template <class Type>
class BinaryTree {
private:
    BinTreeNode<Type>* root;

    void Destroy(BinTreeNode<Type>* node) {
        if (node) {
            Destroy(node->left);
            Destroy(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { Destroy(root); }

    BinTreeNode<Type>* GetRoot() { return root; }

    void MakeEmpty() { Destroy(root); root = nullptr; }

    // 简单构造树的辅助函数（示例）
    void CreateSampleTree() {
        // 删除现有树
        MakeEmpty();

        root = new BinTreeNode<Type>(1);
        root->left = new BinTreeNode<Type>(2);
        root->right = new BinTreeNode<Type>(3);
        root->left->left = new BinTreeNode<Type>(4);
        root->left->right = new BinTreeNode<Type>(5);
        root->right->right = new BinTreeNode<Type>(6);
    }
};

// ==================== 后序遍历栈节点 ====================
enum Tag {L, R}; // L-左子树退栈；R-右子树退栈

template <class Type>
struct StkNode {
    BinTreeNode<Type> *ptr;
    Tag tag;

    StkNode(BinTreeNode<Type> *p = nullptr, Tag t = L) : ptr(p), tag(t) {}
};

// ==================== 后序遍历游标类 ====================
template <class Type>
class PostOrder : public TreeIterator<Type> {
private:
    stack<StkNode<Type>> st;  // 使用标准 stack

public:
    explicit PostOrder(BinaryTree<Type>& BT)
        : TreeIterator<Type>(BT) {
        First();  // 构造函数中直接初始化到第一个节点
    }

    ~PostOrder() override = default;

    void First() override {
        // 清空栈
        while (!st.empty()) st.pop();

        this->current = nullptr;

        // 移动到第一个可访问的节点
        if (this->T.GetRoot()) {
            operator++();
        }
    }

    void operator++() override {
        BinTreeNode<Type>* p;
        if (st.empty() && this->current == nullptr) {
            // 初始情况：从根节点开始
            p = this->T.GetRoot();
            while (p) {
                st.push(StkNode<Type>(p, L));
                p = p->GetLeft();
            }
        }

        while (!st.empty()) {
            StkNode<Type> w = st.top();
            st.pop();

            switch (w.tag) {
                case L:
                    // 第一次访问，处理右子树
                    //Q1
                    w.tag = R;
                    st.push(w);
                    p = w.ptr->GetRight();
                    while(p){
                        st.push(StkNode<Type>(p, L));
                        p = p->GetLeft();
                    }
                    break;
                case R:
                    // 第二次访问，可以访问该节点
                    //Q2
                    this->current = w.ptr;
                    return;
            }
        }

        // 栈空，遍历结束
        this->current = nullptr;
    }
};

int main() {
    BinaryTree<int> tree;
    tree.CreateSampleTree();  // 构造示例树

    PostOrder<int> postIter(tree);

    cout << "后序遍历结果: ";
    while (postIter) {
        cout << postIter() << " ";  // 访问当前节点数据
        ++postIter;  // 移动到下一个
    }
    cout << endl;

    return 0;
}
