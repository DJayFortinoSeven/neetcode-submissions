class Solution {
public:
    int trap(vector<int>& height) {
        int maxl = 0, maxr = 0,n =height.size(),ans = 0;
        vector<int> mr(n),ml(n);

        for( int i=0; i<n;i++){
            ml[i]=maxl;
            if(height[i]>maxl){
                maxl = height[i];
            }

            mr[n-i-1] = maxr;
            if(height[n-i-1]>maxr){
                maxr = height[n-i-1];
            }
        }

        for( int i=0; i<n;i++){
            if(height[i]<ml[i]&&height[i]<mr[i]){
                ans+= min(ml[i],mr[i]) - height[i];
            }
        }
        return ans;
    }
};
