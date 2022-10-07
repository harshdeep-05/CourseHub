class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& in) {
        if(intervals.empty())
        {
            return {in};
        }
        vector<vector<int>> ans;
        int flag=0;
        for(auto &v:intervals)
        {
            if(v[0]>in[1] || v[1]<in[0])continue;
            in[0]=min(in[0],v[0]);
            in[1]=max(in[1],v[1]);
            flag=1;
        }
        if(flag==0){
            if(in[1]<intervals[0][0])
            {
                intervals.insert(intervals.begin(),in);
            return intervals;
            }
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i][1]<in[0] && intervals[i+1][0]>in[1])
                {
                    intervals.insert(intervals.begin()+i+1,in);
                    return intervals;
                }
            
        }
            intervals.push_back(in);
            return intervals;
        }
        flag=1;
        for(auto &v:intervals)
        {
            if(v[0]>in[1] || v[1]<in[0])
            {
                ans.push_back(v);
            }
            else if(flag)
            {
                ans.push_back(in);
                flag=0;
            }
        }
        return ans;
    }
};