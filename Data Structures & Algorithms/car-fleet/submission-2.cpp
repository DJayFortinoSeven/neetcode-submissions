class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        double min = 0;
        int cnt =0;
        sort(pair.rbegin(), pair.rend());
        for (auto& p : pair) {
            double time = (double)(target - p.first)/p.second;
            if(time> min){
                min = time;
                cnt++;
            }
        }       
        return cnt;
    }
};
