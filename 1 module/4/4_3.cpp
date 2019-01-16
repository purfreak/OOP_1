#include <iostream>


class Stack {
public:
    Stack(): buffersize(0), realsize(0), buffer(nullptr) {};
    ~Stack() { delete[] buffer; }
    void push(int);
    int pop();
    bool const is_empty() { return realsize == 0; };
    int const get_size() { return realsize; };
private:
    void grow_buffer();
    int buffersize;
    int realsize;
    int* buffer;
};


void Stack::grow_buffer() {
    if (!buffer) {
        buffer = new int[1];
        buffersize = 1;
    } else {
        int* new_buffer = new int[buffersize*2];
        for (int i = 0; i < realsize; ++i) {
            new_buffer[i] = buffer[i];
        }

        buffersize *= 2;
        delete[] buffer;
        buffer = new_buffer;
    }
}

int Stack::pop() {
    int retval = buffer[realsize - 1];
    realsize--;
    return retval;
}

void Stack::push(int value) {
    realsize++;
    if (realsize > buffersize) {
        grow_buffer();
    }
    buffer[realsize - 1] = value;
}


class Queue {
public:
    Queue(): state(true) {};
    void push(int);
    void pop(int);
    bool get_state() { return state; };
private:
    Stack left_stack;
    Stack right_stack;
    bool state;
    void move_left_to_right();
};


void Queue::push(int value) {
    left_stack.push(value);
}

void Queue::pop(int b) {
    if (right_stack.get_size() + left_stack.get_size() == 0) {
        if (b != -1) {
            state = false;
        }
    } else {
        if (right_stack.is_empty()) {
            move_left_to_right();
        }
    int tmp = right_stack.pop();
    if (tmp != b) {
        state = false;
    }
    }
}

void Queue::move_left_to_right() {
    while (left_stack.get_size()) {
        right_stack.push(left_stack.pop());
    }
}


int main() {
    int n = 0;
    std::cin >> n;
    Queue q;
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;

        if (a == 2) {
            q.pop(b);
        } else if (a == 3) {
            q.push(b);
        }
    }

    if (q.get_state()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
