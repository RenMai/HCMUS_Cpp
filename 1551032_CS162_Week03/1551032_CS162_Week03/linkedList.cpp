#include "linkedList.h"


void linkedList::inputFromFile()
{
	ifstream file;
	file.open("input.txt");

	
	int temp;
	Node*cur;
	cur=new Node;

	if(file.fail())
		cout<<" Unable to open the file"<<endl;
	else
	{	

		while(file>>temp)
		{
			if(file.eof())
				break;
		
			if(head==NULL)
			{				
				cur->data=temp;
				cur->next=NULL;
				head=cur;
				
			}
			else
			{
				cur->next=new Node;
				cur=cur->next;
				cur->data=temp;
				cur->next=NULL;
			}
		}
	}

	
	
	file.close();
}

void linkedList::Display()
{
	Node*cur=head;
	while(cur!=NULL)
	{
		cout<<cur->data<<" ";
		cur=cur->next;
	}

	delete cur;

}

void linkedList::InsertOddNumber()
{
	
	Node*prev=head;
	Node*cur=prev->next;
	Node*temp;
	int i=1;
	while(cur!=NULL)
	{
		if(prev==head)
		{
			temp=new Node;
			temp->data=2*i;
			temp->next=head;
			head=temp;
			prev=head->next;
			cur=prev->next;
			i++;
		}
		else
		{
			temp=new Node;
			temp->data=2*i;
			temp->next=cur;
			prev->next=temp;
			prev=temp;
			prev=cur;
			cur=cur->next;
			i++;
		}
	}
}

void linkedList::JoinList(Node*&head1)
{
	Node*cur1=head1;
	if(cur1==NULL)
	{
		cur1=new Node;
		cur1->data=1;
		cur1->next=NULL;
		head1=cur1;
	}
	
		int i=2;
		while(cur1!=NULL && i<=4)
		{
			cur1->next=new Node;
			cur1=cur1->next;
			cur1->data=i;
			cur1->next=NULL;
			i++;
		}
	
	Node*cur=head;
	while(cur!=NULL && cur->data!=3)
	{
		cur=cur->next;
	}

	cur1->next=cur;

	Node*cur3=head1;

	while(cur3!=NULL)
	{
		cout<<cur3->data<<" ";
		cur3=cur3->next;
	}


}
void linkedList::checkCommonNode(Node*head1)
{
	Node*cur=head;
	Node*cur1=head1;

	bool check=false;
	int count=1;
	Node*temp;

	while(cur!=NULL)
	{
		while(cur1!=NULL)
		{
			if(cur1==cur)
			{
				check=true;
				temp=cur;
				break;				
			}
			else
			{
				cur1=cur1->next;
			}
		}

		if(check==true)
		{
			Node*cur3=head;
			while(cur3!=NULL && cur3!=temp)
			{
				cur3=cur3->next;
				count++;
			}
			cout<<" Common node number "<<count<<endl;

			ofstream file("joined.txt");

			if(file.fail())
				cout<<" Unable to find the file "<<endl;
			else
			{
				file<<count;
				return;
			}
			file.close();
			return;
		}
		else
		{
			cur=cur->next;
			cur1=head1;
		}
	}

	cout<<" No common node "<<endl;


}
void linkedList::printToFile(string filename)
{
	Node*cur=head;
	int temp;

	ofstream file(filename);
	
	if(file.fail())
		cout<<" Unable to open the file "<<endl;
	else
	{
		while(cur!=NULL)
		{			
			temp=cur->data;
			
			file<<temp<<" ";
			cur=cur->next;
		}
	}
	file.close();

}

void linkedList::createLoop(Node*&head1)
{
	Node*cur=NULL;

	if(cur==NULL)
	{
		head1=new Node;
		head1->data=1;
		head1->next=NULL;
		cur=head1;
	}

	int i=2;
	while(cur!=NULL && i<=5)
	{
		cur->next=new Node;
		cur=cur->next;
		cur->data=i;
		cur->next=NULL;
		i++;
	}

	Node*cur2=head1;

	while(cur2!=NULL && i<3)
	{
		cur2=cur2->next;
	}

	cur->next=cur2;

	Node*cur3=head1;

	
}

void linkedList::checkLoop(Node*head1)
{
	Node*fast=head1;
	Node*slow=head1;
	bool check=false;
	
	cout<<" Checking if the list contains a loop "<<endl;

	while(fast!=NULL && fast->next!=NULL && slow!=NULL)
	{

		if(slow==fast->next || slow==fast->next->next)
		{
			check=true;
			
			if(slow==fast->next)
			{
				fast=fast->next;
			}
			else
				fast=fast->next->next;
			Node*slow=head1;

			break;
			
		}

		slow=slow->next;
		fast=fast->next->next;
	}

	ofstream file("loop.txt");
	if(file.fail())
		cout<<" Unable to open the file "<<endl;

	


	if(check==true)
	{
			cout<<" Yes " <<endl;
			string answer="yes";
			file<<answer;
	}
	else
	{
			cout<<" No "<<endl;
			string answer="no";
			file<<answer;
	}

	Node*temp;
	while(slow!=NULL && fast!=NULL)
	{
		if(slow==fast)
		{
			temp=slow;
			break;
		}
	}

	Node*cur2=head1;
	int count=0;

	while(cur2!=NULL)
	{
		if(cur2==temp)
		{
			cout<<" Loop at the node "<<count<<endl;
			break;
		}
		count++;
		cur2=cur2->next;
	}
	file.close();
}

