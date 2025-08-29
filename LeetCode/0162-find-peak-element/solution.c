int findPeakElement(int* nums, int numsSize) {
    int peaki=0;
    for(int i=1;i<numsSize-1;i++){
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
            peaki=i;
        }
    }
    if(nums[numsSize-1]>nums[peaki] && nums[numsSize-1]>nums[numsSize-2]) peaki=numsSize-1;
    return peaki;
}
