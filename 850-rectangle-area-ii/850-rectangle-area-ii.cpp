
// class Solution {
// public:
//     static bool sortcol(vector<int>& v1,vector<int>& v2)
//     {
//         if(v1[0]==v2[0]) return v1[1]<v2[1];
//         else return v1[0]<v2[0];
//     }
//     void merge(vector<vector<int>> &v,vector<int>& pt,int idx)
//     {
//         if(idx>=v.size())
//         {
//             v.push_back(pt);
//         }
        
//         int x1=v[idx][0],y1=v[idx][1];
//         int x2=v[idx][2],y2=v[idx][3];
        
//         int px1=pt[0],py1=pt[1];
//         int px2=pt[2],py2=pt[3];
        
//         if(v[idx][2]<=pt[0])merge(v,pt,idx+1);
//         if(v[idx][3]<=pt[1])merge(v,pt,idx+1);
//         if(v[idx][1]>=pt[3])merge(v,pt,idx+1);
        
// //         if(py2>y2)
// //         {
// //             vector<int> temp(4);
// //             temp[0]=px1;
// //             temp[1]=y2;
// //             temp[2]=min(x2,px2);
// //             temp[3]=py2;
// //             merge(v,temp,idx+1);
// //         }
// //         if(py1<y1){  
// //             vector<int> temp(4,-1);  
// //             temp[0] = px1;
// //             temp[1] = py2;
// //             temp[2] = min(x2,px2);
// //             temp[3] = y1;
// //             merge(v,temp,idx+1);
// //         }
// //         if(px2>x2)
// //         {
// //             vector<int> temp=pt;
// //             temp[0]=x2;
// //             merge(v,temp,idx+1);
// //         }
//         if(pt[3]>v[idx][3]){  // case 1
//             vector<int> temp(4,-1);  //new segment
//             temp[0] = pt[0];
//             temp[1] = v[idx][3];
//             temp[2] = min(pt[2],v[idx][2]);
//             temp[3] = pt[3];
//             merge(v,temp,idx+1);
//         }
//         if(pt[1]<v[idx][1]){  // case 2
//             vector<int> temp(4,-1);  //new segment
//             temp[0] = pt[0];
//             temp[1] = pt[1];
//             temp[2] = min(pt[2],v[idx][2]);
//             temp[3] = v[idx][1];
//             merge(v,temp,idx+1);
//         }
//         if(pt[2]>v[idx][2]){  // case 3
//             vector<int> temp = pt;  //new segment
//             temp[0] = v[idx][2];
//             merge(v,temp,idx+1);
//         }
//         return;
//     }
//     int rectangleArea(vector<vector<int>>& rectangles) {
//         sort(rectangles.begin(),rectangles.end(),sortcol);
//         vector<vector<int>> v;
//         v.push_back(rectangles[0]);
        
//         for(int i=1;i<rectangles.size();++i)
//         {
//             merge(v,rectangles[i],0);
//         }
//         long long ans=0,mod=1e9+7;
//         for(auto rec:v)
//         {
//             long long x=rec[2]-rec[0],y=rec[3]-rec[1];
//             ans+=(x*y)%mod;
//             ans%=mod;
//         }
//         return ans;
//     }
// };
int sortcol(vector<int>& v1,vector<int>& v2){
    if(v1[0]==v2[0]) return v1[1]<v2[1];
    else return v1[0]<v2[0];
}
class Solution {
public:
    void merge(vector<vector<int>> &re,vector<int>& pt,int in){
        if(in>=re.size()){
            re.push_back(pt);
        }
        if(re[in][2]<=pt[0]) return merge(re,pt,in+1);
        if(re[in][3]<=pt[1]) return merge(re,pt,in+1);
        if(re[in][1]>=pt[3]) return merge(re,pt,in+1);
        if(pt[3]>re[in][3]){  // case 1
            vector<int> temp(4,-1);  //new segment
            temp[0] = pt[0];
            temp[1] = re[in][3];
            temp[2] = min(pt[2],re[in][2]);
            temp[3] = pt[3];
            merge(re,temp,in+1);
        }
        if(pt[1]<re[in][1]){  // case 2
            vector<int> temp(4,-1);  //new segment
            temp[0] = pt[0];
            temp[1] = pt[1];
            temp[2] = min(pt[2],re[in][2]);
            temp[3] = re[in][1];
            merge(re,temp,in+1);
        }
        if(pt[2]>re[in][2]){  // case 3
            vector<int> temp = pt;  //new segment
            temp[0] = re[in][2];
            merge(re,temp,in+1);
        }
    }
    
    int rectangleArea(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),sortcol);
        vector<vector<int>> re;  // list of non-overlapping intervals
        re.push_back(nums[0]);
        for(int i = 1; i<nums.size();++i){
            merge(re,nums[i],0);  // merge each interval
        }
        long long ans = 0,mod=1e9+7;
        for(int i = 0; i<re.size();++i){  // find the area of each interval
            long long x = re[i][2]-re[i][0],y=re[i][3]-re[i][1];
            ans= (ans + (x*y)%mod)%mod;
        }
        return ans;
    }
};