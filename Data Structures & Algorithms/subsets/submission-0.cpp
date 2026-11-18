class Solution {
public:
    vector<vector<int>> ans;
    vector<int> input;
    int i;

    void recurr(vector<int> res,int i){
        if(i>=input.size()){
            ans.push_back(res);
            return;
        }

        recurr(res,i+1);
        res.push_back(input[i]);
        recurr(res,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        input = nums;
        i=0;
        vector<int> res;
        recurr(res,i);
        return ans;
    }
};
