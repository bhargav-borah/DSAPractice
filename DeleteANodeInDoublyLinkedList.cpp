class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      Node* temp = head_ref;
      x--; // zero-indexing
      
      if (x == 0) {
        Node* head = head_ref;
        Node* newHead = head->next;
        newHead->prev = nullptr;
        newHead->next = head->next->next;
        return newHead;
      }
      
      while (x--) {
          temp = temp->next;
      }
      
      if (temp->next == nullptr) {
          Node* prevNode = temp->prev;
          prevNode->next = nullptr;
          return head_ref;
      }
      
      Node* prevNode = temp->prev;
      Node* nextNode = temp->next;
      prevNode->next = nextNode;
      nextNode->prev = prevNode;
      return head_ref;
    }
};