class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: Find middle of list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compute max twin sum
        int maxi = INT_MIN;
        ListNode* p1 = head;
        ListNode* p2 = prev; // head of reversed half
        while (p2) {
            maxi = max(maxi, p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        return maxi;
    }
};
