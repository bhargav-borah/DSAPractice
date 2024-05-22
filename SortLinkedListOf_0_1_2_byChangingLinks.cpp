class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node zeroDummy(0), oneDummy(0), twoDummy(0); 
        Node* zeroCurrent = &zeroDummy;
        Node* oneCurrent = &oneDummy;
        Node* twoCurrent = &twoDummy;
        
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == 0) {
                zeroCurrent->next = temp;
                zeroCurrent = zeroCurrent->next;
            }
            else if (temp->data == 1) { 
                oneCurrent->next = temp;
                oneCurrent = oneCurrent->next;
            }
            else if (temp->data == 2) { 
                twoCurrent->next = temp;
                twoCurrent = twoCurrent->next;
            }
            
            temp = temp->next;
        }
        
        zeroCurrent->next = (oneDummy.next != nullptr) ? oneDummy.next : twoDummy.next;
        oneCurrent->next = twoDummy.next;
        twoCurrent->next = nullptr;
        
        return zeroDummy.next;
    }
};

// class Solution
// {
//     public:
//     //Function to sort a linked list of 0s, 1s and 2s.
//     Node* segregate(Node *head) {
        
//         int count_0 = 0, count_1 = 0, count_2 = 0;
//         Node* temp = head;
//         while (temp != nullptr) {
//             if (temp->data == 0) count_0++;
//             else if (temp->data == 1) count_1++;
//             else if (temp->data == 2) count_2++;
//             temp = temp->next;
//         }
        
//         temp = head;
//         while (temp != nullptr) {
//             if (count_0 != 0) {
//                 temp->data = 0;
//                 count_0--;
//             }
//             else if (count_1 != 0) {
//                 temp->data = 1;
//                 count_1--;
//             }
//             else if (count_2 != 0) {
//                 temp->data = 2;
//                 count_2--;
//             }
//             temp = temp->next;
//         }
        
//         return head;
//     }
// };

// class Solution
// {
//     public:
//     //Function to sort a linked list of 0s, 1s and 2s.
//     Node* segregate(Node *head) {
        
//         vector<Node*> zeros, ones, twos;
//         Node* temp = head;
//         while (temp != nullptr) {
//             if (temp->data == 0) zeros.push_back(temp);
//             else if (temp->data == 1) ones.push_back(temp);
//             else if (temp->data == 2) twos.push_back(temp);
//             temp = temp->next;
//         }
        
//         Node dummy(0);
//         Node* current = &dummy;
//         bool done = false;
        
//         for (auto it: zeros) {
//             current->next = it;
//             current = current->next;
//         }
        
//         for (auto it: ones) {
//             current->next = it;
//             current = current->next;
//         }
        
//         for (auto it: twos) {
//             current->next = it;
//             current = current->next;
//         }
        
//         current->next = nullptr;
        
//         return dummy.next;
//     }
// };