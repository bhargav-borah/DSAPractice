//Function to push an integer into the stack.
void MyStack ::push(int x) 
{   
    StackNode* newNode = new StackNode(x);
    newNode->next = top;
    top = newNode;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if (top == nullptr) {
        return -1;
    }
    
    int popVal = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    
    return popVal;
}