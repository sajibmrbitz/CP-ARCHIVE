int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *result=(int *)malloc(numsSize*sizeof(int));
    *returnSize=numsSize;
    for(int i=0;i<numsSize;i++){
        result[i]=nums[i]*nums[i];

        
    }
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(result[i]>result[j])
            {
            int temp=result[j];
            result[j]=result[i];
            result[i]=temp;
            }
        }
    }
    return result;
}
