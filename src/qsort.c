#include "stdio.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition1(int a[], int l, int h) {
  int pivot = a[h];
  int i = l - 1;
  for(int j = l; j < h; j++) {
    if(a[j] < pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i+1], &a[h]);
  return i+1;
}

int partition2(int a [], int l, int h) {
  int temp = a[l];
  int i = l, j = h;
  while(i < j) {
    while(i < j && a[j] >= temp) j--;
    if(i < j) a[i++] = a[j];
    while(i < j && a[i] < temp) i++;
    if(i < j) a[j--] = a[i];
  }
  a[i] = temp;
  return i;
}

void my_qsort(int a[], int l, int h) {
  if(l < h) {
    int p = partition2(a, l, h);
    my_qsort(a, l, p - 1);
    my_qsort(a, p + 1, h); 
  }
}

int main() {
  int tmp[] = {2,4,1,3,3,7,5};
  my_qsort(tmp, 0, sizeof(tmp)/sizeof(int)-1);
  for(int i = 0; i < sizeof(tmp)/sizeof(int); i++) {
    printf("%d ", tmp[i]);
  }
}
