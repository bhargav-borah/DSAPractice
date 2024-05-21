class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // When the head is the node to be deleted
        if (fast == nullptr) {  
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* targetNode = slow->next;
        slow->next = targetNode->next;
        delete targetNode;

        return head;
    }
};

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* temp = head;
//         int count = 0;
//         while (temp != nullptr) {
//             count++;
//             temp = temp->next;
//         }

//         // Edge case when head is to be deleted
//         if (count == n) {
//             ListNode* newHead = head->next;
//             delete head;
//             return newHead;
//         }

//         int steps = count - n - 1;
//         temp = head;
//         while (steps--) {
//             temp = temp->next;
//         }

//         ListNode* targetNode = temp->next;
//         temp->next = temp->next->next;
//         delete targetNode;

//         return head;
//     }
// };
