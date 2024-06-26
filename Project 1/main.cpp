#include <iostream>
#include "fstream"
using namespace std;
int binary_search(int *arr,int right,int key,int&no_of_comparsion){
    int left=0;
    while(left<=right){
        int mid=(right+left)/2;

        if(arr[mid]==key){
            no_of_comparsion++;
            return mid;
        }
        else if(arr[mid]<key){
            no_of_comparsion++;
            left=mid+1;
        }
        else if(arr[mid]>key){
            no_of_comparsion++;
            right=mid-1;
        }


    }
    return left;
}
void Insertion_sort_linear_search(int *arr,int n){
    int sorted_array[n];
    for (int i = 0; i < n; ++i) {
        sorted_array[i]=arr[i];
    }
    int no_of_comparisons=0,no_of_shifts=0;

    for (int i = 1,j; i <n ; ++i) {
        int temp=sorted_array[i];

        for (j=i;  j>0&&sorted_array[j-1]>temp ; j--,no_of_comparisons++) {
            sorted_array[j]=sorted_array[j-1];
            no_of_shifts++;

        }
        sorted_array[j]=temp;
        no_of_shifts++;
    }
    cout<<"Insertion_sort_linear: "<<endl;
    cout<<"Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout<<sorted_array[i]<<" ";
    }
    cout << endl;
    cout << "Comparisons: " << no_of_comparisons << endl;
    cout << "Moves: " << no_of_shifts << endl;
}
void Insertion_sort_binary_search(int *arr,int n){
    int sorted_array[n];
    for (int i = 0; i < n; ++i) {
        sorted_array[i]=arr[i];
    }
    int no_of_comparisons=0,no_of_shifts=0;
    for (int i = 1; i < n; ++i) {
        int key=sorted_array[i];
        int key_index= binary_search(sorted_array,i-1,key,no_of_comparisons);
        for (int j = i; j >  key_index; --j) {
            swap(sorted_array[j],sorted_array[j-1]);
            no_of_shifts++;
        }
    }
    cout<<" Insertion_sort_binary: "<<endl;
    cout<<"Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout<<sorted_array[i]<<" ";
    }
    cout << endl;
    cout << "Comparisons: " << no_of_comparisons << endl;
    cout << "Moves: " << no_of_shifts << endl;

}
void selectionSort(int *arr,int n)
{
    int compare = 0;
    int shifts = 0;
    for(int i=0,j,least; i<n-1;i++){
        for(j=i+1,least = i; j < n; j++)
        {

            if(arr[j] < arr[least])
                least = j;
            compare++;
            //shifts++;
        }
        swap(arr[least],arr[i]);
        shifts+=3;
    }
    cout<<"Selection Sort: "<<endl;
    cout<<"Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout << endl;
    cout << "Comparisons: " << compare << endl;
    cout << "Moves: " << shifts << endl;
}
void ShellSort(int *arr, int n)
{
    int compare = 0;
    int shifts = 0;

    for ( int gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; ++i)
        {
            compare++;
            int tmp = arr[i];
            shifts++;
            int j = i;
            for(; j >= gap && tmp < arr[j - gap]; compare++,j-= gap){
                arr[j] =  arr[j - gap];
                shifts++;
            }
            arr[j] = tmp;
            shifts++;
        }
    }

    cout<<"Shell Sort: "<<endl;
    cout<<"Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout << endl;
    cout << "Comparisons: " << compare << endl;
    cout << "Moves: " << shifts << endl;

}
void merge(int *arr, int left, int mid,int right,int &no_of_comparsion_of_merge_sort,int &moves_of_merge_sort){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; ++i)
        L[i]=arr[left+i];no_of_comparsion_of_merge_sort++;moves_of_merge_sort+=3;

    for (int i = 0; i < n2; ++i)
        R[i]=arr[mid+i+1];no_of_comparsion_of_merge_sort++;moves_of_merge_sort+=3;

    int k=left,i=0,j=0;
    while(i<n1 and j<n2){
        if(L[i]<R[j]){
            arr[k++]=L[i++];
        }
        else {
            arr[k++]=R[j++];
        }
        no_of_comparsion_of_merge_sort++;
        moves_of_merge_sort+=3;
    }
    while (i<n1)
        arr[k++]=L[i++],moves_of_merge_sort+=3;
    while(j<n2)
        arr[k++]=R[j++],moves_of_merge_sort+=3;
}
void mergesort(int *arr,int left,int right,int size){
    int no_of_comparsion_of_merge_sort=0,moves_of_merge_sort=0;
    if(left>=right){
        return;
    }
    int mid=(left+right)/2;
    mergesort(arr,left,mid,size);
    mergesort(arr,mid+1,right,size);
    merge(arr,left,mid,right,no_of_comparsion_of_merge_sort,moves_of_merge_sort);
    if(left==0 and right==size-1){
        cout<<"merge Sort: "<<endl;
        cout<<"Sorted array: ";
        for (int i = 0; i < size; ++i) {
            cout<<arr[i]<<" ";
        }
        cout << endl;
        cout << "Comparisons: " << no_of_comparsion_of_merge_sort << endl;
        cout << "Moves: " << moves_of_merge_sort << endl;
    }


}
int main() {
    /*int tc = 1;
    //cin >> tc;
    while (tc--) {
     */
        cout<<"Task 1"<<endl;
        cout<<"========================================================"<<endl;

    int n;cin>>n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        cin>>array[i];
    }
    Insertion_sort_linear_search(array,n);
    Insertion_sort_binary_search(array,n);
    ifstream myfile("arrays.txt");

    cout<<"========================================================"<<endl;
    cout<<"Task 2"<<endl;
    cout<<"========================================================"<<endl;


    int size;
    while (myfile>>size){
        int arr[size];
        for (int i = 0; i < size; ++i) {
            myfile>>arr[i];
        }
        cout<<"original array-> ";
        for (int i = 0; i < size; ++i) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        int arrayofshellsort[size];
        int arrayofmergesort[size];
        copy(arr,arr+size,arrayofmergesort);
        copy(arr,arr+size,arrayofshellsort);
        selectionSort(arrayofshellsort,size);
        ShellSort(arr,size);
        mergesort(arrayofmergesort,0,size-1,size);

    }
    myfile.close();
}


