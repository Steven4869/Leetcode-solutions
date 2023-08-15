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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        
        ListNode *leftPoint = left;
        ListNode *rightPoint = right;
        
        while(head!=NULL){
            if(head->val < x){
                leftPoint->next = head;
                leftPoint = leftPoint->next;
            }
            else{
                rightPoint->next = head;
                rightPoint = rightPoint->next;
            }
            head = head->next;
        }
        
        leftPoint->next = right->next;
        rightPoint->next = NULL;
        
        return left->next;
    }
};