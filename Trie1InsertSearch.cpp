#include<bits/stdc++.h>
using namespace std;
 
class Trie 
{
public:
    struct Node 
    {
        Node* children[26];
        bool eow;

        Node() 
        {
            for (int i = 0; i < 26; i++) 
            { 
                children[i] = nullptr;
            }
            eow = false;
        }
    };

    Node* root;

    Trie() 
    {
        root = new Node();
    }

    void insert(string word) { // O(n)
        Node* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->eow = true;
    }

    bool search(string key) { // O(n)
        Node* curr = root;
        for (char c : key) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->eow;
    }

    bool startsWith(string prefix) { // O(n)
        Node* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;
    string words[] = {"the", "a", "there", "their", "any", "thee"};
    
    for (string word : words) {
        trie.insert(word);
        cout << "Inserted " << word << endl;
    }

    cout << "thee -> " << (trie.search("thee") ? "true" : "false") << endl;
    cout << "thor -> " << (trie.search("thor") ? "true" : "false") << endl;

    cout << "Prefix 'the' -> " << (trie.startsWith("the") ? "true" : "false") << endl;
    cout << "Prefix 'thi' -> " << (trie.startsWith("thi") ? "true" : "false") << endl;

    return 0;
}
