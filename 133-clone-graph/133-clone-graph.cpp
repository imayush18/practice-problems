/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* bfs(Node* node, unordered_map<Node*, Node*> &mp){
        
        Node* clone=new Node(node->val);
        mp[node]=clone;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* cur=q.front();
            q.pop();
            for(auto it: cur->neighbors){
                if(mp.find(it)==mp.end()){
                    mp[it]=new Node(it->val);
                    q.push(it);
                }
                
                mp[cur]->neighbors.push_back(mp[it]);
            }   
        }

        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
            return NULL;
        
        unordered_map<Node*, Node*> mp;
        
        return bfs(node, mp);
    }
};