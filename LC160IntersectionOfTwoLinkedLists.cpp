class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != tempB) {
            tempA = (tempA != nullptr) ? tempA->next : headB;
            tempB = (tempB != nullptr) ? tempB->next : headA;
        }

        return tempA;
    }
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         int lenA = 0, lenB = 0;
//         ListNode* tempA = headA;
//         ListNode* tempB = headB;

//         while (tempA != nullptr) {
//             lenA++;
//             tempA = tempA->next;
//         }

//         while (tempB != nullptr) {
//             lenB++;
//             tempB = tempB->next;
//         }

//         int diff = 0;
//         tempA = headA;
//         tempB = headB;
//         if (lenA > lenB) {
//             diff = lenA - lenB;
//             for (int i = 0; i < diff; i++) {
//                 tempA = tempA->next;
//             }
//         }
//         else {
//             diff = lenB - lenA;
//             for (int i = 0; i < diff; i++) {
//                 tempB = tempB->next;
//             }
//         }

//         while (tempA != nullptr) {
//             if (tempA == tempB) return tempA;
//             tempA = tempA->next;
//             tempB = tempB->next;
//         }

//         return nullptr;
//     }
// };

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//         set<ListNode*> st;

//         ListNode* temp = headA;
//         while (temp != nullptr) {
//             st.insert(temp);
//             temp = temp->next;
//         }

//         temp = headB;
//         while (temp != nullptr) {
//             if (st.find(temp) != st.end()) {
//                 return temp;
//             }
//             temp = temp->next;
//         }

//         return nullptr;
//     }
// };