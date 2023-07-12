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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL){
            return head;
        }
        // Initalise three pointers odd pointing head 
        ListNode *odd = head;
        // even pointing on head->next
        ListNode *even = head->next;
        // evenHead for joining last element of odd with even 
        ListNode *evenHead = head->next;
        // Run the loop unti; odd or even meets NULL
        while(odd->next!=NULL&&even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};