#include <iostream>

using namespace std;

class node{
private:
    int data;
    node* right;
    node* left;

public:
    node(int d)
    {
        left = NULL;
        right = NULL;

        this->data = d;
    }

    node()
    {

        left = NULL;
        right = NULL;
    }

    void print_node()
    {
        cout <<"\nNode data: " << this->data << endl;

    }
    friend class BSTree;
};

class BSTree{
public:
    node *root;
    int len;

    void disp(node* temp,int order)
    {
        if(temp!=NULL){
            switch(order){
            case -1:
                temp->print_node();
                disp(temp->left,order);
                disp(temp->right,order);
                break;

            case 0:
                disp(temp->left,order);
                temp->print_node();
                disp(temp->right,order);
                break;

            case 1:
                disp(temp->left,order);
                disp(temp->right,order);
                temp->print_node();
                break;
            default:
                cout<<"[ERROR] : Invalid order value!"<<endl;
                break;
            }
        }

    }
void search_tree(int value)
{
    int flag=0;
    node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==value)
            {cout<<"Number found\n";
            flag=1;}
        if (value<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(flag==0)
        cout<<"Number not found\n";
}

node* del(node* toor,int key){
        if(toor==NULL){
            cout << "Element not found or tree is empty!"<<endl;
            return toor;
        }
        if(toor->data > key){
            toor->left = del(toor->left,key);
            return toor;
        }
        else if(toor->data < key){
            toor->right = del(toor->right,key);
            return toor;
        }
        if(toor->left == NULL)
            {
            cout << "Nothing to the left!"<<endl;
            node* temp = toor->right;
            delete toor;
            return temp;
        }
        else if(toor->right == NULL)
        {
            cout << "Nothing to the right!"<<endl;
            node* temp = toor->left;
            delete toor;
            return temp;
        }

        else{
            node* parent = toor->right;
            node* child = toor->right;


            while(child->left != NULL)
                {
                parent = child;
                child = child->left;
            }
            parent->left = child->right;

            if(child == parent)
                {
                toor->right = child->right;
            }

            toor->data = child->data;
            delete child;
            return toor;
        }
    }
public:
    BSTree()
    {
        root = NULL;
        len = 0;
    }

    void ins(int d)
    {
        node *newnode = new node(d);

        if(root == NULL){
            root = newnode;
            len++;
        }
        else{
            node *temp = root;

            while(true)
                {
                if(newnode->data <= temp->data)
                {
                    if(temp->left == NULL)
                    {
                        temp->left = newnode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if(newnode->data > temp->data)
                {
                    if(temp->right == NULL)
                    {
                        temp->right = newnode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
            temp = newnode;
            len++;
        }
    }
        void display(int order)
        {
            cout << "Number of nodes in the tree: " << len<<"\n"<<endl;
            disp(root,order);

        }

    node* del(int key)
    {
        node* temp = del(root,key);
        if(temp!=NULL)
            {
            len--;
        }
        return temp;
    }

};
main()
{
    BSTree b;
    int ch;
    while(1)
    {
    cout<<"Enter your choice:\n1. Create\n2. Display\n3. Search\n4. Delete Node\n";
    cin>>ch;
    switch(ch){
        case 1:
    b.ins(25);
    b.ins(15);
    b.ins(20);
    b.ins(30);
    b.ins(10);
    b.ins(5);
    b.ins(12);
    b.ins(11);
    b.ins(14);
    b.ins(60);
        break;
        case 2:
            {int a;
            cout<<"Choose between: \n1. Inorder\n2. Postorder\n3. Preorder\n";
            cin>>a;
            switch(a)
            {
            case 1:  b.display(0);;
            break;
            case 2:   b.display(1);
            break;
            case 3:  b.display(-1);
            break;
            }
            }break;
            case 3:
                int n;
                cout<<"Enter number to be searched\n";
                cin>>n;
                b.search_tree(n);
                break;
            case 4:
                int k;
                cout<<"Enter element to be deleted";
                cin>>n;
                b.del(n);
                break;
    }}
}
