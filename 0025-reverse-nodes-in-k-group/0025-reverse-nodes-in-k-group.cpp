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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* temp=head;
        for(int i=0;i<k;++i){
            if(temp==nullptr){
                return head;
            }
            temp=temp->next;
        }
         ListNode* prev=nullptr;
         ListNode* curr=head;
         ListNode* next=nullptr;
         int c=1;
         while(curr!=nullptr && c<=k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
         }
         if(next!=nullptr){
            head->next=reverseKGroup(curr,k);
         }
         return prev;
    }
    
};