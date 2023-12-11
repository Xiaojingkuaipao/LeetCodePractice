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
    ListNode* swapPairs(ListNode* head) {
        //对于处理链表头节点的操作可以采用虚拟头节点的方式
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        while (cur ->next != NULL && cur->next->next != NULL) {
            ListNode* tmp1 = cur->next->next->next;//第二个节点的后继节点地址
            ListNode* tmp2 = cur->next;//第一个节点
            //dummyhead -> 1 -> 2 -> 3
            // cur        c.n c.n.n  c.n.n.n
            //自己画个图就明白了
            cur->next = cur->next->next;
            cur->next->next = tmp2;
            cur->next->next->next = tmp1;
            cur = cur->next->next;//完成反转之后cur节点往后走两步
        }
        return dummyhead->next;
    }
};
