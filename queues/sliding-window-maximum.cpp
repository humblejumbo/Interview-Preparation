// https://leetcode.com/problems/sliding-window-maximum/

// https://leetcode.com/problems/sliding-window-maximum/discuss/65884/Java-O(n)-solution-using-deque-with-explanation
//only explanaton

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        vector<int> res;
        deque<int> dq;
        
        for(int i=0;i<arr.size();i++)
        {
            if(!dq.empty() && dq.front()==i-k)
                dq.pop_front();
            
            while(!dq.empty() && arr[dq.back()]<arr[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i>=k-1)
                res.push_back(arr[dq.front()]);
        }
        
        return res;
        
    }
};
