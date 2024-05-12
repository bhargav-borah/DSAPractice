class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if ((head == nullptr) || (head->next == nullptr)) return head;
        
        Node* current = head;
        Node* temp = nullptr;
        
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        
        if (temp != nullptr) head = temp->prev;
    }
};