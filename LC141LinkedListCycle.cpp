class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        } 

        return false;
    }
};
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         set<ListNode*> st;
//         ListNode* temp = head;
//         while (temp != nullptr) {
//             if (st.find(temp) != st.end()) return true;
//             st.insert(temp);
//             temp = temp->next;
//         }

//         return false;
//     }
// };