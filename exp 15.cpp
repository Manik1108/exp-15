#include <iostream>

class DynamicArray {
private:
    int *arr; 
    int size; 
    int capacity; 
public:

    DynamicArray(int initialCapacity) : size(0), capacity(initialCapacity) {
        arr = new int[capacity];
    }


    ~DynamicArray() {
        delete[] arr;
    }


    void add(int value) {

        if (size == capacity) {
            int *temp = new int[2 * capacity];
            for (int i = 0; i < size; ++i) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity *= 2;
        }
        arr[size++] = value;
    }


    int getSize() const {
        return size;
    }


    int get(int index) const {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of bounds" << std::endl;
            return -1; 
        }
        return arr[index];
    }
};

int main() {

    DynamicArray myArray(5);


    for (int i = 0; i < 10; ++i) {
        myArray.add(i);
    }

    std::cout << "Array elements: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}

