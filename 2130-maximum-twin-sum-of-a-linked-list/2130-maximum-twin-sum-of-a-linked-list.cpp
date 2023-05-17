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
   ListNode* ReverseList(ListNode *head){
       ListNode *first=NULL;
       ListNode *r=NULL;
       ListNode *q=NULL;
       while(head!=NULL){
           r=q;
           q=head;
           head=head->next;
           q->next=r;
       }
       first=q;
       return q;
    }
    int pairSum(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=slow->next;
       slow= ReverseList(slow);
        int max_value=0;
        while(slow!=NULL){
            max_value = max(max_value, head->val+slow->val);
            slow=slow->next;
            head=head->next;
        }
        return max_value;
        
        
    }
};