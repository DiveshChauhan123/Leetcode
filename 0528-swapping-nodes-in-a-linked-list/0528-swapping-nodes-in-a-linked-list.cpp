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
int findlen(ListNode*head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}
    ListNode* swapNodes(ListNode* head, int k) {
        int n=findlen(head);
        ListNode*node=head;
        ListNode*node1=NULL;
        ListNode*node2=NULL;
        for(int i=1;i<=n;i++){
            if(i==k){
                node1=node;
            }
            if(n-k+1==i){
                node2=node;
            }
            node=node->next;
        }
        swap(node1->val,node2->val);
        return head;
    }
};