#pragma once
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

            for (int i = 0; i < index - 1; i++) {

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

template <class T>
class DoubleListNode
{
public:
    T data;
    DoubleListNode<T>* prev;
    DoubleListNode<T>* next;

    DoubleListNode(T d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }

};

template<class T>
class DoubleLinkedList
{
    DoubleListNode<T>* head;
    DoubleListNode<T>* tail;
    int size;
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    ~DoubleLinkedList() {
        clear();
    }
    void insertAtHead(T element) {
        DoubleListNode<T>* node = new DoubleListNode<T>(element);
        if (head == NULL) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }
    void insertAtTail(T element) {
        DoubleListNode<T>* node = new DoubleListNode<T>(element);
        if (tail == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
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
        else
        {
            DoubleListNode<T>* node = new DoubleListNode<T>(element);
            DoubleListNode<T>* curr = head;
            for (int i = 0; i < index; i++)
            {
                curr = curr->next;
            }
            node->next = curr;
            curr->prev->next = node;
            node->prev = curr->prev;
            curr->prev = node;

            size++;
        }


    }
    void insertAfter(DoubleListNode<T>* prevNode, int data) {
        if (prevNode == NULL) {
            cout << "Previous node cannot be null\n";
            return;
        }
        DoubleListNode<T>* node = new DoubleListNode<T>(data);
        node->next = prevNode->next;
        node->prev = prevNode;
        prevNode->next = node;
        if (node->next != nullptr) {
            node->next->prev = node;
        }
        else {
            tail = node;
        }
        size++;

    }
    void removeAtHead() {
        if (head == NULL)
        {
            cout << "List is already empty\n";
            return;
        }
        DoubleListNode<T>* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        delete temp;
        size--;
    }
    void removeAtTail() {
        if (tail == NULL) {
            cout << "List is already empty\n";
            return;
        }
        DoubleListNode<T>* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        else {
            head = NULL;
        }
        delete temp;
        size--;
    }
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        if (index == 0) {
            removeAtHead();
            return;
        }
        if (index == size - 1) {
            removeAtTail();
            return;
        }
        DoubleListNode<T>* curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        delete curr;
        size--;
    }
    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        DoubleListNode<T>* curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }
    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        DoubleListNode<T>* curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        curr->data = newElement;
    }
    bool isExist(T element) {
        DoubleListNode<T>* curr = head;
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
        DoubleListNode<T>* curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        if (curr->data == element)
            return true;

        return false;
    }
    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
            throw out_of_range("Index out of range");
        }
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        DoubleListNode<T>* firstNode = head;
        for (int i = 0; i < firstItemIdx; i++)
        {
            firstNode = firstNode->next;
        }
        DoubleListNode<T>* secNode = head;
        for (int i = 0; i < secondItemIdx; i++)
        {
            secNode = secNode->next;
        }
        DoubleListNode<T>* temp = firstNode->prev;
        firstNode->prev = secNode->prev;
        secNode->prev = temp;
        temp = firstNode->next;
        firstNode->next = secNode->next;
        secNode->next = temp;
        if (firstNode->prev == nullptr) {
            head = firstNode;
        }
        else {
            firstNode->prev->next = firstNode;
        }
        if (firstNode->next == nullptr) {
            tail = firstNode;
        }
        else {
            firstNode->next->prev = firstNode;
        }
        if (secNode->prev == nullptr) {
            head = secNode;
        }
        else {
            secNode->prev->next = secNode;
        }
        if (secNode->next == nullptr) {
            tail = secNode;
        }
        else {
            secNode->next->prev = secNode;
        }

    }
    void reverse() {
        DoubleListNode<T>* curr = head;
        while (curr != nullptr)
        {
            DoubleListNode<T>* temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            curr = temp;
        }
        curr = head;
        head = tail;
        tail = curr;
    }
    bool isEmpty() {
        return size == 0;
    }
    int doubleLinkedListSize() {
        return size;
    }
    void clear() {
        while (head != nullptr) {
            DoubleListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    void forwardTraversal() {
        DoubleListNode<T>* curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }
    void backwardTraversal() {
        DoubleListNode<T>* curr = tail;
        while (curr != nullptr)
        {
            cout << curr->data << ' ';
            curr = curr->prev;
        }
        cout << '\n';
    }

};

template<class T>
class Queue
{
private:
    DoubleLinkedList<T> lst;
public:


    ~Queue()
    {
        clear();
    }


    void enqueue(T element) {
        lst.insertAtHead(element);
    }
    T dequeue() {
        if (lst.isEmpty()) {
            cout << "Queue is empty\n";
            return T();
        }
        T first = lst.retrieveAt(lst.doubleLinkedListSize() - 1);
        lst.removeAtTail();
        return first;
    }
    T first() {
        if (lst.isEmpty()) {
            cout << "Queue is empty\n";
            return T();
        }
        return lst.retrieveAt(lst.doubleLinkedListSize() - 1);
    }
    bool isEmpty() {
        return lst.isEmpty();
    }
    int queueSize() {
        return lst.doubleLinkedListSize();
    }
    void clear() {
        lst.clear();
    }
    void print() {
        lst.backwardTraversal();
    }

};
