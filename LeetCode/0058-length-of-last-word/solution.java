class Solution {
    public int lengthOfLastWord(String s){
        String trimmeds=s.trim();
        int len=0;
        for(char c:trimmeds.toCharArray()){
            if(c==' '){
                len=0;
            }
            else{
                len++;
            }
        }
        
        return len;
    }
}
