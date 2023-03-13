/*
 * objective : implement arrays using struct
 * 1. Insert/Add
 * 2. Delete
 */

#include <stdio.h>
#include <stdlib.h>
struct Array{ // array struct
    int *pointer_to_arr;
    int arr_size;
    int arr_length;

};

void displayArray(struct Array arr); // display arr contents
void insert_in_array(struct Array arr, int index, int element); //insert element in array at given index
void delete_from_array(struct Array arr, int index); //delete element at index

int main() {
    struct Array arr;
    arr.arr_size = 20; //changed to 20 to accommodate more example operations
    arr.pointer_to_arr = (int *)malloc(arr.arr_size * sizeof (int)); //allocate memory and point to address
    arr.arr_length = 0; //arr is empty

    for(int i=0; i<arr.arr_size-10; i++){ //taking 10 elements in arr as example
        arr.pointer_to_arr[i] = i;
        arr.arr_length++; //increment length as element is added in array
    }
//Print Statements
    printf("Basic array length: %d\n",arr.arr_length);
    displayArray(arr);
    insert_in_array(arr, 1, 99);
    delete_from_array(arr, 1);
    return 0;
}

void displayArray(struct Array arr){
    for(int i=0; i<arr.arr_length; i++){
        printf("%d\t", arr.pointer_to_arr[i]);
    }
}

void insert_in_array(struct Array arr, int index, int element){
    for(int i=arr.arr_length; i>index; i--){
        arr.pointer_to_arr[i] = arr.pointer_to_arr[i-1]; //shift elements in array
    }
    arr.pointer_to_arr[index] = element;
    arr.arr_length++;
    printf("\nLength after insertion: %d\n", arr.arr_length);
    displayArray(arr);
}

void delete_from_array(struct Array arr, int index){
    for(int i=index; i<arr.arr_length-1; i++){
        arr.pointer_to_arr[i] = arr.pointer_to_arr[i+1]; //shift elements back starting from index to overwrite
    }
    arr.arr_length--;
    printf("\nLength after deletion: %d\n", arr.arr_length);
    displayArray(arr);
}

