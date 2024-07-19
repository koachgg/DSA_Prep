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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brute Force
        // while(headB!=NULL){
        // ListNode* temp = headA;
        // while(temp!=NULL){
        //     if(temp==headB) return headB;

        //     temp=temp->next;
        // }
        // headB=headB->next;
        // }
        // return NULL;
        // Better Approach : hashing use a set/unordered_set
        // Optimal : Difference in Length
    if(headA==NULL || headB==NULL) return NULL;
        ListNode* d1 = headA;
        ListNode* d2 = headB;

        while(d1!=d2){
            if(d1==NULL) d1=headB;
            else d1=d1->next;

            if(d2==NULL) d2=headA;
            else d2=d2->next;
        }
        return d1;
    }
};

