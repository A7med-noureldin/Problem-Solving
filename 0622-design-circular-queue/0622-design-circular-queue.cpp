class MyCircularQueue {
    int front, rear, size; 
    vector<int> q;
public:
    MyCircularQueue(int k) {
        q.assign(k, -1);
        front = 0, rear = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear+1)%size;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        q[front] = -1;
        front = (front+1)%size;
        return true;
    }
    
    int Front() {
        return q[front];
    }
    
    int Rear() {
        if(rear == -1) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return q[front] == -1;
    }
    
    bool isFull() {
        return front == (rear+1)%size && q[(front+1)%size] != -1;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */