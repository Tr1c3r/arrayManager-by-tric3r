#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int *arr = NULL; // global pointer to store the array
int size = 0; // current size of the array

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for(int j = low ; j < high ; j++) {
    if(arr[j] <= pivot){
      i++;
      swap(&arr[j], &arr[i]);
    }
  }

  swap(&arr[i+1], &arr[high]);
  return i+1;

}

void quickSort(int arr[], int low, int high) {
  if(low < high){
    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

void create() {
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  // Allocate memory for n integers.
  arr = (int *)malloc(size * sizeof(int));

  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  printf("Enter %d integers: \n", size);
  for (int i = 0 ; i < size ; i++){
    scanf("%d", &arr[i]);
  }

  system("clear");

  printf("Array created succesfully.\n");
}

void modify() {
  if (arr == NULL){
    system("clear");
    printf("No array created. Create one first.\n");
    return;
  }

  int index; int newValue;
  printf("Enter index to modify from 0 to %d: ", size - 1);
  scanf("%d", &index);

  if (index < 0 || index >= size) {
    system("clear");
    printf("Insert a valid index number.\n");
    return;
  }

  printf("Insert the new value: ");
  scanf("%d", &newValue);
  arr[index] = newValue;

  system("clear");

  printf("Value updated succesfully!\n");
}

void resize() {
  if(arr == NULL){
    system("clear");
    printf("No array created. Create one first.\n");
    return;
  }

  int newSize;
  printf("Enter the new size: ");
  scanf("%d", &newSize);

  int *newArr = (int * )realloc(arr, newSize * sizeof(int));
  if(newArr == NULL) {
    printf("Memory reallocation failed.\n");
    return;
  }

  arr = newArr;
  if(newSize > size){
    printf("New elements will be uninitialized.\n");
  }
  size = newSize;
  system("clear");
  printf("Array resized succesfully.\n");
}

void printArray(){
  if(arr == NULL){
    printf("No array created. Create one first.\n");
    return;
  }

  printf("Current array: ");
  for(int i = 0 ; i < size ; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

}

void deleteElement() { 
  if(arr == NULL){
    system("clear");
    printf("No array created. Create one first.\n");
    return;
  }
  
  int indexToDelete;
  printf("Which element you want to delete?(input the index): ");
  scanf("%d", &indexToDelete);

  arr[indexToDelete] = 0;
  system("clear");
  printf("Element deleted succesfully!\n");
}

int main() {
  system("clear");
  char action[2];

  while (true) {
    //system("clear");
    printf("Options: \n");
    printf("What you want to do?: \n");
    printf("c: create an array with n size\n");
    printf("s: sort the array elements\n");
    printf("m: modify an existing array\n");
    printf("d: Delete an element of the array\n");
    printf("r: resizes the array\n");
    printf("p: prints the array\n");
    printf("q: quit\n");
    printf("Write: ");
    scanf("%s", &action);
 
    if (strcmp(action, "c") == 0) {
      system("clear");
      create();
    }
    else if(strcmp(action, "s") == 0) {
      system("clear");
      quickSort(arr, 0, size -1);
      printf("Array sorted succesfully!\n");
      printArray();
    }
    else if (strcmp(action, "m") == 0) {
      system("clear");
      printArray();
      modify();
    }
    else if(strcmp(action, "r") == 0){
      system("clear");
      resize();
    }
    else if(strcmp(action, "d") == 0){
      system("clear");
      printArray();
      deleteElement();
    }
    else if(strcmp(action, "p") == 0){
      system("clear");
      printArray();
    }
    else if (strcmp(action, "q") == 0){
      system("clear");
      break;
    }
    else {
      printf("\nNot a valid option.\n");
    }
  }

  //Free memory before quitting
  free(arr);
  printf("Memory freed. Exiting program\n");

  return 0;
}
