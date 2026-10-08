class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n=p.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;++i){
            pq.push({g[i],p[i]});
        }
        int start=0;
        int ans=0;
        while(pq.size()>0){
            pair<int,int>s=pq.top();
            pq.pop();
            ans=max(ans,start+s.first+s.second);
            start+=s.second;
        }
        return ans;
    }
};