#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// A Huffman Tree node
struct Node {
    char ch;               // Character
    int freq;              // Frequency of the character
    Node *left, *right;    // Left and right children

    // Constructor for creating a new node
    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue, to sort nodes by frequency
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to generate Huffman codes by traversing the Huffman tree
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // Leaf node: store character and its code
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    // Traverse left and right children
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Function to build the Huffman Tree and generate codes
unordered_map<char, string> buildHuffmanTree(const vector<char>& characters, const vector<int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create a leaf node for each character and add it to the priority queue
    for (size_t i = 0; i < characters.size(); i++) {
        minHeap.push(new Node(characters[i], frequencies[i]));
    }

    // Iterate until there is only one node in the heap
    while (minHeap.size() > 1) {
        // Remove the two nodes with the highest priority (lowest frequency)
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes
        int sum = left->freq + right->freq;
        Node *internalNode = new Node('\0', sum);
        internalNode->left = left;
        internalNode->right = right;

        // Add the new node to the heap
        minHeap.push(internalNode);
    }

    // Root of the Huffman Tree
    Node* root = minHeap.top();

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    return huffmanCode;
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> characters;
    vector<int> frequencies;

    cout << "Enter the characters and their frequencies:" << endl;
    char char1;
    int num1;
    for (int i = 0; i < n; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> char1;
        characters.push_back(char1);

        cout << "Frequency for " << char1 << ": ";
        cin >> num1;
        frequencies.push_back(num1);
    }

    // Build Huffman Tree and get Huffman Codes
    unordered_map<char, string> huffmanCode = buildHuffmanTree(characters, frequencies);

    // Output Huffman Codes
    cout << "\nHuffman Codes for each character:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}
