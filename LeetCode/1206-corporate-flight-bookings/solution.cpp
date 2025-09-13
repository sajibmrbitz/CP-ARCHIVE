class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings,int n){
        vector<int> diff(n, 0);

        for (const auto& op:bookings){
            int l=op[0]-1; 
            int r=op[1]-1;
            int seats=op[2];
            diff[l]+=seats;
            if(r+1<n)   
                diff[r+1]-=seats;
        }

        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }

        return diff;
    }
};
