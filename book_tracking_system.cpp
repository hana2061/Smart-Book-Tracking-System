#include<iostream>
#include<stdlib.h>
using namespace std;
int books_returned[100];
int front=-1,rear=-1;
int i=0;
struct node{
int data;
node *left,*right;
};
node*root=NULL;
node*createnode(int value)
{
node*newnode=(node*)malloc(sizeof(node));
newnode->data=value;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
node*binarysearchtree(node* root,int value)
{
if(root==NULL)
return createnode(value);

if(value<root->data)
root->left=binarysearchtree(root->left,value);
else if(value>root->data)
{
    root->right=binarysearchtree(root->right,value);
}
return root;
}
void inorder(node *root)
{
if(root==NULL)
return;
;


inorder(root->left);
books_returned[i++]=root->data;
inorder(root->right);

}
void return_book()
{
int book_id;
char ans='Y';
while(ans=='Y'||ans=='y')
{
cout<<"Enter book id to return:";   
cin>>book_id;
root=binarysearchtree(root,book_id);
cout<<"Book returned successfully"<<endl;
cout<<"Do you want to return more books?(Y/N):";
cin>>ans;
}
inorder(root); 
if(i > 0)
{ 
    front = 0; 
    rear = i - 1;
}
}
void search_book()
{
int book_id;
cout<<"Enter book id to search:";   
cin>>book_id; 
for(int i=0;i<100;i++)
{
    if(books_returned[i]==book_id)
    {
        cout<<"Book found"<<endl;
        return;
    }
    else
    {
        cout<<"Book not found"<<endl;
        return;
    }

}
}

void total_returned_books()
{
    
    if (front == -1 || front > rear) {
            cout << "no books returned \n";
            return;
        }
        else{
            front=0;
        }
        cout << "total books returned in a day "<<endl;
        for (int j = front; j <= rear; j++) {
            cout << "book id: "<<books_returned[j] << endl;
        }
}
int main()
{

int n,value,choice;
char ans='Y';
while(ans=='Y'||ans=='y')
{
cout<<"----------MENU----------\n";
cout<<"1. return book"<<endl;
cout<<"2. search book"<<endl;
cout<<"3. total returned books"<<endl;
cout<<"Enter your choice: ";
cin>>choice;
cout<<endl;
switch (choice)
{
case 1:
    return_book();
    
    break;
case 2:
    search_book();  
    break;
case 3:
    total_returned_books();
    break;

default:
    cout<<"invalid choice";
    break;
}
cout<<"Do you want to continue?(Y/N):";
cin>>ans;
}
return 0;
}