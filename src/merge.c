#include <stdio.h>
void merge(int arr[], int l, int m, int h) { 
  int tmp[h - l + 1];
  int i = l, j = m + 1, k = 0;
  while(i <= m && j <= h) {
     if(arr[i] < arr[j]) {
       tmp[k] = arr[i];
       i++;
     } else {
       tmp[k] = arr[j];
       j++;
     }
     k++;
  }
  while(i <= m) {
    tmp[k++] = arr[i++];
  }

  while(j <= h) {
    tmp[k++] = arr[j++];
  }
  for(int i = l, k = 0; i <= h; i++, k++) {
    arr[i] = tmp[k];
  }
}

void merge_sort(int arr[], int l, int h) {
  if(l >= h) return;
  int m = (l+h)/2;
  merge_sort(arr, l, m);
  merge_sort(arr, m+1, h);
  merge(arr, l, m, h);
}

int main() {
  int tmp[] = {2,4,1,3,7,5};
  merge_sort(tmp, 0, sizeof(tmp)/sizeof(int)-1);
  for(int i = 0; i < sizeof(tmp)/sizeof(int); i++) {
    printf("%d ", tmp[i]);
  }
}
