#include <iostream>
template<typename T>
void Compare(T arr[], int left, int mid , int right ){
    int l_ind = 0;//left array index
    int m_ind =left;//main array index
    int r_ind = 0;// right array index

    int l_size = mid-left+1;//left array size
    int r_size = right-mid;//right array size


    T L[l_size], R[r_size];////temp arrays 

    // copying
    
    for(size_t i = 0; i < l_size; ++i)
        L[i] = arr[left+i];
    
    for(size_t i = 0; i < r_size; ++i)
        R[i] = arr[mid + i + 1];
    //compareing
    while((l_ind < l_size)&&(r_ind < r_size)){

        if(L[l_ind]<=R[r_ind]){
            arr[m_ind] =L[l_ind];
            ++l_ind;
        }
        else{
            arr[m_ind] = R[r_ind];
            ++r_ind;
        }
        ++m_ind;
    
    }

    //adding remaining part
    while(l_ind < l_size){
        arr[m_ind] = L[l_ind];
        ++l_ind;
        ++m_ind;
    }
    while(r_ind < r_size){
        arr[m_ind] = R[r_ind];
        ++r_ind;
        ++m_ind;
    }


}
    template<typename T>
    void merge_sort(T arr[], int start, int end){
        if(start < end){

            int curr = start+(end-start)/2;              //middle of array


            merge_sort(arr, start, curr );
            merge_sort(arr, curr+1, end);

            Compare(arr,start, curr, end);
        }
    }

int main(){
    int test [15] = {12,11,5,6,14,7,23,35,1,2};
    int size = 10;
    merge_sort(test,0,size-1);
    
    for(size_t i = 0; i < size; ++i)
    {
        std::cout<<"test["<<i<<"] = "<<test[i]<<std::endl;
    }
    
    return 0;
}