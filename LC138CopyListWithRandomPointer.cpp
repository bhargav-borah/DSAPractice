class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* current = head;
        while (current != nullptr) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        current = head;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        current = head;
        Node* copiedHead = head->next;
        Node* copyCurrent = copiedHead;
        while (current) {
            current->next = current->next->next;
            if (copyCurrent->next != nullptr) {   
                copyCurrent->next = copyCurrent->next->next;
            }
            current = current->next;
            copyCurrent = copyCurrent->next;
        }

        return copiedHead;
    }
};