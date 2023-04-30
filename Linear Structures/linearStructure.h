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
    SingleListNode<T>* getHead() {
        return head;
    }
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

struct Node
{
    int data;
    Node* next;
};

template <class T>
class CircularLinkedList
{
private:
    Node* head;
public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void insertAtHead(T newElement)
    {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtTail(T newElement)
    {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAt(T newElement, int index)
    {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL;
        Node* temp = head;
        int NumOfElements = 0;

        if (temp != NULL)
        {
            NumOfElements++;
            temp = temp->next;
        }
        while (temp != head)
        {
            NumOfElements++;
            temp = temp->next;
        }

        if (index < 1 || index >(NumOfElements + 1))
        {
            cout << "Invalid index";
        }
        else if (index == 1)
        {

            if (head == NULL)
            {
                head = newNode;
                head->next = head;
            }
            else
            {
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                newNode->next = head;
                head = newNode;
                temp->next = head;
            }
        }
        else
        {
            temp = head;
            for (int i = 1; i < index - 1; i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    //------------------------------------------


    void removeAtHead()
    {
        if (head != NULL)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node* temp = head;
                Node* firstNode = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                free(firstNode);
            }
        }
    }

    void removeAtTail()
    {
        if (head != NULL)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node* temp = head;
                while (temp->next->next != head)
                    temp = temp->next;
                Node* lastNode = temp->next;
                temp->next = head;
                free(lastNode);
            }
        }
    }

    void removeAt(int index)
    {
        Node* nodeToRemove = head;
        Node* temp = head;
        int NumOfElements = 0;

        if (temp != NULL)
        {
            NumOfElements++;
            temp = temp->next;
        }
        while (temp != head)
        {
            NumOfElements++;
            temp = temp->next;
        }

        if (index < 1 || index > NumOfElements)
        {
            cout << "Invalid index";
        }
        else if (index == 1)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                while (temp->next != head)
                    temp = temp->next;
                head = head->next;
                temp->next = head;
                free(nodeToRemove);
            }
        }
        else
        {

            temp = head;
            for (int i = 1; i < index - 1; i++)
                temp = temp->next;
            nodeToRemove = temp->next;
            temp->next = temp->next->next;
            free(nodeToRemove);
        }
    }



    void clear()
    {
        if (head != NULL)
        {
            Node* temp, * current;
            current = head->next;
            while (current != head)
            {
                temp = current->next;
                free(current);
                current = temp;
            }
            free(head);
            head = NULL;
        }
    }
    //------------------------------------------------------
    void swapNodeValues(int  firstItemIdx, int secondItemIdx)
    {

        Node* temp = head;
        int n = 0;
        if (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        while (temp != head)
        {
            n++;
            temp = temp->next;
        }

        if (firstItemIdx < 1 || firstItemIdx > n || secondItemIdx < 1 || secondItemIdx> n)
            return;

        Node* index1 = head;
        Node* index2 = head;
        for (int i = 1; i < firstItemIdx; i++)
        {
            index1 = index1->next;
        }
        for (int i = 1; i < secondItemIdx; i++)
        {
            index2 = index2->next;
        }
    }
    //------------------------
    Node* retrieveAt(int index)
    {
        Node* current = head;
        int c = 0;


        while (current != NULL && c != index)
        {
            current = current->next;
            c++;
        }


        if (current == NULL)
        {
            cout << "index is out of range" << endl;
            return NULL;
        }

        return current;
    }



    //-----------------------------------------

    void replaceAt(int value, int index) {
        if (index < 0 || index >= CircularLinkedListSize()) {
            throw out_of_range("Index out of range");
        }
        Node* curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        curr->data = value;
    }


    //------------------------------------

    int CircularLinkedListSize()
    {
        if (head == NULL)
        {
            return 0;
        }
        Node* current = head->next;
        int count = 1;
        while (current != head)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    //-------------------------------------

    bool isEmpty()
    {
        return (head == NULL);
    }
    //----------------------------
    bool isExist(T element)
    {
        if (head == NULL)
        {
            return false;
        }

        Node* current = head;
        do
        {
            if (current->data == element)
            {
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }
    //-------------------------------------
    bool isItemAtEqual(T element, int index)
    {
        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->data == element;
    }
    //------------------------------------------

    void print()
    {
        Node* current = head;

        while (current != NULL)
        {
            cout << current->data << ",";
            current = current->next;
            if (current == head)
                break;
        }
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

template<class T>
class Stack
{
    int top;
    int item[100];
public:
    Stack() :top(-1) {}
    void push(T element)
    {
        top++;
        item[top] = element;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    T pop()
    {
        if (isEmpty()) {
            return -1;
        }
        else
        {
            T first = item[top];
            top--;
            return first;
        }
    }
    T Top()
    {
        if (isEmpty()) {
            return -1;
        }
        else
        {
            return item[top];
        }
    }
    int stackSize()
    {
        return top + 1;
    }
    void clear()
    {
        top = -1;
    }
    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << item[i] << " ";
        }
        cout << endl;
    }
};

void binary(int n)
{
    Queue<string> myQ;
    myQ.enqueue("1");
    while (n--)
    {
        string a = myQ.dequeue();
        cout << a << "  ";
        string b = a;

        myQ.enqueue(a.append("0"));
        myQ.enqueue(b.append("1"));
    }
}

template <class T>
class StackQueue
{
    Queue<T> q1, q2;
public:
    void push(T value) {
        q1.enqueue(value);
    }
    T pop() {
        while (q1.queueSize() > 1)
        {
            q2.enqueue(q1.dequeue());
        }
        T result = q1.dequeue();
        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
        return result;
    }
    bool empty() {
        return q1.isEmpty();
    }
};

template<class T>
void sortQueue(Queue<T>& q) {
    int n = q.queueSize();
    Queue<T> temp, temp2;
    T smallest;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        smallest = q.first();
        while (!q.isEmpty()) {
            T x = q.dequeue();
            if (x < smallest) {
                smallest = x;
            }
            temp2.enqueue(x);
        }
        temp.enqueue(smallest);
        while (!temp2.isEmpty()) {
            T y = temp2.dequeue();
            if (y == smallest && !flag) {
                flag = true;
            }
            else {
                q.enqueue(y);
            }
        }
        flag = false;
    }
    while (!q.isEmpty()) {
        q.dequeue();
    }
    while (!temp.isEmpty()) {
        q.enqueue(temp.dequeue());
    }
}

class Maxlen
{
private:
    Stack<int>myStack;
public:


    int validLen(string expression)
    {
        myStack.push(-1);
        int len = int(expression.length());
        int ans = 0;

        for (int i = 0; i < len; i++)
        {
            if (expression[i] == '(')
            {
                myStack.push(i);
            }
            else
            {
                if (!myStack.isEmpty())
                {
                    myStack.pop();

                }
                if (!myStack.isEmpty())
                {
                    ans = max(ans, abs(i - myStack.Top()));
                }
                else
                {
                    myStack.push(i);
                }
            }
        }
        return ans;
    }

};

class postfix
{
private:
    Stack<char>myStack;
public:
    string InfixToPostfix(string infix)
    {
        int len = int(infix.length());
        string postfix = "";
        for (int i = 0; i < len; i++)
        {
            if (infix[i] == '(')
            {
                Stack<char>myStack2;
                string postfix2 = "";
                while (infix[i] != ')')
                {
                    i++;
                    if (infix[i] == '*' || infix[i] == '/')
                    {
                        if (myStack2.isEmpty())
                        {
                            myStack2.push(infix[i]);
                        }
                        else if (myStack2.Top() == '*' || myStack2.Top() == '/' || myStack2.Top() == '^')
                        {
                            while (!myStack2.isEmpty())
                            {
                                postfix += myStack2.Top();
                                myStack2.pop();
                            }
                            myStack2.push(infix[i]);
                        }
                        else
                        {
                            myStack2.push(infix[i]);
                        }
                        continue;
                    }
                    else if (infix[i] == '+' || infix[i] == '-')
                    {
                        if (myStack2.isEmpty())
                        {
                            myStack2.push(infix[i]);
                        }
                        else if (myStack2.Top() == '*' || myStack2.Top() == '/' || myStack2.Top() == '(' || myStack2.Top() == ')' || myStack2.Top() == '+' || myStack2.Top() == '-')
                        {
                            while (!myStack.isEmpty())
                            {
                                postfix += myStack2.Top();
                                myStack2.pop();
                            }
                            myStack2.push(infix[i]);
                        }
                        else
                        {
                            myStack2.push(infix[i]);
                        }
                        continue;
                    }
                    else if (infix[i] == '^')
                    {
                        if (myStack2.isEmpty())
                        {
                            myStack2.push(infix[i]);
                        }
                        else if (myStack2.Top() == '*' || myStack2.Top() == '/' || myStack2.Top() == '(' || myStack2.Top() == ')' || myStack2.Top() == '+' || myStack2.Top() == '-' || myStack2.Top() == '*' || myStack2.Top() == '/')
                        {
                            while (!myStack2.isEmpty())
                            {
                                postfix += myStack2.Top();
                                myStack2.pop();
                            }
                            myStack2.push(infix[i]);
                        }
                        else
                        {
                            myStack2.push(infix[i]);
                        }
                        continue;
                    }
                    if (infix[i] != ')')
                    {
                        postfix2 += infix[i];
                    }

                }
                while (!myStack2.isEmpty())
                {
                    postfix2 += myStack2.Top();
                    myStack2.pop();
                }
                postfix += postfix2;
                continue;
            }
            else if (infix[i] == '*' || infix[i] == '/')
            {
                if (myStack.isEmpty())
                {
                    myStack.push(infix[i]);
                }
                else if (myStack.Top() == '(' || myStack.Top() == ')' || myStack.Top() == '*' || myStack.Top() == '/' || myStack.Top() == '^')
                {
                    while (!myStack.isEmpty())
                    {
                        postfix += myStack.Top();
                        myStack.pop();
                    }
                    myStack.push(infix[i]);
                }
                else
                {
                    myStack.push(infix[i]);
                }
                continue;
            }
            else if (infix[i] == '+' || infix[i] == '-')
            {
                if (myStack.isEmpty())
                {
                    myStack.push(infix[i]);
                }
                else if (myStack.Top() == '*' || myStack.Top() == '/' || myStack.Top() == '(' || myStack.Top() == ')' || myStack.Top() == '+' || myStack.Top() == '-')
                {
                    while (!myStack.isEmpty())
                    {
                        postfix += myStack.Top();
                        myStack.pop();
                    }
                    myStack.push(infix[i]);
                }
                else
                {
                    myStack.push(infix[i]);
                }
                continue;
            }
            else if (infix[i] == '^')
            {
                if (myStack.isEmpty())
                {
                    myStack.push(infix[i]);
                }
                else if (myStack.Top() == '*' || myStack.Top() == '/' || myStack.Top() == '(' || myStack.Top() == ')' || myStack.Top() == '+' || myStack.Top() == '-' || myStack.Top() == '*' || myStack.Top() == '/')
                {
                    while (!myStack.isEmpty())
                    {
                        postfix += myStack.Top();
                        myStack.pop();
                    }
                    myStack.push(infix[i]);
                }
                else
                {
                    myStack.push(infix[i]);
                }
                continue;
            }
            postfix += infix[i];
        }
        while (!myStack.isEmpty())
        {
            postfix += myStack.Top();
            myStack.pop();
        }
        return postfix;
    }
};

void printList(Node* head)
{
    Node* curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* SortedMerge(Node* A, Node* B)
{
    Node* result = NULL;


    if (A == NULL)
        return (B);
    else if (B == NULL)
        return (A);


    if (A->data <= B->data)
    {
        result = A;
        result->next = SortedMerge(A->next, B);
    }
    else
    {
        result = B;
        result->next = SortedMerge(A, B->next);
    }

    return result;
}

Node* mergeKLists(Node* arr[], int last)
{
    while (last != 0)
    {
        int i = 0, j = last;

        while (i < j)
        {

            arr[i] = SortedMerge(arr[i], arr[j]);

            i++, j--;


            if (i >= j)
                last = j;
        }
    }

    return arr[0];
}

Node* newNode(int data)
{
    struct Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

SingleLinkedList<int> merge_nodes(SingleLinkedList<int> myList) {
    SingleListNode<int>* curr = myList.getHead()->next;
    SingleLinkedList<int> temp;
    int sum{ 0 };
    while (curr->next != NULL)
    {
        if (!curr->data) {
            temp.insertAtTail(sum);
            sum = 0;
        }
        else
        {
            sum += curr->data;
        }
        curr = curr->next;
    }
    temp.insertAtTail(sum);
    return temp;
}