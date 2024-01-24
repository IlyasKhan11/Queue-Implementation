#include <iostream>

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        // Implement the Constructor
        size = 10001;
        qfront = 0;
        rear = 0;
        arr = new int[size];
    }

    ~Queue() {
        // Implement the Destructor
        delete[] arr;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return qfront == rear;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (rear == size) {
            std::cout << "The Queue is Full\n";
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if (qfront == rear) {
            return -1; // Queue is empty
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if (qfront == rear) {
            return -1; // Queue is empty
        } else {
            return arr[qfront];
        }
    }
};

int main() {
    // Example usage
    Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    while (!myQueue.isEmpty()) {
        std::cout << "Front element: " << myQueue.front() << std::endl;
        std::cout << "Dequeue: " << myQueue.dequeue() << std::endl;
    }

    return 0;
}
