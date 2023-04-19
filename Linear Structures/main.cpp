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
        return size == SIZE;
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




template <class T>
class SingleListNode {
public:
    T data;
    SingleListNode<T>* next;

    SingleListNode(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class SingleLinkedList {
    SingleListNode<T>* head;
    SingleListNode<T>* tail;
    int size;

public:
    SingleLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~SingleLinkedList() {
        clear();
    }

    void insertAtHead(T element) {
        SingleListNode<T>* node = new SingleListNode<T>(element);

        if (head == NULL) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head = node;
        }

        size++;
    }


    void insertAtTail(T element) {
        SingleListNode<T>* node = new SingleListNode<T>(element);

        if (tail == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }

        size++;
    }


    void insertAt(T element, int index) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of range");
        }

        if (index == 0) {
            insertAtHead(element);
        }
        else if (index == size) {
            insertAtTail(element);
        }
        else {
            SingleListNode<T>* node = new SingleListNode<T>(element);
            SingleListNode<T>* curr = head;

            for (int i = 0; i < index-1; i++) {

                curr = curr->next;
            }

            node->next = curr->next;
            curr->next = node;

            size++;
        }
    }

    
    void removeAtHead() {
        if (head == NULL) {
            throw out_of_range("List is empty");
        }

        SingleListNode<T>* node = head;
        head = head->next;

        if (head == NULL) {
            tail = NULL;
        }

        delete node;

        size--;
    }


    void removeAtTail() {
        if (tail == NULL) {
            throw out_of_range("List is empty");
        }

        if (size == 1) {
            delete head;
            head = NULL;
            tail = NULL;
            size = 0;
        }
        else {
            SingleListNode<T>* prev = NULL;
            SingleListNode<T>* curr = head;

            while (curr->next->next != NULL) {
                curr = curr->next;
            }

            curr->next = NULL;
            tail = curr;

            delete curr->next;

            size--;
        }
    }


    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        if (index == 0) {
            removeAtHead();
        }
        else if (index == size - 1) {
            removeAtTail();
        }
        else {
            SingleListNode<T>* prev = NULL;
            SingleListNode<T>* curr = head;

            for (int i = 0; i < index; i++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;

            delete curr;

            size--;
        }
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        SingleListNode<T>* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->data;
    }


    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        SingleListNode<T>* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        curr->data = newElement;
    }

    bool isExist(T element) {
        SingleListNode<T>* curr = head;

        while (curr != NULL) {
            if (curr->data == element) {
                return true;
            }

            curr = curr->next;
        }

        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        SingleListNode<T>* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->data == element;
    }


    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
            throw out_of_range("Index out of range");
        }

        if (firstItemIdx == secondItemIdx) {
            return;
        }

        if (firstItemIdx > secondItemIdx) {
            swap(secondItemIdx, firstItemIdx);
            return;
        }

        SingleListNode<T>* prevFirst = NULL;
        SingleListNode<T>* currFirst = head;

        for (int i = 0; i < firstItemIdx; i++) {
            prevFirst = currFirst;
            currFirst = currFirst->next;
        }

        SingleListNode<T>* prevSecond = prevFirst;
        SingleListNode<T>* currSecond = currFirst;

        for (int i = firstItemIdx; i < secondItemIdx; i++) {
            prevSecond = currSecond;
            currSecond = currSecond->next;
        }

        prevFirst->next = currSecond;
        prevSecond->next = currFirst;

        SingleListNode<T>* temp = currFirst->next;
        currFirst->next = currSecond->next;
        currSecond->next = temp;
    }

    bool isEmpty() {
        return size == 0;
    }

    int linkedListSize() {
        return size;
    }


    void clear() {
        while (head != NULL) {
            SingleListNode<T>* node = head;
            head = head->next;
            delete node;
        }

        tail = NULL;
        size = 0;
    }

    void print() {
        SingleListNode<T>* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }
};

int main() {
}
