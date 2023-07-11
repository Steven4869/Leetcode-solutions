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
    ListNode *solveIterative(ListNode *head){
        //Using iteration 
        //Make three pointers 
        ListNode *curr = head;
        ListNode *nxt = NULL;
        ListNode *prev = NULL;
        
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode *solveRecursion(ListNode* head){
        //base Case 
        if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* newHead = solveRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        // return solveIterative(head);
        return solveRecursion(head);
        
    }
};