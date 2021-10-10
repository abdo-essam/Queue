#include <iostream>

using namespace std;

template <typename T>
class Queue {

private:
    int rear;
    int front;
    int length; // number of elements in queue
    int size; // the capacity for queue
    T *arr;

public:
    // default constructor.
    Queue() {
        size = 10 ;
        front = 0;
        length = 0;
        rear = size - 1;
        arr = new T[size];

    }

    // constructs a queue having ‘initial_size’ elements whose values are ‘value’.
    Queue(T element, int size) {
        this->size = size;
        for (int i = 0; i < size; ++i) {
            arr[i] = element;
        }
    }


    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == size;
    }

    // adds an element to the back of the queue.
    void push(T element) {
        if (isFull()) {
            cout << "queue is full " << endl;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = element;
            length++;
        }
    }


    // removes the first element.
    void pop() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
        } else {
            front = (front + 1) % size;
            --length;
        }
    }

    // returns the first element by reference.
    T &getFront() {
        return arr[front];
    }

    // print all elements in the queue.
    void show(){
        if (isEmpty()){
            cout << "queue is empty " <<endl;
        }
        else{
            cout <<"elements : " ;
            for (int i = front; i != rear+1 ; i = (i+1)%size) {
                cout << arr[i] <<" " ;
            }
            cout << endl;
        }

    }

    // returns the number of elements in the queue

    int getSize(){
        return length ;
    }

    // a destructor to clear the queue and leave no memory leaks
    ~Queue(){
        delete[] arr ;
    }

};

int main() {

    return 0;
}