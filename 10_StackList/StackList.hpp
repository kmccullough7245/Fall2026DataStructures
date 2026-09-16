#ifndef STACKLIST_HPP
#define STACKLIST_HPP


template <typename T>
class StackList {
public:
    StackList();
    ~StackList();

    void        push(const T& val);
    bool        empty() const;
    void        print() const;
    T           pop();
    const T&    top() const;
    
private:

};

#endif