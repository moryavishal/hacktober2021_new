#include<stdio.h>
int maxof (int a[], int n){
   int max = a[0];
   int i;
   for ( i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}
void radix_sort (int a[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, place = 0, divisor = 1, lar, pass;
   lar = maxof (a, n);
   while (lar > 0){
      place++;
      lar /= 10;
   }
   for (pass = 0; pass < place; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
   }
}
int main (){
   int i, n, a[100];
   printf ("Enter the size of array: ");
   scanf ("%d", &n);
   printf ("Enter elements: ");
   for (i = 0; i < n; i++){
      scanf ("%d", &a[i]);
   }
   radix_sort (a, n);
   printf ("array after sorting : ");
   for (i = 0; i < n; i++)
      printf ("%d ", a[i]);
   return 0;
}
