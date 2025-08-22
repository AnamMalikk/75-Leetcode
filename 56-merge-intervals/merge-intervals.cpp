class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //optimal approach
        //tc = O(nlogn) + O(n)
        //sc = O(n)

        int n = intervals.size();
        vector<vector<int>> ans;

        if(n == 0){
            return ans;
        }

        sort(intervals.begin(), intervals.end());

        vector<int> pp = intervals[0]; //taking 1st ele in the temp
        int i = 0;

        while(i < n){
            if( pp[1] >= intervals[i][0] ){ //overlap
                pp[1] = max(pp[1], intervals[i][1]);
            }
            else{ //no overlap
                ans.emplace_back(pp);
                pp[0] = intervals[i][0];
                pp[1] = intervals[i][1];
            }
            i++;
        }

        ans.emplace_back(pp); //pushing whatever's remaining in the temp
        return ans;
    }
};