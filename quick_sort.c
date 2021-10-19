#include <stdio.h>

int partition(int *A, int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do {
      while(A[i]<=pivot){
         i++;
     }
      while(A[j]>pivot){
         j--;
     }
     if(i<j){
         temp=A[i];
         A[i]=A[j];
         A[j]=temp;
     }
    } while (i<j);
    
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}

void quick_sort(int *A, int low, int high)
{
    int partitionIndex; 

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quick_sort(A, low, partitionIndex - 1); 
        quick_sort(A, partitionIndex + 1, high); 
    }
}

int main(){
       int size,i;
	printf("enter the size of array :");
	scanf("%d",&size);
	int arr[size];
	
	printf("enter the elements :\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}	  
	
    quick_sort(arr,0,size); 
	printf("array after sorting\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
