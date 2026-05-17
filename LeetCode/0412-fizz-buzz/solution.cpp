class Solution {
public:
    vector<string> fizzBuzz(int n){
        vector<string> FB(n);

        for(int i=1;i<=n;i++){
            int five=i%5;
            int three=i%3;
            if(!five && !three){
                FB[i-1]="FizzBuzz";
            }
            else if(!three){
                FB[i-1]="Fizz";
            }
            else if(!five){
                FB[i-1]="Buzz";
            }
            else{
                FB[i-1]=to_string(i);
            }
        }

        return FB;
    }
};
