// TODO: Finish the Header

template <typename T, int size = 100>
class QueueArray {
public:
    QueueArray();
    
private: 
    T data[size];
    int front, back;
    
};