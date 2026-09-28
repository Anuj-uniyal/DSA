class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<
    pair<long long, pair<int,int>>,
    vector<pair<long long, pair<int,int>>>,
    greater<pair<long long, pair<int,int>>>
> pq;

for(auto point : points) {
    long long dist = point[0] * point[0]
                   +  point[1] * point[1];

    pq.push({dist, {point[0], point[1]}});
}
        while(k--) {
    ans.push_back({pq.top().second.first,pq.top().second.second});
    pq.pop();
}
        return ans;
    }
};