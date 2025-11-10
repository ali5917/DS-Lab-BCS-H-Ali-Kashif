#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int playCount;
    string songName;
    Node* left;
    Node* right;
    Node(int count, string name) : playCount(count), songName(name), left(nullptr), right(nullptr) {}
};

class MusicBST {
public:
    Node* root;
    MusicBST() : root(nullptr) {}

    Node* insert(Node* root, int count, string name) {
        if (!root) return new Node(count, name);
        if (count < root->playCount)
            root->left = insert(root->left, count, name);
        else
            root->right = insert(root->right, count, name);
        return root;
    }

    void insertSong(int count, string name) {
        root = insert(root, count, name);
    }

    Node* search(Node* root, int count) {
        if (!root || root->playCount == count)
            return root;
        if (count < root->playCount)
            return search(root->left, count);
        return search(root->right, count);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->songName << " (" << root->playCount << ") ";
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->songName << " (" << root->playCount << ") ";
    }

    Node* findMin(Node* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int count) {
        if (!root) return root;
        if (count < root->playCount)
            root->left = deleteNode(root->left, count);
        else if (count > root->playCount)
            root->right = deleteNode(root->right, count);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->playCount = temp->playCount;
            root->songName = temp->songName;
            root->right = deleteNode(root->right, temp->playCount);
        }
        return root;
    }

    void deleteSong(int count) {
        root = deleteNode(root, count);
    }
};

int main() {
    MusicBST playlist;
    // inserting songs
    playlist.insertSong(50, "Shape of You");
    playlist.insertSong(30, "Perfect");
    playlist.insertSong(70, "Blinding Lights");
    playlist.insertSong(20, "Peaches");
    playlist.insertSong(40, "Stay");
    playlist.insertSong(60, "Levitating");
    playlist.insertSong(80, "Senorita");

    cout << "Inorder (least to most played): ";
    playlist.inorder(playlist.root);
    cout << endl;

    cout << "Postorder (reverse popularity order): ";
    playlist.postorder(playlist.root);
    cout << endl;

    // searching for a particular song
    int searchKey = 60;
    Node* found = playlist.search(playlist.root, searchKey);
    if (found)
        cout << "Found: " << found->songName << " (" << found->playCount << " plays)" << endl;
    else
        cout << "Song with " << searchKey << " plays not found." << endl;

    // deleting a song
    cout << "\nDeleting song with 70 plays...\n";
    playlist.deleteSong(70);

    cout << "Updated Inorder: ";
    playlist.inorder(playlist.root);
    cout << endl;
}