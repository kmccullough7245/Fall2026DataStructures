#include "Trie.hpp"
#include <iostream>
#include <string>

Trie::Trie() {
    root = new TrieNode();
    word_count = 0;
}

Trie::~Trie() {
    clear(root);
}

void Trie::clear(TrieNode* node) {
    if (!node) return;

    for (int i = 0; i < 26; i++) {
        clear(node->children[i]);
    }

    delete node;
}

void Trie::print() const {
    std::string s;
    print(root, s);
}

int Trie::letterToIndex(char c) const {
    return c - 'a';
}

char Trie::indexToLetter(int index) const {
    return 'a' + index;
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;

    for (char c : word) {
        int index = letterToIndex(c);

        if (index < 0 || index >= 26) {
            return;
        }

        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }

        current = current->children[index];
    }

    if (!current->isEndOfWord) {
        current->isEndOfWord = true;
        word_count++;
    }
}

void Trie::print(const TrieNode* node, const std::string& s) const {
    if (!node) return;

    if (node->isEndOfWord) {
        std::cout << s << std::endl;
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            print(node->children[i], s + indexToLetter(i));
        }
    }
}

bool Trie::contains(const std::string& word) const {
    TrieNode* current = root;

    for (char c : word) {
        int index = letterToIndex(c);

        if (index < 0 || index >= 26) {
            return false;
        }

        if (current->children[index] == nullptr) {
            return false;
        }

        current = current->children[index];
    }

    return current->isEndOfWord;
}

std::string Trie::getNextLetters(const std::string& prefix) const {
    std::string result;
    TrieNode* current = root;

    for (char c : prefix) {
        int index = letterToIndex(c);

        if (index < 0 || index >= 26) {
            return result;
        }

        if (current->children[index] == nullptr) {
            return result;
        }

        current = current->children[index];
    }

    for (int i = 0; i < 26; i++) {
        if (current->children[i]) {
            result += indexToLetter(i);
        }
    }

    return result;
}
int Trie::countWords() const { return word_count; } 