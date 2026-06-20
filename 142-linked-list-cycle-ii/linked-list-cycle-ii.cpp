/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //T.C-O(N)
 //S.C-O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>m;
        ListNode*temp=head;
        int i=0;
        if(head==NULL){
            return head;
        }
        while(temp!=NULL){
            if(m.find(temp)!=m.end()){
                return temp;
            }
            m[temp]=i;
            i++;
            temp=temp->next;
        }
      return NULL;
    }
};