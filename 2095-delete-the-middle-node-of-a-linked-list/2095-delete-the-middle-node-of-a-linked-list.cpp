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
    
    int length(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        int len=length(head);
        if(len==1)
            return NULL;
//         if(len%2==0){
//             mid=len/2;
            
//         }
        // else{
            int mid=len/2;
        cout << mid << endl;
        // }
        
        ListNode* temp=head;
        mid--;
        while(mid--){
            temp=temp->next;
        }
        
        ListNode* x=temp->next;
        temp->next=x->next;
        return head;
    }
};