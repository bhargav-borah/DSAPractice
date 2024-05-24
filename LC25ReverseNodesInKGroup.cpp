class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseLinkedList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    ListNode* getKthNode(ListNode* current, int k) {
        k--;
        while (current != nullptr && k != 0) {
            current = current->next;
            k--;
        }

        return current;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevGroupLast = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = getKthNode(temp, k);
            if (kthNode == nullptr) {
                if (prevGroupLast != nullptr) prevGroupLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            ListNode* reversedGroupHead = reverseLinkedList(temp);

            if (temp == head) {
                head = reversedGroupHead;
            }
            else {
                prevGroupLast->next = reversedGroupHead;
            }

            prevGroupLast = temp;
            temp = nextNode;
        }

        return head;
    }
};