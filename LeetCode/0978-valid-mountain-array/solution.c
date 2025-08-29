bool validMountainArray(int* arr, int arrSize){
    bool mountain =false;
    if(arrSize<3) return mountain;

    int i = 0;
    while(i<(arrSize-1) && arr[i]<arr[i+1]){
        i++;
    }
    if (i==0 || i==arrSize-1){  //1st or last cannot be peak
        return mountain;
    }

    while(i<(arrSize-1) && arr[i]>arr[i+1]){
        i++;
    }
    if(i==arrSize-1)    mountain=true;
    return mountain;
}

