#include<iostream>
using namespace std;
class Queue
{
	int* data=NULL;
	int front;
	int rear;
	int capacity;
	int count;
public:
	Queue()
	{
	}
	Queue(int capacity)
	{
		this->capacity = capacity;
		data = new int[capacity];
		front = 0;
		rear = -1;
		count = 0;
	}
	~Queue()
	{
		delete[] data;
	}
	void enqueue(int num)
	{
		 if(count == capacity)
		 {
			cout << " Queue is Full"<<endl;
			return;
		 }
		rear = (rear + 1) % capacity;
		data[rear] = num;
		count++;
	}
	int dequeue()
	{
		int value = 0;
		if (count==0)
		{
			cout << "Queue is Empty" << endl;
			return 0;
		}
		value = data[front];
		front = (front + 1) % capacity;
		return value;
	}
	void Display()
	{
		if (count==0)
			cout << "Queue is empty";
		else
		{
			cout << "Queue data is :" << endl;
			for (int i = 0; i < count; i++)
			{
				cout << " " << data[i];
			}
		}
	}
};
int main()
{
	Queue* q = new Queue(5);
	while (1)
	{
		cout << "\n----------- Queue of Number -----------" << endl;
		cout << "   1. Add" << endl;
		cout << "   2. Delete" << endl;
		cout << "   3. Display" << endl;
		cout << "-----------------------------------------" << endl;

		int choice, num;
		cout << "Enter Your Choice :- " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter Number to store" << endl;
			cin >> num;
			q->enqueue(num);
			break;
		case 2:
			num = q->dequeue();
			cout << num << " is deleted." << endl;
			break;
		case 3:
			q->Display();
			break;
		default:
			break;
		}
	}
	delete q;
	return 0;
}