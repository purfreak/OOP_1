#include <iostream>


class Deque {
public:
    Deque();
    ~Deque() {
        delete[] buffer;
    };
    void pushFront(int);
    void popFront(int);
    void pushBack(int);
    void popBack(int);
    bool showState();
private:
    void createBuffer();
    bool isEmpty();
    bool state;
    int realsize, buffersize;
    int tail, head;
    int *buffer;
};

Deque::Deque () {
    tail = 0;
    head = 0;
    realsize = 0;
    buffersize = 0;
    state = true;
    buffer = nullptr;
}
void Deque::createBuffer() {
    if (buffersize == 0) {
        buffer = new int [1];
        buffersize = 1;
    }
    else {
        int *newBuf = new int [buffersize*2];
        for (int i = 0; i < buffersize; i++) {
            newBuf[i] = buffer[(head + i)%buffersize];
        }
        tail = buffersize - 1;
        head = 0;
        buffer = newBuf;
        buffersize *= 2;
    }
}
bool Deque::isEmpty () {
    return realsize == 0;
}
void Deque::pushBack (int value) {
    realsize++;
    if (realsize > buffersize) {
        createBuffer();
    }
    tail = (tail + 1) % buffersize;
    buffer[tail] = value;
}
void Deque::popBack(int value) {
    if (!isEmpty()) {
        if (value != buffer[tail]) {
            state = false;
        }
        tail = (buffersize + tail - 1) % buffersize;
        realsize--;
    }
    else {
        if (value != -1) {
            state = false;
        }
    }
}
void Deque::popFront(int value) {
    if (!isEmpty()) {
        if (value != buffer[head]) state = false;
        head = (head + 1) % buffersize;
        realsize--;
    }
    else {
        if (value != -1) {
            state = false;
        }
    }
}
void Deque::pushFront (int value) {
    realsize++;
    if (realsize > buffersize) {
        createBuffer();
    }
    head = (buffersize + head - 1) % buffersize;
    buffer[head] = value;
}
bool Deque::showState () {
    return state;
}

int main()
{
    int n;
    std::cin >> n;
    Deque deque;
    for (int i = 0; i < n; i++) {
        int number;
        int value;
        std::cin >> number >> value;
        switch (number) {
            case 1:
                deque.pushFront(value);
                break;
            case 2:
                deque.popFront(value);
                break;
            case 3:
                deque.pushBack(value);
                break;
            case 4:
                deque.popBack(value);
                break;
            default:
                break;
        };
    }
    if (deque.showState()) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

    std::cout << std::endl;
}
