//
// Singly linked list manipulation


#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE				
{					
	int data;
	NODE * next ;		
};



NODE* DeleteList(NODE *head)
{
	NODE *cur;

	cur = head;

	while (cur != NULL)
	{
		cur = head->next;
		delete head;
		head = cur;
	}

	return NULL;
}


NODE* InsertElement(NODE *head, int value, bool& result)
{
	NODE *cur, *previous, *tmp;

	result = false;

	tmp = new NODE;
	if (tmp == NULL)
		return head;

	tmp->data = value;
	tmp->next = NULL;

	if (head == NULL)
	{
		tmp->next = head;
		head = tmp;
		result = true;
		return head;
	}

	if (value <= head->data)
	{
		tmp->next = head;
		head = tmp;
		result = true;
		return head;
	}

	cur = head;
	previous = NULL;
	while ((cur != NULL) && (cur->data < value))
	{
		previous = cur;
		cur = cur->next;
	}

	previous->next = tmp;
	tmp->next = cur;

	result = true;

	return head;
}
				


NODE* DeleteElement(NODE *head,  int value, bool& result)
{
	NODE *cur, *previous;

	result = false;

	if (head == NULL)
		return head;
	
	if (value == head->data)
	{
		cur = head->next;
		delete head ;
		result = true;
		head = cur;
		return head;
	}

	cur = head;
	while ((cur != NULL) && (cur->data != value))
	{
		previous = cur;
		cur = cur->next;
	}
	
	if (cur == NULL)
		return head;

	previous->next = cur->next;

	delete cur;

	result = true;

	return head;
}


NODE* ModifyElement(NODE *head, int oldValue, int newValue, bool& result)
{
	NODE *cur;

	result = false;

	cur = head;

	while ((cur != NULL) && (cur->data != oldValue))
		cur = cur->next;


	if (cur == NULL)
		return head;

	cur->data = newValue;

	result = true;

	return head;
}



NODE* SearchElement(NODE *head, int value)
{
	NODE *cur;

	if (head == NULL)
		return head;

	cur = head;;
	while ((cur != NULL) && (cur->data != value))
		cur = cur->next;

	return cur;
}
				

bool IsInList(NODE *head, int value)
{
	NODE *cur;

	if (head == NULL)
		return false;

	cur = head;;
	while ((cur != NULL) && (cur->data != value))
		cur = cur->next;

	if (cur == NULL)
		return false;

	return true;
}


int GetEltNbr(NODE *head)
{
	NODE *cur;
	int nbr = 0;

	if (head == NULL)
		return 0;

	cur = head;
	while (cur != NULL) 
	{
		nbr++;
		cur = cur->next;
	}

	return nbr;
}

int GetEltNbrRec(NODE *head)
{
	if(!head) return 0;
	return 1+ GetEltNbrRec(head->next);

}


void PrintList(NODE *head)
{
	NODE *cur;

	if (head == NULL)
	{
		cout << "The list is empty" << endl;
		return;
	}

	cur = head;
	while (cur != NULL) 
	{
		cout << cur->data << "\t";
		cur = cur->next;
	}
	
	cout << endl;

}
void reverseList(NODE*& head)
{
	NODE *cur, *previous, *next;

	if (head == NULL)
		return;

	cur = head;
	previous = NULL;
	while (cur != NULL) 
	{
		next = cur->next;
		cur->next = previous;
		previous = cur;
		cur = next;
	}

	head = previous;
}
NODE* mergeSortedLists(NODE *l1, NODE *l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	if (l1->data < l2->data){
		l1->next=mergeSortedLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeSortedLists(l1,l2->next);
		return l2;
	}
	
}
int main(int argc, char* argv[])
{
	NODE *head1 = NULL;
	NODE *head2 = NULL;
	int choice = 1;
	NODE *head;
	NODE *tmp;
	int val, val1;
	bool result;

	cout << "A list of integers has been created (it will be sorted by increasing order) " << endl;
	
	while (choice != 0)
	{
		cout << endl
			 << "     ======================" << endl
		     << "     1: InsertElement to list 1 : " << endl
			 << "     2: Insert Element to list 2 : " << endl
			 << "     3: Reverse List 1 : " << endl
			 << "     4: Reverse List 2 : " << endl
			 << "     5: Merge lists : " << endl
			 << "     6: Remove Dupes from sorted List: " << endl
			 << "     7: Print list 1: " << endl
			 << "     8: Print list 2: " << endl
			 << "     ======================" << endl
			 << "     0: Quit" << endl
			 << "     ======================" << endl
			 << endl
			 << "Your Choice : ";
		
		cin >> choice;
		cout << endl;

		switch(choice)
		{
		case 1 :
			cout << "Type the element's value : ";
			cin >> val;
			head = InsertElement(head1, val, result);
			if (result == false)
			{
				cout << "Insertion failed " << val << endl;
				head = DeleteList(head);
				exit(0);
			}
			else
				cout << "The value "<< val << " has been added" << endl;
			break;
		
		case 2 :
			cout << "Type the element's value : ";
			cin >> val;
			head = InsertElement(head2, val, result);
			if (result == false)
			{
				cout << "Insertion failed " << val << endl;
				head = DeleteList(head);
				exit(0);
			}
			else
				cout << "The value "<< val << " has been added" << endl;
			break;
			
		
		case 3 :
			reverseList(head1);
			break;

		case 4 :
			reverseList(head2);
			break;

		case 5 :
			mergeSortedLists(head1,head2);
			break;
		case 6:
			break;
		case 7:
			PrintList(head1);
			break;
		case 8:
			PrintList(head2);
		case 0 :
			break;
		}
	}
	head = DeleteList(head);
	cout << "The list has been deleted " << endl;

	return 0;
}

