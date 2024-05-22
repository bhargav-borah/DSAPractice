class Solution
{
    public:
    Node* reverseLinkedList(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        Node* newHead = reverseLinkedList(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    
    Node* addOne(Node *head) 
    {
        Node* newHead = reverseLinkedList(head);
        int carry = 1;
        Node* temp = newHead;
        while (temp != nullptr) {
            int data = temp->data;
            temp->data = (data + carry) % 10;
            carry = (data + carry) / 10;
            
            if (temp->next == nullptr && carry != 0) {
                temp->next = new Node(carry);
                carry = 0;
            }
            
            temp = temp->next;
        }
        
        newHead = reverseLinkedList(newHead);
        
        return newHead;
    }
};