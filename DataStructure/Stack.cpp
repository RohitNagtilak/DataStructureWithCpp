#include<iostream>
using namespace std;
class Stack
{
	int top;
    int* data;
    int capacity;
public:
    Stack(){}
    Stack(int capacity)
    {
        this->capacity = capacity;
        data = new int[capacity];
        top = -1;
    }
    ~Stack()
    {
        delete[] data;
    }
    void push(int num);
	int Pop();
    void Display();
    bool isEmpty();
    bool isFull();
};

void Stack::push(int num)
{
    if (isFull())
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        data[++top] = num;
    }
}

int Stack::Pop()
{
    int val=0;
    if (isEmpty())
    {
        cout << "Stack is Empty." << endl;
    }
    else
    {
        val = data[top];
        data[top] = NULL;
        top--;
    }
    return val;
}

void Stack::Display()
{
    if (isEmpty())
        cout << "--Stack is empty--" << endl;
    else
    {
        int* ptr = data;
        cout << "Data is :-"<<endl;
        for (int i = 0; i <= top; i++)
        {
            cout << " " << *ptr<<"\t";
            ptr++;
        }
    }
}

bool Stack::isEmpty()
{
   return top == -1;
}

bool Stack::isFull()
{
   return top == capacity - 1;
}

int main()
{
    Stack *s = new Stack(10);
    while (1)
    {
        cout << "\n----------- Stack of Number -----------" << endl;
        cout << "   1. Push" << endl;
        cout << "   2. Pop" << endl;
        cout << "   3. Display" << endl;
        cout << "-----------------------------------------" << endl;

        int choice,num;
        cout << "Enter Your Choice :- " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Number to store" << endl;
            cin >> num;
            s->push(num);
            break;
        case 2:
            num=s->Pop();
            cout << num << " is poped." << endl;
            break;
        case 3:
            s->Display();
            break;
        default:
            break;
        }
    }
    delete s;
	return 0;
}