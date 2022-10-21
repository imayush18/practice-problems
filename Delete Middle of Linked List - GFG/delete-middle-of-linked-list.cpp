//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		head = deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends


/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

int length(Node* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    int len=length(head);
        if(len==1)
            return NULL;
//         if(len%2==0){
//             mid=len/2;
            
//         }
        // else{
            int mid=len/2;
        // cout << mid << endl;
        // }
        
        Node* temp=head;
        mid--;
        while(mid--){
            temp=temp->next;
        }
        
        
        
        Node* x=temp->next;
        temp->next=x->next;
        return head;
}