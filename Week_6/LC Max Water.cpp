class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0,j = nums.size() - 1, mx = INT_MIN;
	    while(i < j)
	    {
		    int water = (j-i)*min(nums[i],nums[j]);
		    mx = max(mx,water);
		    if(nums[i] < nums[j])
		        i++;
		    else
		        j--;
	    }
	
	    return mx;
    }
};