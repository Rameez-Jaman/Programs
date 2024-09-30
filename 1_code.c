#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define INITIAL_CAPACITY 5
#define CHUNK_SIZE 5

int* dyn_arr;
int len_of_arr = 0;
int capacity = INITIAL_CAPACITY;

void ensure_capacity() {
    if(len_of_arr >= capacity) {
        capacity += CHUNK_SIZE;
        dyn_arr = (int*)realloc(dyn_arr, capacity * sizeof(int));
    }
}

void shrink_capacity_if_needed() {
    if(capacity - len_of_arr > 4) {
        capacity -= CHUNK_SIZE;
        dyn_arr = (int*)realloc(dyn_arr, capacity * sizeof(int));
    }
}

void append(int x) {
    ensure_capacity();
    dyn_arr[len_of_arr++] = x;
}

int remove_element(int x) {
    if(len_of_arr > 0) {
        int found = false;
        int temp_index;
        for(int i = 0; i < len_of_arr; i++) {
            if(dyn_arr[i] == x) {
                found = true;
                temp_index = i;
                break;
            }
        }
        if (found) {
            for(int i = temp_index; i < len_of_arr - 1; i++) {
                dyn_arr[i] = dyn_arr[i + 1];
            }
            len_of_arr--;
            shrink_capacity_if_needed();
            return true;
        } else {
            printf("Unable to remove %d \n", x);
            return false;
        }
    }
    printf("Unable to remove %d \n", x);
    return false;
}

int removeAt(int index) {
    if(index >= 0 && index < len_of_arr) {
        for(int i = index; i < len_of_arr - 1; i++) {
            dyn_arr[i] = dyn_arr[i + 1];
        }
        len_of_arr--;
        shrink_capacity_if_needed();
        return true;
    }
    return false;
}

int arr_length() {
    return len_of_arr;
}

void print() {
    printf("Dynamic array elements are:\n");
    for(int i = 0; i < len_of_arr; i++) {
        printf("%d ", dyn_arr[i]);
    }
    printf("\n");
}

int* slice(int start, int end) {
    if(start < 0 || end > len_of_arr || start >= end) {
        return NULL;
    }
    int slice_length = end - start;
    int* sliced_arr = (int*)malloc(slice_length * sizeof(int));
    for(int i = 0; i < slice_length; i++) {
        sliced_arr[i] = dyn_arr[start + i];
    }
    return sliced_arr;
}

int main() {
    dyn_arr = (int*)malloc(capacity * sizeof(int));

    append(1);
    print();
    append(2);
    print();
    append(3);
    print();
    append(4);
    print();
    append(5);
    print();
    append(6);
    print();

    // Remove element
    if(remove_element(1)) {
        printf("Element 1 removed successfully.\n");
    } else {
        printf("Element 1 not found.\n");
    }
    print();

    // Remove element at index
    if(removeAt(2)) {
        printf("Element at index 2 removed successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
    print();

    // Slice the array
    int* sliced_arr = slice(1, 3);
    if(sliced_arr) {
        printf("Sliced array elements are:\n");
        for(int i = 0; i < 2; i++) {
            printf("%d ", sliced_arr[i]);
        }
        printf("\n");
        free(sliced_arr);
    } else {
        printf("Invalid slice range.\n");
    }

    printf("Array length: %d\n", arr_length());
    print();

    free(dyn_arr);
    return 0;
}

