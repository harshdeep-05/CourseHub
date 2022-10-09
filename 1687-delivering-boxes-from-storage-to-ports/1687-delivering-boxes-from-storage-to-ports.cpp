// class Solution {
// public:
//     vector<int> dp;
//     int solve(vector<vector<int>>& boxes,int &mxb,int &mxw,int i)
//     {
//         if(i==boxes.size())
//             return 0;
//         if(dp[i]!=0)return dp[i];
//         int j=i,weight=boxes[i][1],cnt=1;
//         int prev_port=boxes[i][0],port_cnt=0;
//         while(j+1<boxes.size() && weight+boxes[j+1][1]<=mxw && j+1<=mxb)
//         {
//             j++;
//             weight+=boxes[j][1];
//             cnt++;
//             if(prev_port!=boxes[j][0])
//             {
//                 prev_port=boxes[j][0];
//                 port_cnt++;
//             }
//         }
//         int trips=2+port_cnt+solve(boxes,mxb,mxw,j+1);
//         j--;
//         while(j>=i && boxes[j][0]==prev_port){
//             j--;
//         }
        
// //         int x=-1;
// //         for(x=j-1;x>=i;x--)
// //         {
// //             if(boxes[x][0]!=prev_port)
// //             {
// //                 break;
// //             }
// //         }
        
//         if(j>=i)
//             trips=min(trips,1+port_cnt+solve(boxes,mxb,mxw,j+1));
                                         
//         return dp[i]=trips;
//     }
//     int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
//         int n=boxes.size();
//         dp=vector<int> (n+1,0);
//         return solve(boxes,maxBoxes,maxWeight,0);
//     }
// };

class Solution {
public:

    vector<vector<int>> boxes;
    int ports , max_box , max_wt , n;
    vector<int> dp;
    
    int backtrack(int index) {
        if(index == n)
            return 0;
        if(dp[index] != 0)
            return dp[index];
        
        int start = index, end = index, currWt = boxes[index][1] , boxCount = 1 , lastPort = boxes[index][0] , ports_visited = 0;
        //as long as it's possible to load the boxes load them into the ship so that the visit to the storage unit is minimised.
        while(end+1<n && currWt + boxes[end+1][1] <= max_wt && boxCount + 1 <=max_box) 
        {
            end++;
            currWt += boxes[end][1];
            boxCount++;
            if(lastPort != boxes[end][0]){
                ports_visited++;
                lastPort = boxes[end][0];
            }
        }
        //2 - from the storage to the 1st port and then back to the storage from the last port either for loading the next set of boxes or returning after delivering all the boxes.         
        int trips = 2 + ports_visited + backtrack(end+1);
        
        //number of trips can still be minimised when a box going to port 'j' can be included in the next trip if there are other boxes going to port 'j'
        
        int x = -1;
        for(int i = end-1;i>=index;i--){
            if(boxes[i][0]!=lastPort) {
            // cout<<end<<"    end\n";                
                x = i;
                break;
            }
        }
        if(x!=-1){
            trips = min(trips , 2+ports_visited-1+backtrack(x+1));
        }

        dp[index] = trips;        
        // cout<<trips<<" "<<index<<"\n";
        return trips;        
    }
    
    
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        this->boxes = boxes;
        //ports,boxes
        n = boxes.size();
        dp.assign(n,0);
        ports = portsCount; 
        max_box = maxBoxes;
        max_wt = maxWeight;
        return backtrack(0);
    }
};