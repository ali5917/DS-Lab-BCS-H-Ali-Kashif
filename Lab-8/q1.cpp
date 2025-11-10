#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    string name;
    Node* left;   // mother
    Node* right;  // father
    Node(string s) : name(s), left(nullptr), right(nullptr) {}
};

Node* buildFamily() {
    // constructing a binary tree
    Node* sharifa = new Node("Sharifa");
    Node* usman  = new Node("Usman");
    Node* fatima = new Node("Fatima");
    Node* maqsood  = new Node("Maqsood");

    Node* seema   = new Node("Seema");
    seema->left = sharifa;
    seema->right = usman;

    Node* kashif = new Node("Kashif");
    kashif->left = fatima;
    kashif->right = maqsood;

    Node* ali = new Node("Ali"); // youngest person 
    ali->left = seema;
    ali->right = kashif;

    return ali;
}

void printLeafNodes(Node* root) {
    if (!root) return;
    if (!root->left && !root->right)
        cout << root->name << " ";
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int height(Node* root) {
    if (!root) return -1; 
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

void printLevels(Node* root, int level = 0) {
    if (!root) return;
    cout << root->name << "'s level: " << level << endl;
    printLevels(root->left, level + 1);
    printLevels(root->right, level + 1);
}

int main() {
    Node* root = buildFamily();
    cout << "Root (youngest person): " << root->name << endl;
    cout << "Leaf nodes (ancestors with no known parents): ";
    printLeafNodes(root);
    cout << endl;

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Level of each member:" << endl;
    printLevels(root);
}