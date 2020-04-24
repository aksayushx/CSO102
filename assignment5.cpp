#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    char data;
    node* left;
    node* right;
};
node* root=NULL;
node* create_new_node(char x)
{
    node* ptr;
    ptr=new node;
    ptr->data=x;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
void declare(char x)
{
    node* ptr=create_new_node(x);
    if(root==NULL)
        root=ptr;
    else
    {
        node* temp=root;
        while(temp!=NULL)
        {
            if(x<temp->data)
            {
                if(temp->left!=NULL)
                    temp=temp->left;
                else
                    break;
            }
            else if(x>temp->data)
            { 
                if(temp->right!=NULL)
                    temp=temp->right;
                else
                    break;
            }
            else
            {
                cout<<"Character already present\n";
                return;
            }        
        }
        if(x>temp->data)
            temp->right=ptr;
        else
            temp->left=ptr; 
    }
    
}
node* inorderSuccessor(node* y)
{
    node* current = y;
    while (current->left != NULL)
        current = current->left;
    return current;
}
node* del(node* temp, char data)
{
    if (temp == NULL)
        return temp;
    if (data < temp->data)
        temp->left = del(temp->left, data);
    else if (data > temp->data)
        temp->right = del(temp->right, data);
    else
    {
        if (temp->left == NULL)
        {
            node *t = temp->right;
            delete temp;
            return t;
        }
        else if (temp->right == NULL)
        {
            node *t = temp->left;
            delete temp;
            return t;
        }
        node* t = inorderSuccessor(temp->right);
        temp->data = t->data;
        temp->right = del(temp->right, temp->data);
    }
    return temp;
}
void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}
void preorder(node* temp)
{
    if(temp==NULL)
        return;
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(node* temp) 
{ 
    if (temp == NULL) 
        return;  
    postorder(temp->left); 
    postorder(temp->right); 
    cout << temp->data << " "; 
} 
void display()
{
    cout<<"Preorder:\n";
    preorder(root);
    cout<<'\n';
    cout<<"PostOrder:\n";
    postorder(root);
    cout<<'\n';
    cout<<"Inorder:\n";
    inorder(root);
    cout<<'\n';
    
}
int main()
{
    int n;
    cin>>n;
    int i,j;
    char x;
    char op[10];
    for(i=0;i<n;i++)
    {
        cin>>op;
        if(strcmp(op,"INSERT")==0)
        {
            cin>>x;
            declare(x);
        }
        else if(strcmp(op,"DEL")==0)
        {
            cin>>x;
            del(root,x);
        }
        else
            display();
    }
    return 0;
}


