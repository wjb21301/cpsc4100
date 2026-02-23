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


NODE* CreateList(NODE *head)
{
	return NULL;
}

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
void reverseList(NODE *head)
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
	
}
void removeDuplicates(NODE *head)
{

}



int main(int argc, char* argv[])
{
	int choice = 1;
	NODE *head;
	NODE *tmp;
	int val, val1;
	bool result;
	
	head = CreateList(head);

	cout << "A list of integers has been created (it will be sorted by increasing order) " << endl;
	
	while (choice != 0)
	{
		cout << endl
			 << "     ======================" << endl
		     << "     1: InsertElement() : " << endl
			 << "     2: DeleteElement() : " << endl
			 << "     3: SearchElement() : " << endl
			 << "     4: IsInList()      : " << endl
			 << "     5: ModifyElement() : " << endl
			 << "     6: PrintList()     : " << endl
			 << "     7: GetEltNbr()     : " << endl
			 << "     8: DeleteList()    : " <<endl
			 << "     9: GetEltNbrRec()  : " << endl
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
			head = InsertElement(head, val, result);
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
			cout << "Type the value to delete : ";
			cin >> val;
			head = DeleteElement(head, val, result);
			if (result == false)
				cout << "Deletion failed : " << val << endl;
			else
				cout << "The value "<< val << " has been deleted" << endl;
			break;
		
		case 3 :
			cout << "Type the value to search : ";
			cin >> val;
			tmp = SearchElement(head, val);
			if (tmp == NULL)
				cout << val << "is not in the list" << endl;
			else
				cout << "The value "<< val << "is in the list with address : " << tmp << endl;
			break;

		case 4 :
			cout << "type the value to search : ";
			cin >> val;
			if (IsInList(head, val))
				cout << val << " is in the list" << endl;
			else
				cout << val << " is not in the list " << endl;
			break;

		case 5 :
			cout << "Type the old value : ";
			cin >> val;
			cout <<endl << "Type the new value : ";
			cin >> val1;
			head = ModifyElement(head, val, val1, result);
			if (result == false)
				cout << "Modification failed " << val << " en "<< val1 <<endl;
			else
				cout << "The value "<< val << " has been modified " << val1 <<endl;

			break;

		case 6 :
			PrintList(head);
			break;

		case 7 :
			cout << "The list contains " << GetEltNbr(head) << " elements."<< endl;
			break;
		case 8 :
			  head= DeleteList(head); 
			  cout<<"The list has been deleted " << endl;
			break;
		case 9 :
			cout << "The list contains " << GetEltNbrRec(head) << " elements."<< endl;
			break;
		case 0 :
			break;
		}
	}


	head = DeleteList(head);
	cout << "The list has been deleted " << endl;

	return 0;
}

