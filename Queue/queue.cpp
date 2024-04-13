#include <iostream>

const int QUEUE_SIZE = 3;

class Queue_array {
    public:
        Queue_array() {
            size = QUEUE_SIZE + 1;
            values = new int[size];
            first = 0;
            last = 0;
        }

        void push(int x) {
            if ((last + 1) % size != first) {
                values[last] = x;
                last = (last + 1) % size;
            } else std::cout << "The queue is full";
        }

        bool empty() {
            return first == last;
        }

        int pop() {
            if (!empty()) {
                int result = values[first];
                first = (first + 1) % size;
                return result;
            }
        }
        ~Queue_array() {
            delete[] values;
        }
    private:
        int *values;
        int first;
        int last;
        int size;
};

class Node {
    public:
    Node *next;
    int value;
};

class Queue_list {
    public:
        Queue_list() {
            first_node = 0;
            last_node = 0;
        }
        bool empty() {
            return first_node == 0;
        } 
        void push(int x) {
            Node *new_node = new Node;
            new_node->value = x;
            new_node->next = 0;
            if (empty()) {
                first_node = new_node;
                last_node = new_node;
            }
            else {
                last_node->next = new_node;
                last_node = new_node;
            }
        }
        int pop() {
            if (!empty()) {
                int result = first_node->value;
                Node *ptr = first_node;
                first_node = first_node->next;
                delete ptr;
                return result;
            } std::cout << "Queue is empty\n";
        }
        ~Queue_list() {
            while (!empty()) pop();
        }
    private:
        Node *first_node;
        Node *last_node;
};

int main() {
    Queue_list q;
    q.pop();
    q.push(1);
    q.push(2);
    std::cout << q.pop() << std::endl;
    q.push(3);
    std::cout << q.pop() << std::endl;
    q.push(4);
    q.push(5);
    q.push(6);
    std::cout << q.pop() << std::endl;
}