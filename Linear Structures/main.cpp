#include"linearStructure.h"


int main() {
	//-----------------------QueueP1-------------------------
    cout << "-----------------------QueueP1-------------------------\n";
    int n{ 10 };
    
	cout << "for n equal 10 the binary from 1 to 10 is:\n";
	binary(n);

	//-----------------------QueueP2-------------------------
    cout << "\n-----------------------QueueP2-------------------------\n";
	StackQueue<int> s;
    cout << "item push \n";
    s.push(1);

    cout << "item push \n";
    s.push(2);

    cout << "item push \n";
    s.push(3);

	cout << "item pop " << s.pop() << '\n';
    cout << "item pop " << s.pop() << '\n';
    cout << "item pop " << s.pop() << '\n';

	cout << "check if stack is empty: " << s.empty() << '\n';

	//-----------------------QueueP3-------------------------
    cout << "\n-----------------------QueueP3-------------------------\n";
	Queue<int>q;
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(2);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(3);
    cout << "the queue before sort is: \n";
	q.print();
	sortQueue(q);
    cout << "the queue after sort is: \n";
	q.print();
    //-----------------------StackP1-------------------------
    cout << "\n-----------------------StackP1-------------------------\n";
    {
        string exp = ")()())";
        Maxlen a;
        cout << a.validLen(exp);
    }
    //-----------------------StackP2-------------------------
    cout << "\n-----------------------StackP2-------------------------\n";
    postfix a;
    cout << a.InfixToPostfix("(A+B)*(C+D)");

    //-----------------------LinkedListP1-------------------------
    cout << "\n-----------------------linkedlistP1--------------------\n";
    SingleLinkedList<int> myList;
    myList.insertAtTail(0);
    myList.insertAtTail(3);
    myList.insertAtTail(1);
    myList.insertAtTail(0);
    myList.insertAtTail(4);
    myList.insertAtTail(5);
    myList.insertAtTail(2);
    myList.insertAtTail(0);
    cout << "linked list : ";
    myList.print();

    SingleLinkedList<int> temp =  merge_nodes(myList);
    temp.print();
    //-----------------------LinkedListP2-------------------------
    cout << "\n-----------------------linkedlistP2--------------------\n";
    const int K = 3;
    Node* arr[K];

    arr[0] = newNode(1);
    arr[0]->next = newNode(4);
    arr[0]->next->next = newNode(5);

    arr[1] = newNode(1);
    arr[1]->next = newNode(3);
    arr[1]->next->next = newNode(4);

    arr[2] = newNode(2);
    arr[2]->next = newNode(6);

    Node* head = mergeKLists(arr, K - 1);
    printList(head);
	
}
