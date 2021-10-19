#include<stdio.h>

int binarySerch(int arr[],int low,int max,int key){
	while(max>=low){
		int mid=(low+max)/2;
		if(arr[mid]==key){
			printf("key found :\nposition: ");
			return mid+1;
		}
		if(arr[mid]<key){
		low=mid+1;
		} else {
		max=mid-1;
		}
	}
	printf("key not found : ");
	return -1;
}
int main(){
    int num,size,i;
	printf("enter the size of array :");
	scanf("%d",&size);
	int arr[size];
	printf("enter the elements of array :");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}	
    
	printf("enter the no to serch :");
	scanf("%d",&num);
	
    int result=binarySerch(arr,0,size-1,num);
    printf("%d",result);
}
