int search(int* nums, int numsSize, int target) {
    int f= 0,l=numsSize-1,m;
    while(f<=l){
        m=(f+l)/2;
        if(nums[m]==target)        return m;
        else if (nums[m]<target)   f = m + 1;
        else                       l = m - 1;
    }
    return -1;
}

