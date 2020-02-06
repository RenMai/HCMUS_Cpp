#include "linkedList.h"

void linkedList::Insert2LinkList()
{
	Node*cur1 = head1;
	Node*cur2 = head2;
	int num;

	cout << " List 1 " << endl;
	while (1)
	{
		cout << " List 1 element ( terminate by -1) : ";
		cin >> num;
		if (num == -1)
			break;
		if (cur1 == NULL)
		{
			head1 = new Node;
			cur1 = head1;
		}
		else
		{
			cur1->next = new Node;
			cur1 = cur1->next;
		}

		cur1->data = num;
		cur1->next = NULL;
	}
	cout << " List 2 " << endl;
	while (1)
	{
		cout << " List 2 element ( terminate by -1) : ";
		cin >> num;
		if (num == -1)
			break;
		if (cur2 == NULL)
		{
			head2 = new Node;
			cur2 = head2;
		}
		else
		{
			cur2->next = new Node;
			cur2 = cur2->next;
		}

		cur2->data = num;
		cur2->next = NULL;
	}
	
}

void linkedList::sortInsert()
{
	Node*prev = head1;
	Node*cur = prev->next;
	cout << " Performing on list 1 " << endl;

	if (prev == NULL)
	{
		return;
	}

	int info = 0;
	Node*temp = NULL;
	
		cout << " Input data : ";
		cin >> info;	
		
		while (prev != NULL)
		{
			if (prev->next == NULL)
			{
				if (info > prev->data)
					return;
				else
				{
					temp = new Node;
					temp->data = info;
					temp->next = prev;
					head1 = temp;
					return;
				}
			}
			else
			{
				if (cur->next == NULL)
				{
					if (info > cur->data)
					{
						temp = new Node;
						temp->data = info;
						temp->next = NULL;
						cur->next = temp;
						return;
					}
					else
						return;
				}
				else
				{
					if (prev->data < info && cur->data > info)
					{
						temp = new Node;
						temp->data = info;
						temp->next = cur;
						prev->next = temp;
						return;
					}
				}

				if (prev == head1 && info < prev->data)
				{
					temp = new Node;
					temp->data = info;
					temp->next = prev;
					head1 = temp;
					return;
				}
			}
			prev = cur;
			cur = cur->next;
		}
}

void linkedList::Display2List()
{
	Node*cur1 = head1;
	

	cout << " List 1 : ";
	while (cur1 != NULL)
	{
		cout << cur1->data << " ";
		cur1 = cur1->next;
	}
	cout << endl;
	cur1 = head2;
	cout << " List 2 : ";
	while (cur1 != NULL)
	{
		cout << cur1->data << " ";
		cur1 = cur1->next;
	}

	delete cur1;
}

void linkedList::sumUptoI()
{
	Node*newhead = NULL;
	
	cout << " Performing on list 1 " << endl;
	Node*cur = head1;

	int sum = 0;
	Node*newcur = newhead;

	while (cur != NULL)
	{
		if (newcur == NULL)
		{
			newcur = new Node;	
			newhead = newcur;
		}
		else
		{
			newcur->next = new Node;
			newcur = newcur->next;
		}

		sum += cur->data;
		newcur->data = sum;
		newcur->next = NULL;	

		cur = cur->next;
	}

	Node*dis1 = head1;
	Node*dis2 = newhead;
	cout << " THe first list :";
	while (dis1 != NULL)
	{
		cout << dis1->data << " ";
		dis1 = dis1->next;
	}
	cout << endl;

	cout << " The Sum to i list :";

	while (dis2 != NULL)
	{
		cout << dis2->data << " ";
		dis2 = dis2->next;
	}
	cout << endl;

}

void linkedList::SeparateList(Node*&fhead, Node*&shead)
{
	fhead = head1;
	shead=head1->next;
	int count = 0;
	Node*cur1 = fhead;
	Node*cur2 = shead;
	
	head1 = head1->next->next;
	Node*cur = head1;

	while (cur!=NULL)
	{
		if (count % 2 == 0)
		{
			
				cur1->next = cur;
				cur1 = cur1->next;
			
		}
		else
		{
			
				cur2->next = cur;
				cur2 = cur2->next;
			
		}
		cur = cur->next;
		count++;
	}
	cur1->next = cur2->next = NULL;
	
	Node*dis1 = fhead;
	Node*dis2 = shead;

	cout << " First list : ";
	while (dis1 != NULL)
	{
		cout << dis1->data << " ";
		dis1=dis1->next;
	}
	cout << endl;
	cout << " Second list : ";
	while (dis2 != NULL)
	{
		cout << dis2->data << " ";
		dis2 = dis2->next;
	}
}

void linkedList::CombineList(Node*fhead, Node*shead,Node*&head1)
{
	

	Node*fhcur = fhead;
	Node*shcur = shead;
	Node*fnext, *snext;

	while (fhcur != NULL && shcur != NULL)
	{
		fnext = fhcur->next;
		snext = shcur->next;

		shcur->next = fnext;
		fhcur->next = shcur; 

		fhcur = fnext;
		shcur = snext;
	}

	shead = shcur;	
	
	cout << " New list : ";

	Node*dis = fhead;
	while (dis != NULL)
	{
		cout << dis->data << " ";
		dis = dis->next;
	}
	cout << endl;


}

void linkedList::computeToInteger(Node*&head, int &result)
{
	Node*temp = head;
	int num;
	int count = 1;

	while (1)
	{
		cout << " Insert number : ";
		cin >> num;
		if (num == -1)
			break;

		if (temp == NULL)
		{
			head = new Node;
			head->data = num;
			head->next = NULL;
			temp = head; 
			count = 1;
			
		}
		else
		{
			temp->next = new Node;
			temp = temp->next;
			temp->data = num;
			temp->next = NULL;
			count *= 10;			
		}			
	}
	
	
	result = 0;

	Node*cur = head;
	while (cur != NULL)
	{
		result += cur->data*count;
		count = count / 10;
		cur = cur->next;
	}
	cout << " Result : " << result << endl;
}

void linkedList::integerRepresent(int result, Node*&head)
{
	int newResult = 0;

	cout << " Input an integer : ";
	cin >> result;

	while (result != 0)
	{
		int remainder = result % 10;
		newResult = newResult * 10 + remainder;
		result /= 10;		
	}
	cout << newResult << endl;
	Node*temp = head;
	while (newResult!=0)
	{
		if (head == NULL)
		{
			head = new Node;
			head->data = newResult % 10;
			head->next = NULL;
			temp = head;
		}
		else
		{
			temp->next = new Node;
			temp = temp->next;
			temp->data = newResult % 10;
			temp->next = NULL;
		}
		newResult /= 10;
	}

	Node*dis = head;
	cout << " The List reprenting the integer :" << endl;
	while (dis != NULL)
	{
		cout << dis->data << " ";
		dis = dis->next;
	}

}