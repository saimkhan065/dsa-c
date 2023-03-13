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

int main() {
    struct Array arr;
    arr.arr_size = 11; //desired arr size for this example - changed from 10 to 11 for one insert
    arr.pointer_to_arr = (int *)malloc(arr.arr_size * sizeof (int)); //allocate memory and point to address
    arr.arr_length = 0; //arr is empty

    for(int i=0; i<arr.arr_size; i++){ //taking 10 elements in arr as example
        arr.pointer_to_arr[i] = i;
        arr.arr_length++; //increment length as element is added in array
    }

    displayArray(arr);
    insert_in_array(arr, 1, 99);
    printf("\n");
    displayArray(arr);
    return 0;
}

void displayArray(struct Array arr){
    for(int i=0; i<arr.arr_length; i++){
        printf("%d\t", arr.pointer_to_arr[i]);
    }
}

void insert_in_array(struct Array arr, int index, int element){
    for(int i=arr.arr_length; i>=index; i--){
        arr.pointer_to_arr[i] = arr.pointer_to_arr[i-1]; //shift array for insert at index
    }
    arr.pointer_to_arr[index] = element;
    arr.arr_length++;
}

