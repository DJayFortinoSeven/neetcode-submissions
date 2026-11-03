class Solution {
public:
    int findMin(vector<int> &nums) {
        int m = 0, n = nums.size()-1,mid;
        
        
        while (m<n){
            if(m +1==n){
                return min(nums[m],nums[n]);
            }
            mid = (m+n)/2;
            if (nums[m]<nums[mid]&&nums[mid]<nums[n]){
            return nums[m];
            }
            if(nums[m]<nums[mid]){
                m = mid +1;
            }
            else{
                n=mid;
            }
        }
        return min(nums[m],nums[n]);
    }
};
