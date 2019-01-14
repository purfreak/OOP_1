#include <iostream>


class CQueue {
public:
    CQueue();
    ~CQueue() {
        delete[] buffer;
    };
    void popFront(int);
    void pushBack(int);
    bool showState();
private:
    void createBuffer();
    bool isEmpty();
    bool state;
    int realsize, buffersize;
    int tail, head;
    int *buffer;
};

CQueue::CQueue () {
    tail = 0;
    head = 0;
    realsize = 0;
    buffersize = 0;
    state = true;
    buffer = nullptr;
}

void CQueue::createBuffer() {
    if (buffersize == 0) {
        buffer = new int [1];
        buffersize = 1;
    }
    else {
        int *newBuf = new int [buffersize*2];
        for (int i = 0; i < buffersize; i++) {
            newBuf[i] = buffer[(head + i) % buffersize];
        }
        tail = buffersize - 1;
        head = 0;
        buffer = newBuf;
        buffersize *= 2;
    }
}

bool CQueue::isEmpty () {
    return realsize == 0;
}

bool CQueue::showState() {
    return state;
}

void CQueue::pushBack (int value) {
    realsize++;
    if (realsize > buffersize) {
        createBuffer();
    }
    tail = (tail + 1) % buffersize;
    buffer[tail] = value;
}

void CQueue::popFront(int value) {
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

int main()
{
    int n;
    std::cin >> n;
    CQueue queue;
    for (int i = 0; i < n; i++) {
        int number;
        int value;
        std::cin >> number >> value;
        switch (number) {
            case 2:
                queue.popFront(value);
                break;
            case 3:
                queue.pushBack(value);
                break;
            default:
                break;
        };
    }
    if (queue.showState()) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

    std::cout << std::endl;
}
