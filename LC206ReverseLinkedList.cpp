class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp = head;
//         ListNode* prev = nullptr;
//         while (temp != nullptr) {
//             ListNode* front = temp->next;
//             temp->next = prev;
//             prev = temp;
//             temp = front;
//         }

//         return prev;
//     }
// };