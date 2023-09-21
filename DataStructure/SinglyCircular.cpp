#include<iostream>
using namespace std;
class Node
{
public:
	
	Node():data(0),next(NULL){}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}

	int data;
	Node* next;
};

Node* createNode()
{
	int data;
	cout << "Enter data to store:" << endl;
	cin >> data;
	Node* node = new Node(data);
	return node;
}

Node* InsertAtStart(Node* head)
{
	Node* node = createNode();
	if (head == NULL)
	{
		head = node;
		head->next = node;
	}
	else
	{
		Node* temp = head;
		while (temp->next != head)
			temp = temp->next;

		temp->next = node;
		node->next = head;
		head = node;
	}
	return head;
}

Node* InsertAtEnd(Node* head)
{
	Node* node = createNode();
	if (head == NULL)
	{
		head = node;
		head->next = node;
	}
	else
	{
		Node* temp = head;
		while (temp->next != head)
			temp = temp->next;
		temp->next = node;
		node->next = head;
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
	bool keyFound = false;

	do
	{
		if (temp->data == key)
		{
			node->next = temp->next;
			temp->next = node;
			cout << "Node inserted successfully." << endl;
			keyFound = true;
			break;
		}
		temp = temp->next;
	} while (temp != head);

	if (!keyFound)
		cout << "Node with " << key << " data not found." << endl;

	return head;
}

Node* DeleteFromStart(Node* head)
{
	if (head == NULL)
	{
		cout << "\n List is empty...!";
		return NULL;
	}
	else
	{
		Node* temp = head;
		while (temp->next != head)
			temp = temp->next;
		temp->next = head->next;

		if (head->next == head)
		{
			delete head;
			return NULL; 
		}
		else
		{
			Node * newHead = head->next;
			delete head;
			return newHead;
		}
	}
}

Node* DeleteFromEnd(Node* head)
{
	if (head == NULL)
	{
		cout << "\n List is empty...!";
		return NULL;
	}
	else if (head->next == head)
	{
		delete head;
		return NULL;
	}
	else
	{
		Node* temp = head;
		while (temp->next->next != head)
			temp = temp->next;

		Node* toDelete = temp->next;
		temp->next = head;

		delete toDelete;
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
		if (head->next == head) 
		{
			delete head;
			return NULL;
		}

		Node* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}

		Node* temp2 = head;
		head = head->next;
		temp->next = head;
		delete temp2;
		return head;
	}

	Node* temp = head;
	while (temp->next != head)
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
		do
		{
			cout << " " << temp->data<<" ->";
			temp = temp->next;
		} while (temp != head);
	}
}

int main()
{
	Node* head = NULL;
	while (1)
	{
		cout << "\n 1. Insert At Start\n 2. Insert At End\n 3. Insert At Middle\n 4. Delete from start \n 5. Delete from end \n 6. Delete from middle \n 7. Display";
		int ch;
		cout << "\nEnter your choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			head = InsertAtStart(head);
			break;
		case 2:
			head = InsertAtEnd(head);
			break;
		case 3:
			head = InsertAtMiddle(head);
			break;
		case 4:
			head = DeleteFromStart(head);
			break;
		case 5:
			head = DeleteFromEnd(head);
			break;
		case 6:
			head = DeleteFromMiddle(head);
			break;
		case 7:
			 Display(head);
			 break;
		}
	}
	return 0;
}