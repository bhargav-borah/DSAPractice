class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        ListNode* current = head;
        int length = 1;

        while (current->next != nullptr) {
            current = current->next;
            length++;
        }

        current->next = head;

        k = k % length;
        int stepsToNewHead = length - k;
        int stepsToNewTail = stepsToNewHead - 1;

        ListNode* newTail = head;
        while (stepsToNewTail != 0) {
            newTail = newTail->next;
            stepsToNewTail--;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};