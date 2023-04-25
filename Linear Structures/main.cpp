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

int main() {
	int n;
	cout << "Enter the end value : ";
	cin >> n;
	cout << '\n';
	binary(n);

}
