class Solution {
public:
    int findMax(vector<int> nums, int start, int end){
        int ind = start;
        for (int i = start+1; i <= end; i++){
            if(nums[i] > nums[ind]) ind = i;
        }
        return ind;
    }
    
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> myvec;
        if (nums.size() == 0) return myvec;
        if (k == 1) return nums;
        if (k >= nums.size()) {
            myvec.push_back(nums[findMax(nums, 0, nums.size()-1)]);
            return myvec;
        }
        int start = 0, maxptr = 0;
        maxptr = findMax(nums, 0, k-1);
        myvec.push_back(nums[maxptr]);
        while(start < nums.size() - k ){
            start ++; //increment start ptr
            if(maxptr < start){
                maxptr = findMax(nums, start, start + k - 1);
            }else{
                if(nums[maxptr] <= nums[start + k - 1]){
                    maxptr = start + k - 1;
                }
            }
            myvec.push_back(nums[maxptr]);
        }// end while
        return myvec;
    }
};
