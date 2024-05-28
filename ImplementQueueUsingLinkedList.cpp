//Function to push an element into the queue.
void MyQueue:: push(int x)
{
    QueueNode* newNode = new QueueNode(x);
    
    if (front == nullptr && rear == nullptr) {
        rear = front = newNode;
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if (front == nullptr) {
        return -1;
    }      
    
    int popData = front->data;
    QueueNode* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    
    return popData;
}