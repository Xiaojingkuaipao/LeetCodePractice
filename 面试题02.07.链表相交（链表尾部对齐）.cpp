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
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 1, lenB = 1;
        while (curA != NULL) {
            curA = curA -> next;
            lenA++;
        }
        while (curB != NULL) {
            curB = curB -> next;
            lenB++;
        }
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(headA, headB);
        }
        curA = headA;
        curB = headB;
        int gap = lenA - lenB;
        while (gap != 0) {
            curA = curA->next;
            gap--;
        }
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            else {
                curA = curA -> next;
                curB = curB -> next;
            }
        }
        return NULL;
    }
};
