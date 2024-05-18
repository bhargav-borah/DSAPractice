class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return fast;
            }
        }

        return nullptr;
    }
};

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         set<ListNode*> st;
//         ListNode* temp = head;
//         while (temp != nullptr) {
//             if (st.find(temp) != st.end()) {
//                 return temp;
//             }
//             st.insert(temp);
//             temp = temp->next;
//         }

//         return nullptr;
//     }
// };