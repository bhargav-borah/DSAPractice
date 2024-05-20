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

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = reverseLinkedList(slow->next);

        while (temp2 != nullptr) {
            if (temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp = head;
//         while (temp != nullptr) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }

//         int i = 0, j = arr.size() - 1;
//         while (i < j) {
//             if (arr[i] != arr[j]) return false;
//             i++;
//             j--;
//         }

//         return true;
//     }
// };