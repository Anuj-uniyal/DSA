class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        int n=nums.size();
        for(int i=0;i<n;++i){
            um[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(pair<int,int>p:um){
            pq.push({p.second,p.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};