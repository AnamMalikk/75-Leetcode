class Solution {
public:
// TC=O(N log N)
// SC=O(1)

// RULE: always choose the interval that ends first.
// Reason:
/* 
We want to remove the minimum number of intervals so that the remaining intervals are non-overlapping.

Equivalently, we can think:

Maximize the number of non-overlapping intervals.

The minimum number to remove = total intervals - maximum number of non-overlapping intervals.


// So basically we need to maximize the no. of non overlapping intervals. That's why greedy works.
// If we sort by start time, we might pick a long interval early, which blocks shorter intervals later.


[1, 10], [2, 3], [3, 4]

If you pick [1,10] first, you can't take any others because they will overlap with [1,10]
If you pick [2,3] first (ends earlier), you can also take [3,4] because they don't overlap.

*/

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