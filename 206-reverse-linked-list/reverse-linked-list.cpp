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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        vector<int>temp;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        reverse(temp.begin(),temp.end());
        ListNode* t=new ListNode(temp[0]);
        ListNode* p=t;
        for(int i=1;i<temp.size();i++){
          ListNode*q=new ListNode(temp[i]);
          p->next=q;
          p=p->next;
        }
        return t;
    }
};