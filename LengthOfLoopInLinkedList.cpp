int countNodesinLoop(struct Node *head)
{
    map<Node*, int> mpp;
    Node* temp = head;
    int count = 0;
    
    while (temp != nullptr) {
        if (mpp.find(temp) == mpp.end()) {
            mpp[temp] = ++count;
            temp = temp->next;
        }
        else {
            return count + 1 - mpp[temp];
        }
    }
    
    return 0;
}