#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;

// 哈夫曼树节点结构
struct HuffmanNode {
    char ch;           // 字符
    int freq;          // 频率
    HuffmanNode* left;
    HuffmanNode* mid;
    HuffmanNode* right;
    bool isDummy;

    HuffmanNode(char c, int f, bool dummy = false) : ch(c), freq(f), left(nullptr), mid(nullptr), right(nullptr), isDummy(dummy) {}
};

// 比较函数，用于优先队列
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// 构建哈夫曼树
HuffmanNode* buildHuffmanTree(const map<char, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // 将字符频率加入优先队列
    for (auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }
    if (pq.size() % 2 == 0) {
        pq.push(new HuffmanNode('\0', 0, true));
    }
    // 构建哈夫曼树
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* mid = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq + mid->freq);
        parent->left = left;
        parent->mid = mid;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}

// 生成哈夫曼编码表
void generateCodes(HuffmanNode* root, string code, map<char, string>& huffmanCode) {
    if (!root) return;

    // 叶子节点，存储编码
    if (!root->left && !root->right && !root->mid) {
        if(!root->isDummy){
            huffmanCode[root->ch] = code;
        }
        return;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->mid, code + "1", huffmanCode);
    generateCodes(root->right, code + "2", huffmanCode);
}

// 编码字符串
string encodeString(const string& text, const map<char, string>& huffmanCode) {
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode.at(ch);
    }
    return encoded;
}

// 解码字符串
string decodeString(const string& encoded, HuffmanNode* root) {
    string decoded = "";
    HuffmanNode* current = root;

    for (char bit : encoded) {
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->mid;
        }else {
            current = current->right;
        }

        // 到达叶子节点
        if (!current->left && !current->right && !current->mid) {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}

// 统计字符频率
map<char, int> countFrequency(const string& text) {
    map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }
    return freqMap;
}

// 打印编码表
void printHuffmanCodes(const map<char, string>& huffmanCode) {
    cout << "Huffman Table" << endl;
    cout << "char\tfreq\tcode" << endl;
    for (auto& pair : huffmanCode) {
        cout << pair.first << "\t\t" << pair.second << endl;
    }
}

int main() {
    string text = "this is an example of huffman encoding";

    cout << "原始文本: " << text << endl;
    cout << "原始大小: " << text.length() * 8 << " bits" << endl << endl;

    // 统计字符频率
    map<char, int> freqMap = countFrequency(text);

    // 构建哈夫曼树
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // 生成编码表
    map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    printHuffmanCodes(huffmanCode);
    cout << endl;

    // 编码文本
    string encoded = encodeString(text, huffmanCode);
    cout << "编码后: " << encoded << endl;
    cout << "编码大小: " << encoded.length() << " bits" << endl;

    // 计算压缩率
    double compressionRatio = (1.0 - (double)encoded.length() / (text.length() * 8)) * 100;
    cout << "压缩率: " << compressionRatio << "%" << endl << endl;

    // 解码文本
    string decoded = decodeString(encoded, root);
    cout << "解码后: " << decoded << endl;

    // 验证正确性
    if (text == decoded) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    return 0;
}
