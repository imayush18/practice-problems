class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
//         for(int i=0; i<nums.size(); i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i]==nums[j] and abs(i-j)<=k)
//                     return true;
//             }
//         }
        
//         return false;
        
        map<int, vector<int>> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i])==m.end()){
                vector<int> v;
                v.push_back(i);
                m.insert({nums[i], v});
            }
            else{
                m[nums[i]].push_back(i);
            }
        }
        
        // for(auto x: m){
        //     for(auto y: x.second)
        //         cout << y << " "; 
        //     cout << endl;
        // }
        
        for(auto x: m){
            int prev=-1;
            for(auto y: x.second){
                int cur=y;
                if(prev==-1){
                    prev=cur;
                    continue;
                }
                if(abs(prev-cur)<=k)
                    return true;
                prev=cur;
            }
        }
        
        return false;
    }
};