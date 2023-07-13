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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int size = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    int parts = size / k;
    int remainder = size % k;

    vector<ListNode*> result;
    temp = head;
    while (temp != NULL) {
        result.push_back(temp);
        int currLen = 1;
        while (currLen < parts) {
            if (temp != NULL) {
                temp = temp->next;
            }
            currLen++;
        }
        if (remainder > 0 && size>k) {
            if (temp != NULL) {
                temp = temp->next;
                remainder--;
            }
        }
        if (temp != NULL) {
            ListNode* x = temp->next;
            temp->next = NULL;
            temp = x;
        }
    }
    while (size < k) {
        result.push_back(NULL);
        size++;
    }
    return result;
}

};