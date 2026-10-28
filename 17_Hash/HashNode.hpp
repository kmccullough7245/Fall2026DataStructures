#ifndef HASHNODE_HPP
#define HASHNODE_HPP

template <typename t>
class HashNode {
public:
    HashNode(int key, const T& value) : key(key), value(value) {

    }

    int key;
    T value;

};

#endif