/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode*curr=head;

       
        double dn=0;
        int x=0;
        vector<int>arr;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        for(int i=arr.size()-1;i>=0;i--){
            dn=arr[i]*pow(2,x)+dn;
            x=x+1;
        }
        return dn;

       

    }
};