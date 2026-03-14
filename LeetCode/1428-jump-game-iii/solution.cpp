class Solution {
    bool khuj(vector<int>& laaf,int ekhonAchi, vector<bool>& ageAschiKina){
        
        if(ekhonAchi<0 || ekhonAchi>=laaf.size() || ageAschiKina[ekhonAchi]==true){
            return false;
        }
        
        if(laaf[ekhonAchi]==0){
            return true;
        }
        
        ageAschiKina[ekhonAchi]=true;
        
        int samne=ekhonAchi+laaf[ekhonAchi];
        int pichone=ekhonAchi-laaf[ekhonAchi];
        
        return khuj(laaf,samne,ageAschiKina) || khuj(laaf,pichone,ageAschiKina);
    }
    
public:
    bool canReach(vector<int>& arr, int start){
        vector<bool> ageAschiKina(arr.size(),false);
        return khuj(arr,start,ageAschiKina);
    }
};
