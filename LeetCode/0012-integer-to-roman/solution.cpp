class Solution {
public:
    string intToRoman(int num) {

        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbols[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string roman="";
        int n=sizeof(values)/sizeof(values[0]);

        for(int i=0;i<n;i++){
            while(num>=values[i]){
                roman+=symbols[i];
                num-=values[i];
            }
        }

        return roman;
    }
};
