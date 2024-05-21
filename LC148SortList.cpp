class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Divide the list into two parts
        fast = slow->next;
        slow->next = nullptr;

        return merge(sortList(head), sortList(fast));
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1 != nullptr) {
            current->next = l1;
        }
        
        current->next = (l1 != nullptr) ? l1 : l2;

        return dummy.next;
    }
};

// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp = head;
//         while (temp != nullptr) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         sort(arr.begin(), arr.end());
        
//         temp = head;
//         int idx = 0;
//         while (temp != nullptr) {
//             temp->val = arr[idx++];
//             temp = temp->next;
//         }

//         return head;
//     }
// };