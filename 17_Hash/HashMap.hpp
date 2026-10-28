#ifndef HASHMAP_HPP
#define HASHMAP_HPP

template <typename t>
class HashMap {
public:
    HashMap(int capacity = 31);
    void insert(int key, const T& value);
    void print() const;

private:
    std::vector<HashNode<T>> data;
    int size;
    int hash(int key) const;
};

#endif