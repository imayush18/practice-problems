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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
    
        temp=head;
        
        if(n==len){
            if(!head){
                return NULL;
            }
            
            else if(head->next==NULL){
                return NULL;
            }
            
            else{
                ListNode*k=head;
                head=head->next;
                delete k;
            }
        }
        
        else{
            int x=len-n-1;
            while(x){
                x--;
                temp=temp->next;
            }
            // delete temp;
            temp->next=temp->next->next;   
        }
        
        return head;   
    }
};