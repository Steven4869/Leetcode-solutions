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
    ListNode *reverseLL(ListNode *head){
        //Make three pointers 
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode *middleLL(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *middle = middleLL(head);
        ListNode *reverse = reverseLL(middle);
        ListNode *temp = head;
        while(temp!=NULL && reverse!=NULL){
            if(temp->val != reverse->val)
                return false;
            temp=temp->next;
            reverse=reverse->next;
        }
        return true;
        
    }
};