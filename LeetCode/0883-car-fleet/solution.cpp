class Solution{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){   // monotonic stack
        
        int n=position.size();
        vector<pair<int,int>> cars;

        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());

        vector<double> stack;
        for(auto car:cars){
            double time=(double)(target-car.first)/car.second;

            if(stack.empty() || time>stack.back()){
                stack.push_back(time);
            }
        }

        return stack.size();

    }
};
