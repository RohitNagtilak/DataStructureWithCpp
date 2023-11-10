#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node() :data(0), next(NULL) {}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node* createNode()
{
	int data;
	cout << "\nEnter data to store:";
	cin >> data;

	Node* node = new Node(data);

	return node;
}

Node* InsertAtStart(Node* head)
{
	Node* node = createNode();
	if (head == NULL)
		head = node;
	else
	{
		node->next = head;
		head = node;
	}
	return head;
}

Node* InsertAtEnd(Node* head)
{
	Node* node = createNode();
	if (head == NULL)
		head = node;
	else
	{
		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}

	return head;
}


Node* InsertAtMiddle(Node* head)
{
	if (head == NULL)
	{
		cout << "List is empty. Cannot insert at middle." << endl;
		return head;
	}

	int key;
	cout << "Enter key after which you want to add data: ";
	cin >> key;

	Node* node = createNode();
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			node->next = temp->next;
			temp->next = node;
			cout << "Node inserted successfully." << endl;
			break;
		}
		temp = temp->next;
	}

	if (temp == NULL)
		cout << "Node with " << key << " data not found." << endl;

	return head;
}


Node* DeleteFromStart(Node* head)
{
	if (head == NULL)
	{
		cout << "LinkedList is empty" << endl;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	return head;
}

Node* DeleteFromEnd(Node* head)
{
	if (head == NULL)
	{
		cout << "\nList is empty..!" << endl;
		return head;
	}
	else if (head->next == NULL)
	{
		delete head;
		head = NULL;
		return head;
	}
	else
	{
		Node* temp = head;
		while (temp->next->next != NULL)
			temp = temp->next;

		delete temp->next;
		temp->next = NULL;
		return head;
	}
}

Node* DeleteFromMiddle(Node* head)
{
	if (head == NULL)
	{
		cout << "\nList is empty..!\n";
		return head;
	}

	int key;
	cout << "\nEnter data which you want to delete : ";
	cin >> key;

	if (head->data == key)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}

	Node* temp = head;
	while (temp->next != NULL)
	{
		if (temp->next->data == key)
		{
			Node* t = temp->next;
			temp->next = temp->next->next;
			delete t;
			return head;
		}
		temp = temp->next;
	}

	cout << key << " not found..!\n";
	return head;
}


void Display(Node* head)
{
	if (head == NULL)
		cout << "\n List is empty...!";
	else
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << " " << temp->data << " ->";
			temp = temp->next;
		}
	}
}

//      10 -> 20  ->  30  ->  40  ->  50  ->NULL
//NULL  |     |
// |    |     |
//prev curr  nextPtr

Node* Reverse(Node*& head)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* nextPtr;
	while (curr != NULL)
	{
		nextPtr = curr->next;
		curr->next = prev;

		prev = curr;
		curr = nextPtr;
	}
	return prev;
}


Node* ReverseRecursive(Node*& head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* newHead = ReverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;

	return newHead;
}

int main()
{
	Node* head = NULL;
	while (1)
	{
		cout << "\n 1.  Create List\n 2.  Insert At Start\n 3.  Insert At End\n 4.  Insert At Middle\n 5.  Delete from start \n 6.  Delete from end \n 7.  Delete from middle \n 8.  Display \n 9.  Reverse \n 10. ReverseRecursive \n";
		int ch;
		cout << "\nEnter your choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			head = createNode();
			break;
		case 2:
			head = InsertAtStart(head);
			break;
		case 3:
			head = InsertAtEnd(head);
			break;
		case 4:
			head = InsertAtMiddle(head);
			break;
		case 5:
			head = DeleteFromStart(head);
			break;
		case 6:
			head = DeleteFromEnd(head);
			break;
		case 7:
			head = DeleteFromMiddle(head);
			break;
		case 8:
			Display(head);
			break;
		case 9:
			head = Reverse(head);
			break;
		case 10:
			head = ReverseRecursive(head);
			break;
		default:
			break;
		}
	}
	return 0;
}