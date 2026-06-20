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
 //T.C-O(N)
 //S.C-O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode*temp=head;
       int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==1){
            return head;
        }
        count=count/2;
        temp=head;
        ListNode* result=NULL;
        while(count>1){
            count--;
            temp=temp->next;
        }
         result=temp->next;
         temp->next=NULL;
        return result;
    }
};