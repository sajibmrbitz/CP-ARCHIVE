#include <stdio.h>
#include <stdlib.h>

int findMaxConsecutiveOnes(int nums[],int n){
    int count=0,max1=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            count++;
            if(count>max1)  max1=count;
        }
        else count=0;
    }
    return max1;
}
