class Solution {
public:
// TC=O(N log N)
// SC=O(1)


    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1])
        return a[0]<b[0];
        else
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int cnt=0;
    
        sort(intervals.begin(),intervals.end(),cmp);


       int first=intervals[0][0];
       int second=intervals[0][1];

       for(int i=0;i<intervals.size()-1;i++){
          if(second>intervals[i+1][0]){
          cnt++;
          }

          else{
            first=intervals[i+1][0];
            second=intervals[i+1][1];
          }
       }

       return cnt;
    }
};