/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(INT_MIN);
        ListNode* aux = head;
        
        int sum = 0;
        while (l1 || l2) {
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            aux->next = new ListNode(sum % 10);
            sum /= 10;
            aux = aux->next;
            
            l1 = (l1 ? l1->next : l1);
            l2 = (l2 ? l2->next : l2);
        }
        
        if(sum) aux->next = new ListNode(sum);
        aux = head->next;
        delete head;
        return aux;
    }
};