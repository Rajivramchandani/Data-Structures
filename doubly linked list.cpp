#include<iostream>
#include<stdlib.h>

using namespace std;
class List;
class Node
{
    int data ;
    Node *next;
    Node *prev;
    Node()
    {
        next=NULL;
        data=0;
    }
    Node(int num)
    {
        data=num;
        next=NULL;
        prev=NULL;
    }
    friend class List;
};
class List
{
    Node * temp;
    Node *listptr;
    public :
    List()
    {
        listptr=temp=NULL;
    }
    int ask_num();
    int len();
    int display();
    Node * traverse(int pos);
    Node * insert_list(int pos,int num);
    Node * delete_list(int pos);
    Node * conc(List &l1,List &l2);
    Node * search_list(int num);
    Node * sort_list();
    Node * reverse_list();
    Node * copy_list(List l);
    Node * uni(List& l1,List& l2);
    Node * in(List &l1,List &l2);
    Node * merge_list(List &l1, List &l2);
};
int List :: len()
{
    temp=listptr;
    int length=1;
    while(temp->next!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
Node * List:: traverse(int pos)
{
    temp=listptr;
if (pos==0)   //transverse till end
{
    temp=listptr;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
}
else
    {
      for(int i=1;i<pos;i++)  //transverse till given position
      temp=temp->next;
    }
    return temp;
}
int List :: ask_num()
{
    int num;

    cin>>num;
    return num;
}
Node * List::insert_list(int pos,int num)
{
    Node *newnode = new Node (num);
    if(pos==0)
    {
        if(listptr==NULL)
        {
            listptr=newnode;
            newnode->next=NULL;
            newnode->prev=NULL;
        }
        else
        {
            temp=traverse(0);
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
            newnode->next=NULL;
        }
    }
    else if (pos==-1)
    {
        listptr->prev=newnode;
        newnode->next=listptr;
        listptr=newnode;
    }
    else
      {
        temp=listptr;
        temp=traverse(pos-1);
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next->prev=newnode;
      }
      return listptr;
}
int List :: display()
{
    temp=listptr;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<temp->data;
}
Node * List:: delete_list(int pos)
{
    temp=listptr;
   Node * temp1=listptr;
   Node * temp2=listptr;
    if(pos==0)
    {
        listptr=listptr->next;
        listptr->prev=NULL;
        free(temp);
    }
    else if (pos==100)
    {
        if(temp->next==NULL)
        {
            cout<<"list is empty";
        }
        else
        {
            temp1=traverse(0);
            temp2=temp1->prev;
           //  cout<<"hello";
            temp2->next=NULL;
            free(temp1);

        }
    }
    else
    {
        temp1=traverse(pos-1);
        temp=traverse(pos);
        temp1->next=temp->next;
        temp->next->prev=temp1;
        free(temp);
    }
    return listptr;
}
Node * List :: conc(List &l,List &l2)
{
    l.temp=traverse(0);
    l.temp->next=l2.listptr;
    l2.listptr->prev=l.temp;
    return l.listptr;
}
Node * List :: search_list(int num)
{
    Node * temp1;
    int i=0,flag=0;

        for(temp1=listptr;temp1->next!=NULL;temp1=temp1->next)
        {
            i++;
           if(num==temp1->data)
            {
                flag=1;
            cout<<"number found at "<<i<<"\n";
            }
        }
        if(flag==0)
        {
            cout<<"element not present in list";
        }

    return listptr;
}
Node * List :: sort_list()
{
    Node *i,*j,*p;
int c=len();
	for(i=listptr;i->next->next!=NULL;i=i->next)
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
	if((temp->next->data)<(temp->data))
			{
				int tem;
				tem=temp->next->data;
				temp->next->data=temp->data;
				temp->data=tem;
			}
    return listptr ;
}
Node * List :: copy_list(List l)
{
int data;
    l.temp=l.listptr;
   do
    {
        data=l.temp->data;
        insert_list(0,data);
        l.temp=l.temp->next;
    }
    while(l.temp!=NULL);
    return listptr;
}
Node * List :: reverse_list()
{
     if(listptr->next==NULL)
	cout<<"list not created";
	else{
    Node * tempo;
    Node * forw;
    Node * curr;
    forw=listptr;
    curr=NULL;
    do
    {
        curr=forw;
        forw=forw->next;
        tempo=curr->next;
        curr->next=curr->prev;
        curr->prev=tempo;

    }while(forw!=NULL);
    listptr=curr;
	}
	return listptr;
}
Node * List :: uni(List& l1,List& l2)
{
    List l3;
    int un_flag=0;
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
            l3.insert_list(0,temp1->data);
        }

    }
    temp3=l2.listptr;
    while(temp3!=NULL)
    {
     l3.insert_list(0,temp3->data);
       temp3=temp3->next;
    }
   l3.display();
}
Node * List :: in(List &l1,List &l2)
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
                 l3.insert_list(0,temp1->data);
                 break;
            }
        }

    }
    l3.display();
}
Node * List :: merge_list(List &l,List &l2)
{
    l.temp=l.listptr;
    l2.temp=l2.listptr;
    for(l.temp=l.listptr;l.temp!=NULL;l.temp=l.temp->next)
    {
        int n;
        cout<<"Enter the value to merge :";
        cin>>n;
        l2.insert_list(0,n);
        l2.insert_list(0,l.temp->data);
    }
    l2.display();
}
int main()
{
    List l;
    List l2;
    int n,num;
    int ch;
     while(1)
    {
    cout<<"\nEnter your choice:\n 1.create\n 2.display \n 3.insert from beginning\n 4.insert from intermediate position\n 5.insert from end \n 6.delete from beginning\n";
    cout<<" 7.delete from end\n 8.delete from intermediate\n 9.concatenate list\n 10.search from list\n 11.sort list\n 12.reverse the list\n 13.copy to list 2\n 14.length of the list\n ";
    cout<<"15.union of two lists\n 16.intersection of two lists\n 17.merge contents of two lists\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
    cout<<"Enter the number \n";
         num=l.ask_num();
         l.insert_list(0,num);
            break;
    case 2:
          l.display();
            break;
    case 3:
    cout<<"Enter the number \n";
         num=l.ask_num();
        l.insert_list(-1,num);
            break;
    case 4:
        int pos;
        cout<<"enter the position \n";
        pos=l.ask_num();
        cout<<"enter the number \n";
        num=l.ask_num();
        l.insert_list(pos,num);
            break;
    case 5:
    cout<<"Enter the number \n";
         num=l.ask_num();
        l.insert_list(0,num);
            break;
    case 6:
        l.delete_list(0);
            break;
    case 7:
        l.delete_list(100);
        break;
    case 8:
        cout<<"enter the position \n";
        pos=l.ask_num();
        l.delete_list(pos);
        break;
    case 9:

        cout<<"enter the number of elements to be concatenated\n";
         n = l.ask_num();
        cout<<"enter the elements\n";
        for(int i=0;i<n;i++)
        {
           cout<<"Enter the number \n";
            num=l.ask_num();
            l2.insert_list(0,num);
        }
        l.conc(l,l2);
        break;

    case 10:
        cout<<"enter the number you want to search in the list\n";
        num=l.ask_num();
        l.search_list(num);
        break;
    case 11:
        l.sort_list();
        break;
    case 12:
      l.reverse_list();
        break;
   case 13:
        l2.copy_list(l);
        cout<<"the copied list is\n ";
        l2.display();
        break;
   case 14:
        cout<<"length of the string is "<<l.len();
        break;
   case 15:
           cout<<"How many elements to take union of?\n ";
            cin>>n;
            for(int i=0;i<n;i++)
            {   int num;
                cout<<"Enter the value to insert \n";
                cin>>num;
                l2.insert_list(0,num);
            }
            l.uni(l,l2);
            break;
   case 16:
      int n;
            cout<<"How many elements to take intersection of?\n ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                        int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
                l2.insert_list(0,num);
            }
            l.in(l,l2);
            break;
   case 17:
        l.merge_list(l,l2);
        break;

    }
    }

}
