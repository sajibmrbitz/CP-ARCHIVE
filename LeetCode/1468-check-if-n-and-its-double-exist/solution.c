bool checkIfExist(int* arr, int arrSize) {
    bool exists=false;
    for(int i=0;i<arrSize;i++){
       for(int j=0;j<arrSize;j++){ 
           if(i!=j && arr[i]==2*arr[j])
               exists= true;
    }
}
return exists;
}
