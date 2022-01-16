class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),i=0,j=n-1,cnt=0;
        //if(n==1 && nums[0]==val)return 0;
        while(i<=j)
        {
            if(nums[j]==val){
                j--;
                cnt++;
                //continue;
            }
            else if(nums[i]==val){
                cnt++;
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else i++;
        }
        //cout<<n-cnt<<endl;
        return n-cnt;
    }
};