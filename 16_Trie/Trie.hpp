#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <string>

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie();
    ~Trie();

    void print() const;
    void insert(const std::string& word);
    bool contains(const std::string& word) const;

    // get next letters - return a stringcontaining alll the next letters 
    // that can follow a given pregix
    // return in alphabeticval order
    std::string getNextLetters(const std::string& prefix) const;
    int countWords() const;

private:
    TrieNode* root;
    int word_count;

    int letterToIndex(char c) const;
    char indexToLetter(int i) const;

    void print(const TrieNode* node, const std::string& s) const;
    void clear(TrieNode* node);
};

#endif
