class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int min=INT_MAX;
        for(int i=0;i<list1.size();i++)
        {
            for(int j=0;j<list2.size();j++)
            {
                if(list1[i]==list2[j])
                {
                    if(i+j==min)ans.push_back(list1[i]);
                    else if(i+j<min) 
                    {
                        ans.clear();
                        ans.push_back(list1[i]);
                        min=i+j;
                    }
                }
            }
        }
        
        return ans;
            
    }
};