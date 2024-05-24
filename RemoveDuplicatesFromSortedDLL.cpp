class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* duplicate = current->next;
                current->next = duplicate->next;
                if (duplicate->next != nullptr) {
                    duplicate->next->prev = current;
                }
                
                delete duplicate;
            }
            else {
                current = current->next;
            }
        }
        
        return head;
    }
};