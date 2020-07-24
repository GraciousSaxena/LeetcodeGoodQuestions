/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public :
    ListNode* newSum(ListNode* h, int sum){
        ListNode* last = h;
        ListNode* node = new ListNode();
        node->val = sum;
        node->next = NULL;
        if(h == NULL)   return node;
        while(last->next != NULL)
            last = last->next;
        last->next = node;
        return h;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h = NULL;
        int sum=0, carry=0;
        while(l1 != NULL && l2 != NULL){
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            h = newSum(h, sum%10);
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            sum = l1->val + carry;
            carry = sum/10;
            h = newSum(h, sum%10);
            l1 = l1->next;
        }
        while(l2 != NULL){
            sum = l2->val + carry;
            carry = sum/10;
            h = newSum(h, sum%10);
            l2 = l2->next;
        }
        while(carry != 0){
            h = newSum(h, carry%10);
            carry /= 10;
        }
        return h;
    }
};
