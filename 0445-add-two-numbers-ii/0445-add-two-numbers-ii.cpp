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
    
    ListNode *reverseList(ListNode *head){
        ListNode *nxt = NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Base Cases 
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        
        //Reversing both the lists 
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        int carry = 0;
        
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum = 0;
            if(l1!=NULL){
                sum = sum + l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum = sum + l2->val;
                l2=l2->next;
            }
            
            sum = sum + carry;
            carry = sum/10;
            
            ListNode *node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        dummy = reverseList(dummy->next);
        return dummy;
        
    }
};