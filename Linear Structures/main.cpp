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

    void replaceAt(T newElement, int index) {
        if (index >= 0 && index < size) {
            data[index] = newElement;
        }
    }

    bool isItemAtEqual(T element, int index) {
        if (index >= 0 && index < size) {
            return data[index] == element;
        }
        return false;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    int listSize() {
        return size;
    }

    int maxListSize() {
        return SIZE;
    }

    void clear() {
        size = 0;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};