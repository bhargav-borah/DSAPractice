class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        Node* head = *head_ref;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x) {
                if (temp == head) {
                    head = head->next;
                    *head_ref = head;
                }
                
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                
                if (nextNode != nullptr) nextNode->prev = prevNode;
                if (prevNode != nullptr) prevNode->next = nextNode;
                
                delete temp;
                temp = nextNode;
            }
            else {
                temp = temp->next;
            }
        }
    }
};