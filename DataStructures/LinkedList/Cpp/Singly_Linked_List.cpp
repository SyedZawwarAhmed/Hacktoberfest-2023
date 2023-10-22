#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		node()
		{
			data=0;
			next=NULL;
		}
		node(int x)
		{
			data=x;
			next=NULL;
		}
};
class SLL
{
	node *head;
	public:
		SLL()
		{
			head=NULL;
		}
	void create();
	void display();
	int count();
	int search(int x);
	void addatbegin(int x);
	void addatend(int x);
	void addatpos(int pos,int x);
	void deleteatbeg();
	void deleteatend();
	void deleteatpos(int pos);
	void delsll();
	void new_create();
	void new_create_atoi();
	void show_rec(node *p);
	void show_rec_rev(node *p);	
	void printdata()
	{
		show_rec(head);
		cout<<"\nIn reverse order:";
		show_rec_rev(head);
	}
	/*int search_main(node *p,int x); this is another way to define function
	int search_1(int x)
	{
		search_main(head,x);
	}
	int count_main(node *p);
	int count_1()
	{
		int c;
		c=count_main(head);
	}*/
	int search_main(node *p,int x);
	int search_1(int x);
	int count_main(node *p);
	int count_1();
};
int main()
{
	int count;
	SLL obj;
	/*
	cout<<"\nEnter data to add at begin:";
	cin>>x;
	obj.addatbegin(x);
	cout<<"\nEnter data to add at end:";
	cin>>x;
	obj.addatend(x);
	obj.create();
	obj.display();
	count=obj.count();
	cout<<"\nnumber of count is:"<<count;
	cout<<"\nEnter data to search:";
	cin>>x;
	int result,pos;
	result=obj.search(x);
	if(result==1)
	{
		cout<<"\nData is found..";
	}
	else
	{
		cout<<"\nData is not found..";
	}
	cout<<"\nEnter data to add at begin:";
	cin>>x;
	obj.addatbegin(x);
	obj.display();
	cout<<"\nEnter data to add at end:";
	cin>>x;
	obj.addatend(x);
	obj.display();
	cout<<"\nEnter position to add node:";
	cin>>pos;
	cout<<"\nEnter data to add in node:";
	cin>>x;
	obj.addatpos(pos,x);
	obj.display();
	obj.deleteatbeg();
	cout<<"\nAfter deletion of 1st node:";
	obj.display();
	obj.deleteatend();
	cout<<"\nAfter deletion of last node:";
	obj.display();
	cout<<"\nEnter position to delete node:";
	cin>>pos;
	obj.deleteatpos(pos);
	obj.display();
	obj.delsll();
	cout<<"\nDeleting all nodes..";
	obj.display();
	count=obj.count();
	cout<<"\nCount is:"<<count;
	*/
	/*obj.new_create();
	obj.display();
	cout<<"\nDeleted all element...:";
	obj.delsll();
	count=obj.count();
	cout<<"\nCount is:"<<count;
	obj.new_create();
	obj.display();
	cout<<"\nDeleted all element...:";
	obj.delsll();
	obj.new_create_atoi();
	obj.display();
	count=obj.count();
	cout<<"\ncount is:"<<count;
	*/
	obj.create();
	obj.printdata();
	int x,res,cnt;
	cout<<"\nEnter data to find x:";
	cin>>x;
	res=obj.search_1(x);
	if(res==0)
	{
		cout<<"\nData not found...";
	}
	else
	{
		cout<<"\nData is found..";
	}
	cnt=obj.count_1();
	cout<<"\nCount is:"<<cnt;

}

void SLL :: create()
{
	int n,i,x;
	node *p;
	cout<<"\nHow many node you want to create:";
	cin>>n;
	if(n==0)
	{
		return;
	}
	if(head==NULL)
	{
		cout<<"\nEnter data for 1st node:";
		cin>>x;
		head=new node(x);
		p=head;
		for(i=1;i<=n-1;i++)
		{
			cout<<"\nEnter data for next node:";
			cin>>x;
			p->next=new node(x);
			p=p->next;
		}
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		for(i=1;i<=n;i++)
		{
			cout<<"\nEnter data for next node:";
			cin>>x;
			p->next=new node(x);
			p=p->next;
		}
	}
}
void SLL :: display()
{
	node *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}
int SLL ::count()
{
	int c=0;
	node *p=head;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}
int SLL :: search(int x)
{
	node *p=head;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			return 1;
		}
		p=p->next;
	}
	return 0;
}
void SLL :: addatbegin(int x)
{
	node *p;
	p=new node(x);
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		p->next=head;
		head=p;
	}
}
void SLL :: addatend(int x)
{
	node *p;
	p=new node(x);
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		node *q;
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;	
		}
		q->next=p;
	}
}
void SLL :: addatpos(int pos,int x)
{
	int c,i;
	c=count();
	if(pos<1||pos>c+1)
	{
		cout<<"\nPosition is invalid";
		return;
	}
	else
	{
		if(pos==1)
		{
			addatbegin(x);
		}
		else
		{
			node *q,*p=head;
			q=new node(x);
			for(i=1;i<pos-1;i++)
			{
				p=p->next;
			}
			q->next=p->next;
			p->next=q;
		}
	}
}
void SLL :: deleteatbeg()
{
	if(head==NULL)
	{
		cout<<"\nEmpty list..";
		return;
	}
	if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	else
	{
		node *p=head;
		head=head->next;
		delete p;
	}
}
void SLL :: deleteatend()
{
	if(head==NULL)
	{
		cout<<"\nList is empty";
		return;
	}
	if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	else
	{
		node *p,*q;
		p=head,q=NULL;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		delete p;
	}
}
void SLL :: deleteatpos(int pos)
{
	int c;
	c=count();
	if(pos<1||pos>c)
	{
		cout<<"\nInvalid pos";
		return;
	}
	if(pos==1)
	{
		deleteatbeg();
	}
	else
	{
		node *p=head,*q=NULL;
		for(int i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		delete q;
	}
}
void SLL :: delsll()
{
	node *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
}
void SLL :: new_create()
{
	int x;
	cout<<"\nKeep entering data...";
	cout<<"\nEnter -1 when you want to stop\n";
	while(1)
	{
		cout<<"\nEnter Data:";
		cin>>x;
		if(x==-1)
		{
			break;
		}
		addatend(x);
	}
}
void SLL :: new_create_atoi()
{
	int x,res;
	char str1[20];
	cout<<"\nKeep entering data...";
	cout<<"\nEnter STOP when you want to stop\n";
	cin.ignore(1);
	while(1)
	{
		cin.getline(str1,19);
		res=strcmp(str1,"STOP");
		if(res==0)
		{
			break;
		}
		x=atoi(str1);
		addatend(x);
	}
}
void SLL :: show_rec(node *p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		cout<<p->data<<" ";
		show_rec(p->next);
	}
}
void SLL :: show_rec_rev(node *p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		show_rec_rev(p->next);
		cout<<"\np->data:"<<p->data;
	}
}
int SLL :: search_1(int x)
{
	int res;
	res=search_main(head,x);
	return res;
}

int SLL :: search_main(node *p,int x)
{
	if(p==NULL)
	{
		return 0;
	}
	else if(p->data==x)
	{
		return 1;
	}
	else
	{
		int y;
		y=search_main(p->next,x);
		return y;
	}
}
int SLL :: count_1()
{
	int c;
	c=count_main(head);
	return c;
}
int SLL :: count_main(node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		int c;
		c=count_main(p->next);
		return c+1;
	}
}