#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(){
        next=NULL;
    }
    Node(int n)
    {
        data=n;
        next=NULL;
    }
};
class List : Node
{
    Node *listptr;
    Node *temp;
public:
    List()
    {
        listptr=NULL;
        temp=NULL;
    }
   void create(int);
   void insert_beg();
   void insert_end();
   void insert_mid();
   void delete_beg();
   void delete_mid(int);
   void delete_end();
   void display();
   void length();
   void rev();
   void conc();
   void uni(List &l1,List &l2);
   void in(List &l1,List &l2);
   void rem_ext();
   void con_in_un();
};
void List :: create(int num)
{
       Node *newnode = new Node(num);
       newnode->data=num;
       newnode->next=NULL;
    if(listptr==NULL)
    {
       listptr=newnode;
       temp=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;

    }
}
void List :: insert_beg()
{
    if(listptr==NULL)
        cout<<"List not created";
    else
    {
       int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
          Node *newnode = new Node(num);
       newnode->data=num;
       newnode->next=listptr;
       listptr=newnode;
    }
}
void List :: insert_end()
{
    Node *temp=listptr;
    while (temp->next!=NULL)
       {temp=temp->next;}
    int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
        Node *newnode = new Node(num);
       newnode->data=num;
       temp->next=newnode;
       newnode->next=NULL;
}
void List :: display()
{
   Node *temp= listptr;
   while(temp->next!=NULL)
   {
       cout<<temp->data<<"->";
       temp=temp->next;
   }
   cout<<temp->data<<"\n";
}
void List :: insert_mid()
{
    Node *temp=listptr;

    int num,pos,i;
       cout<<"Enter the value to insert \n";
       cin>>num;
        Node *newnode = new Node(num);
       newnode->data=num;
       cout<<"Enter the position \n";
       cin>>pos;
  for(i=1;i<pos-1;i++)
  {
      temp=temp->next;
  }
  newnode->next=temp->next;
  temp->next=newnode;
  temp=newnode;
}
void List :: delete_beg()
{
	Node *temp=listptr;
	Node *temp1=listptr;
	temp=temp->next;
	listptr=temp;
	free(temp1);
}
void List :: delete_mid(int pos)
{
    Node *temp1=listptr;
    Node *temp2=listptr;
    int i;

    for(i=1;i<pos-1;i++)
    {
        temp1=temp1->next;
        i++;
    }
    temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
void List :: delete_end()
{


    Node *temp1=listptr;
    if (temp1->next==NULL)
        cout<<"list is empty\n";
    Node *temp2=listptr;
    int i=1,j=1;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
        i++;
    }
    while(j<i-1)
    {
        temp1=temp1->next;
        j++;
    }
   // cout<<"just before \n"<<temp1->data<<"\n";
    //cout<<"at the end \n"<<temp2->data<<"\n";
    temp1->next=NULL;
    free(temp2);
}
void List :: length()
{
    Node *temp = listptr;
    int cnt=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    cout<<"length of the linked list is  "<<cnt<<"\n";
}
void List :: rev()
{
    if(this->listptr==NULL)
	cout<<"list not created";
	else{

	Node *forward,*curr,*back;
	forward=listptr;
	curr=NULL;
	while(forward!=NULL)
	{
		back=curr;
		curr=forward;
		forward=forward->next;
		curr->next=back;

	}
	listptr=curr;
      display();
}
}
void List :: conc()
{
   List l2;
   int num;
   Node *temp=listptr;
          cout<<"\nHow many elements to be concatenated?\n";
          cin>>num;
          for(int i=0;i<num;i++)
          {
        int n;
       cout<<"Enter the value to insert \n";
       cin>>n;
              l2.create(n);
          }
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          temp->next=l2.listptr;
          display();
          temp=listptr;
            int c=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        c++;
    }

          	Node *i,*j,*p;
	for(i=listptr;i->next!=NULL;i=i->next)
	{
		p=listptr;
		j=p->next;
		c--;
		for(int k=0;k<c;k++)
		{
			if(j->data<p->data)
			{
				int tem;
				tem=j->data;
				j->data=p->data;
				p->data=tem;
			}
			p=j;
			j=j->next;
		}
	}
	temp=listptr;
/*	if((temp->next->data)<(temp->data))
			{
				int tem;
				tem=temp->next->data;
				temp->next->data=temp->data;
				temp->data=tem;
			}*/
	display();
}
void List :: uni(List& l1,List& l2)
{
    List l3;
    int un_flag;
    Node *temp1, *temp2, *temp3;
    temp1=l1.listptr;
    temp2=l2.listptr;
    for(temp1=l1.listptr;temp1!=NULL;temp1=temp1->next)
    {
        un_flag=0;
        for(temp2=l2.listptr;temp2!=NULL;temp2=temp2->next)
        {
            if(temp1->data==temp2->data)
            {
                un_flag=1;
                break;
            }
        }

        if(un_flag==0)
        {
            l3.create(temp1->data);
        }
    }
    temp3=l2.listptr;
    while(temp3!=NULL)
    {
     l3.create(temp3->data);
       temp3=temp3->next;
    }
    l3.display();
}
void List :: in(List &l1,List &l2)
   {
    List l3;
    int un_flag;
    Node *temp1, *temp2, *temp3;
    temp1=l1.listptr;
    temp2=l2.listptr;
    for(temp1=l1.listptr;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=l2.listptr;temp2!=NULL;temp2=temp2->next)
        {
            if(temp1->data==temp2->data)
            {
                 l3.create(temp1->data);
                 break;
            }
        }

    }
    l3.display();
}
void  List ::con_in_un()
{
      List l2;
      List l3;
      Node *temp=listptr;
      Node *temp1=NULL;
      Node *temp2=NULL;
      Node *temp3=NULL;
   int num;
          cout<<"\nHow many elements to be concatenated?\n";
          cin>>num;
          for(int i=0;i<num;i++)
          {
        int n;
       cout<<"Enter the value to insert \n";
       cin>>n;
              l2.create(n);
          }
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          temp->next=l2.listptr;
          display();
          temp=listptr;
 /*for (temp1=listptr;temp1->next!=NULL;temp1=temp1->next)
    {
         for(temp2=temp1->next;temp2->next!=NULL;temp2=temp2->next)
         {
             if(temp1->data==temp2->data)
             {

                 free(temp1);
             }
         }
    }
display();
cout<<"this is union";
*/
    for (temp1=listptr;temp1->next!=NULL;temp1=temp1->next)
    {
         for(temp2=temp1->next;temp2->next!=NULL;temp2=temp2->next)
         {
             if(temp1->data==temp2->data)
             {
                 l3.create(temp2->data);
                 break;
             }
         }
    }
l3.display();
cout<<"\nthis is the intersection";

}


int main()
{
    List l;
    List l2;
    int ch;
     while(1)
    {
    cout<<"\nEnter your choice:\n 1.create\n 2.insert from beginning\n 3.insert from end\n 4.insert from intermediate position\n 5.display\n 6.delete from beginning\n";
    cout<<" 7.delete from intermediate\n 8.delete from end\n 9.length of list\n 10.Reverse the list\n 11.Concatenate two lists\n 12.intersection\n 13.union\n";
    cin>>ch;

    switch(ch)
    {
    case 1:
                int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
            l.create(num);
            break;
    case 2:
            l.insert_beg();
            break;
    case 3:
            l.insert_end();   cout<<"a";
            break;
    case 4:
            l.insert_mid();
            break;
    case 5:
            l.display();
            break;
    case 6:
            l.delete_beg();
            break;
    case 7:
        int pos;
          cout<<"What is the position of the node you want to delete?\n";
          cin>>pos;
          l.delete_mid(pos);
            break;
    case 8:
            l.delete_end();
            break;
    case 9:
            l.length();
            break;
    case 10:
            l.rev();
            break;
    case 11:
           l.conc();
            break;
    case 12:
           int n;
            cout<<"How many elements to take intersection of?\n ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                        int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
                l2.create(num);
            }
            l.in(l,l2);
            break;
    case 13:
            cout<<"How many elements to take union of?\n ";
            cin>>n;
            for(int i=0;i<n;i++)
            {   int num;
                cout<<"Enter the value to insert \n";
                cin>>num;
                l2.create(num);
            }
            l.uni(l,l2);
            break;
    case 14:
        l.con_in_un();
    }
    }
    return 0;
}
