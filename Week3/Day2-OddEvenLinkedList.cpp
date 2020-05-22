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
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        ListNode* ans=head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* t1 = even;
        while(odd->next){
            odd->next = even->next;
            if(odd->next)
                even->next = odd->next->next;
            else
                even->next=NULL;
            even=even->next;
            if(odd->next!=NULL)
                odd=odd->next;
        }
        odd->next=t1;
        return ans;
    }
};
