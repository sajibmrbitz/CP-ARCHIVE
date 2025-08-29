int findNumbers(int* nums, int numsSize) {
    
    int evendigits=0;
    for(int i=0;i<numsSize;i++){
        int digits=0;
        while(nums[i]){
            digits++;
            nums[i]/=10;
        }
        if(digits%2==0)  evendigits++;
    }
    return evendigits;
}
