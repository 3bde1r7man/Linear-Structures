#include <iostream>

using namespace std;

const int SIZE = 200; 

template <class T>
class ArrayList {
    T data[SIZE]; 
    int size; 

public:
    ArrayList() {
        size = 0;
    }

   
    void insert(T element) {
        if (size < SIZE) {
            data[size++] = element;
        }
    }

    void insertAt(T element, int index) {
        if (size < SIZE && index >= 0 && index <= size) {
            for (int i = size - 1; i >= index; i--) {
                data[i + 1] = data[i];
            }
            data[index] = element;
            size++;
        }
    }

    T retrieveAt(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else
        {
            cout << "Out of Index";
        }
    }

    void removeAt(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
        }
    }

    // Replace the element at a specific index with a new element
    void replaceAt(T newElement, int index) {
        if (index >= 0 && index < size) {
            data[index] = newElement;
        }
    }

    // Check if an element at a specific index is equal to a given element
    bool isItemAtEqual(T element, int index) {
        if (index >= 0 && index < size) {
            return data[index] == element;
        }
        return false;
    }

    // Check if the list is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the list is full
    bool isFull() {
        return size == MAX_SIZE;
    }

    // Get the current size of the list
    int listSize() {
        return size;
    }

    // Get the maximum size of the list
    int maxListSize() {
        return MAX_SIZE;
    }

    // Clear the list by setting the size to 0
    void clear() {
        size = 0;
    }

    // Print the elements of the list
    void print() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }
};