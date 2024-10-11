#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class HList {
public:
	Node* head;

public:
	HList()
	{
		head = new Node;
		head->data = 0;
		head->next = NULL;
	}

	bool is_empty()
	{
		if (head->next == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Insert_Begin(int Value)
	{
		Node* temp = new Node;
		temp->data = Value;
		temp->next = NULL;

		if (is_empty())
		{
			head->next = temp;
		}
		else
		{
			temp->next = head->next;
			head->next = temp;
		}
	}

	void Insert_End(int Value)
	{
		Node* temp = new Node;
		temp->data = Value;
		temp->next = NULL;

		if (is_empty())
		{
			head->next = temp;
		}
		else
		{
			Node* t = head;
			while (t->next != NULL)
			{
				t = t->next;
			}
			t->next = temp;
		}
	}

	void Insert_After(int OldV, int NewV)
	{
		if (is_empty())
		{
			cout << "List is empty!" << endl;
		}
		Node* p = head->next;
		while (p != NULL && p->data != OldV)
		{
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "Node not found!" << endl;
		}
		Node* temp = new Node;
		temp->data = NewV;
		temp->next = p->next;
		p->next = temp;
	}

	void Delete_Node(int Value)
	{
		if (is_empty())
		{
			cout << "List is empty!" << endl;
		}

		Node* p = head->next;
		Node* q = head;

		while (p != NULL && p->data != Value)
		{
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "Node not found!" << endl;
		}
		q->next = p->next;
		delete p;
	}

	void Delete_Begin()
	{
		if (is_empty())
		{
			cout << "List is empty!" << endl;
			return;
		}
		Node* temp = head->next;
		head->next = temp->next;
		delete temp;
	}

	void Delete_End()
	{
		if (is_empty())
		{
			cout << "List is empty!" << endl;
			return;
		}

		Node* p = head->next;
		Node* q = head;

		while (p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
		delete p;
	}

	void traverse()
	{
		Node* current = head->next;
		cout << "List is: " << endl;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

int main()
{
	HList li;
	li.Insert_Begin(10);
	li.Insert_Begin(20);
	li.Insert_Begin(30);
	li.Insert_End(40);
	li.Insert_End(50);
	li.Insert_After(30, 60);
	li.traverse();
	li.Delete_Begin();
	li.traverse();
	li.Delete_End();
	li.traverse();
	li.Delete_Node(20);
	li.traverse();

	return 0;
}