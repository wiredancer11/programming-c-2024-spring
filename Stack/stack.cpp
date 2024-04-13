#include <iostream>

class Stack_array {
    private:
        double *values;
        int i;
    public:
        Stack_array(int size) {
            values = new double[size];
            i = 0;
        }
        bool is_empty() {
            return i == 0;
        }

        void push(double x) {
            values[i] = x;
            i++;
        }
        double pop() {
            if (!is_empty()) {
                i--;
                return values[i];
            }
        }
};

class Node {
    public:
    Node *next;
    double value;
};

class Stack_list {
    public:
    Node *first;
    Stack_list() {
        first = 0;
    }
    void push(double x) {
        Node *ptr;
        ptr = first;
        first = new Node;
        first->value = x;
        first->next = ptr;
    }
    bool is_empty() {
       return first == 0;
    }
    double pop() {
        if (!is_empty()) {
            Node *ptr;
            double value = first->value;
            ptr = first;
            first = first->next;
            delete ptr;
            return value;
        };
    }
};

int main() {
    Stack_array stack(10); 
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    stack.push(88);
    std::cout << stack.pop() << std::endl;
}