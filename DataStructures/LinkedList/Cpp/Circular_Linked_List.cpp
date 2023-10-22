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
class CLL 
{
	node *front;
	node *rear;
	public:
		CLL()
		{
			front=NULL;
			rear=NULL;
		}
		void create();
		void show();
		int count();
		int search(int x);
		void addatbeg(int x);
		void addatend(int x);
		void addbypos(int pos,int x);
		void delatbeg();
		void delatend();
		void delbypos(int pos);
		int count_rec(node *p);
		int count_main();
		int search_main(int x);
		int search_rec(node *p,int x);
		void create_main();
	
};
int main()
{
	CLL obj;
/*	obj.create();
	obj.show();
	int c,res,pos;
	c=obj.count();
	cout<<"\nCount is:"<<c;
	cout<<"\nEnter data you want to search:";
	cin>>c;
	res=obj.search(c);
	if(res==1)
	{
		cout<<"\nData is found..";
	}
	else
	{
		cout<<"\nData is not found..";
	}
	cout<<"\nEnter data to addatbeg:";
	cin>>c;
	obj.addatbeg(c);
	obj.show();
	cout<<"\nEnter data to addatend:";
	cin>>c;
	obj.addatend(c);
	obj.show();
	cout<<"\nEnter position to add node:";
	cin>>pos;
	cout<<"\nEnter data to add node:";
	cin>>c;
	obj.addbypos(pos,c);
	obj.show();
	cout<<"\nAfter deleting 1st node:";
	obj.delatbeg();
	obj.show();
	cout<<"\nAfter deleting end node:";
	obj.delatend();
	obj.show();
	cout<<"\nEnter position to delete node:";
	cin>>pos;
	obj.delbypos(pos);
	obj.show();
	c=obj.count_main();
	cout<<"\nCount is:"<<c;
	cout<<"\nEnter data to search..";
	cin>>c;
	pos=obj.search_main(c);
	if(pos==1)
	{
		cout<<"\nFound..";
	}
	else
	{
		cout<<"\nNot found..";
	}*/
	obj.create_main();
	obj.show();
}
void CLL :: create()
{
	int x,i,n;
	cout<<"\nEnter number of nodes:";
	cin>>n;
	if(n==0)
	{
		cout<<"\nEmpty list..";
		return;
	}
	cout<<"\nEnter Data for 1st node:";
	cin>>x;
	front=new node(x);
	node *p=front;
	for(i=1;i<n;i++)
	{
		cout<<"\nEnter data for next node:";
		cin>>x;
		p->next=new node(x);
		p=p->next;
	}
	rear=p;
	p->next=front;
}
void CLL :: show()
{
	node *p=front;
	if(front==NULL)
	{
		cout<<"\nEmpty list..";
		return;
	}
	do
	{
		cout<<"\n"<<p->data<<" "<<(long long)p;
		p=p->next;
	}while(p!=front);
}
int CLL :: count()
{
	int cnt=0;
	node *p=front;
	if(front==NULL)
	{
		return 0;
	}
	do
	{
		cnt++;
		p=p->next;
	}while(p!=front);
	return cnt;
}
int CLL :: search(int x)
{
	node *p=front;
	do
	{
		if(p->data==x)
		{
			return 1;
		}
		p=p->next;
	}while(p!=front);
	return 0;
}
void CLL :: addatbeg(int x)
{
	node *p=new node(x);
	if(front==NULL)
	{
		front=p;
		rear=p;
		p->next=p;
	}
	else
	{
		p->next=front;
		front=p;
		rear->next=front;
	}
}
void CLL :: addatend(int x)
{
	node *p=new node(x);
	if(front==NULL)
	{
		front=p;
		rear=p;
		p->next=front;
	}
	else
	{
		p->next=front;
		rear->next=p;
		rear=p;
	}
}
void CLL :: addbypos(int pos,int x)
{
	int c;
	c=count();
	if(pos<1 || pos>c+1 )
	{
		cout<<"\nInvalid position..";
		return;
	}
	if(pos==1)
	{
		addatbeg(x);
	}
	else
	{
		node *p=new node(x),*q=front;
		int i;
		for(i=1;i<pos-1;i++)
		{
			q=q->next;
		}
		if(pos==c+1)
		{
			p->next=front;
			rear=p;
		}
		else
		{
			p->next=q->next;
		}
		q->next=p;
	}
}
void CLL :: delatbeg()
{
	if(front==NULL)
	{
		cout<<"\nEmpty list..";
		return;
	}
	if(front==rear)
	{
		delete front;
		rear=front=NULL;
	}
	else
	{
		node *p=front;
		front=front->next;
		rear->next=front;
		delete p;
	}
}
void CLL :: delatend()
{
	if(front==NULL)
	{
		cout<<"\nEmpty list...";
		return;
	}
	if(front==rear)
	{
		delete front;
		front=rear=NULL;
	}
	else
	{
		node *p=front,*q;
		do
		{
			q=p;
			p=p->next;
		}while(rear!=p);
		q->next=front;
		delete p;
		rear=q;
	}	
}
void CLL :: delbypos(int pos)
{
	int c;
	c=count();
	if(pos<1 || pos>c)
	{
		cout<<"\nInvalid postion...";
		return;
	}
	if(front==rear)
	{
		delete front;
		front=rear=NULL;
	}
	else
	{
		node *p=front,*q;
		for(int i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		delete q;
		if(rear==q)
		{
			rear=p;
		}
	}
}
int CLL :: count_main()
{
	int y;
	y=count_rec(front);
	return y;
}
int CLL :: count_rec(node *p)
{
	if(p==rear)
	{
		return 1;
	}
	else
	{
		int c;
		c=count_rec(p->next);
		return c+1;
	}
}
int CLL :: search_main(int x)
{
	int y;
	y=search_rec(front,x);
	return y;
}
int CLL :: search_rec(node *p,int x)
{
	if(p->data==x)
	{
		return 1;
	}
	else if(p->next==front)
	{
		return 0;
	}
	else
	{
		int y;
		y=search_rec(p->next,x);
		return y;
	}
}
void CLL :: create_main()
{
	int data,x,flag=0;
	char str[20];
	cout<<"\nEnter STOP when you want to stop....";
	while(1)
	{
		cout<<"\nEnter data:";
		cin.getline(str,20);
		data=strcmp(str,"STOP");
		if(data==0)
		{
			break;
		}
		else
		{
			flag++;
		}
		x=atoi(str);
		if(flag==1)
		{
			front=new node(x);
			front->next=front;
			rear=front;
		}
		else
		{
			rear->next=new node(x);
			rear=rear->next;
			rear->next=front;
		}
	}
	if(flag==0)
	{
		cout<<"\nNothing you enter..";
	}
	cout<<"\nfront=="<<(long long)front;
	cout<<"\nrear=="<<(long long)rear;
	cout<<"\nrear->next=="<<(long long)rear->next;
}