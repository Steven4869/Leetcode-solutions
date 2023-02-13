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
    ListNode *recur(ListNode *prev, ListNode *head){
        if(head==NULL)
            return prev;
        
        ListNode *temp = head->next;
        head->next = prev;
        return recur(head, temp);
    }
    ListNode* reverseList(ListNode* head) {
        
        //Using Recursion 
        return recur(NULL, head);
    }
};