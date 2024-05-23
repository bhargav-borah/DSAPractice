class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* current = &dummy;

        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while (temp1 != nullptr || temp2 != nullptr || carry != 0) {
            int val1 = (temp1 != nullptr) ? temp1->val : 0;
            int val2 = (temp2 != nullptr) ? temp2->val : 0;
            int sum = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;

            current->next = new ListNode(sum);
            current = current->next;

            
            temp1 = (temp1 == nullptr) ? nullptr : temp1->next;
            temp2 = (temp2 == nullptr) ? nullptr : temp2->next;
        }
        current->next = nullptr;

        return dummy.next;
    }
};