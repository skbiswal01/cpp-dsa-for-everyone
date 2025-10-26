#ifndef QueueADT_hpp
#define QueueADT_hpp

template <typename T>
class QueueADT {
public:
    virtual void enqueue(T x) = 0;
    virtual T dequeue() = 0;
    virtual T frontElement() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void display() = 0;

    virtual ~QueueADT() {} // virtual destructor
};

#endif
