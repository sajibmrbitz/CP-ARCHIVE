class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int map[10001]; 
        for(int i=0;i<10001;i++){
            map[i]=-1;
        }

        stack<int> s;

        for(int num:nums2){
            while(!s.empty() && num>s.top()){
                map[s.top()]=num; 
                s.pop();
            }
            s.push(num);
        }
        vector<int> result;
        for(int num:nums1){
            result.push_back(map[num]);
        }

        return result;
    }
};
