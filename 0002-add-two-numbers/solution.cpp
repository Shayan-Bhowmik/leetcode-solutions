class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); 
        ListNode* curr = dummyHead; 
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int total = carry;

            if (l1 != nullptr) {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                total += l2->val;
                l2 = l2->next;
            }

            carry = total / 10;
            curr->next = new ListNode(total % 10);
            curr = curr->next; 
        }

        ListNode* result = dummyHead->next; 
        delete dummyHead;
        return result;
    }
};