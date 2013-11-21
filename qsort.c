#include <stdlib.h>
#include <stdio.h>

int search(const int *, int, int, int);
void sort(int *, int, int);
void swap(int *, int, int);
void print(const int *, int, int);
int compare(void*, void*);

int main(int argc, const char * argv[])
{
  int v[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  
  print(v, 0, 10);
  sort(v, 0, sizeof(v)/sizeof(*v));
  print(v, 0, 10);


  int find = 5;
  int found = search(v, find, 0, sizeof(v)/sizeof(*v));
  printf("Found %d at index %d\n", find, found);
  
  return 0;
}

int search(const int *v, int find, int start, int end)
{
  if (start >= end) return -1;
  int i = (start + end)/2;
  
  int res = compare(&find, (void *)(v+i));
  printf("-> %d-%d = %d\n", find, *(v+i), res);

  if (*(v+i) == find) {
    return find;
  }
  else if (*(v+i) < find) {
    return search(v, find, ++i, end);
  }
  else if (*(v+i) > find) {
    return search(v, find, 0, --i);
  }
  return -1;
}

int compare(void *pa, void *pb)
{
  int a = *(int *)pa;
  int b = *(int *)pb;
  return a - b;
}

void print(const int *v, int start, int end) {
  for (int i = start; i < end; i++) {
    printf("%d ", *(v+i));
  }
  printf("\n");
}

void sort(int *data, int left, int right)
{
  int i, last;
  if (left >= right) return;
  swap(data, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; i++) {
    if ( *(data+i) < *(data+left)) {
      swap(data, i, ++last);
    }
  }
  swap(data, left, last);
  sort(data, left, last-1);
  sort(data, last+1, right);
}

void swap(int *v, int a, int b)
{
  int t = *(v+a);
  *(v+a) = *(v+b);
  *(v+b) = t;
}














