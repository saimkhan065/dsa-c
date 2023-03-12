/*
 * objective : implement arrays using struct
 */

#include <stdio.h>
#include <stdlib.h>
struct Array{ // array struct
    int *pointer_to_arr;
    int arr_size;
    int arr_length;

};
void displayArray(struct Array arr); // display arr contents

int main() {
    struct Array arr;
    arr.arr_size = 10; //desired arr size for this example
    arr.pointer_to_arr = (int *)malloc(arr.arr_size * sizeof (int)); //allocate memory and point to address
    arr.arr_length = 0; //arr is empty

    for(int i=0; i<arr.arr_size; i++){ //taking 10 elements in arr as example
        arr.pointer_to_arr[i] = i;
        arr.arr_length++; //increment length as element is added in array
    }

    displayArray(arr);
    return 0;
}

void displayArray(struct Array arr){
    for(int i=0; i<arr.arr_length; i++){
        printf("%d\n", arr.pointer_to_arr[i]);
    }
}
