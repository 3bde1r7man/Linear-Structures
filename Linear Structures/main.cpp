#include"linearStructure.h"

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


int main() {
	//-----------------------P1-------------------------
	/*int n;
	cout << "Enter the end value : ";
	cin >> n;
	cout << '\n';
	binary(n);*/
	//-----------------------P2-------------------------
	/*StackQueue<int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.pop() << '\n';
	cout << s.pop() << '\n';
	cout << s.pop() << '\n';

	cout << s.empty() << '\n';*/
	//-----------------------P3-------------------------
	Queue<int>a;
	a.enqueue(5);
	a.enqueue(4);
	a.enqueue(2);
	a.enqueue(8);
	a.enqueue(9);
	a.enqueue(3);
	a.print();
	sortQueue(a);
	a.print();
	return 0;
}
