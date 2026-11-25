#include <iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;

    Node(char c) : data(c), left(nullptr), right(nullptr){}
};

Node* buildTree(string pre, string in){
    if (pre.empty()) return nullptr;
    char rootValue = pre[0];
    Node* root = new Node(rootValue);
    int pos = in.find(rootValue);
    root->left = buildTree(pre.substr(1, pos),in.substr(0, pos));
    root->right = buildTree(pre.substr(pos + 1),in.substr(pos + 1));
    return root;
}

void postorder(Node* root){
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int height
