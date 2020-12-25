#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int m)
{
 Node* temp=new Node();
   temp->data=m;
   temp->left=NULL;
   temp->right=NULL;
   return temp;
}
struct Node* makeBst(int a[],int start,int end)
{
   int m=(start+end)/2;
   Node* root=createNode(a[m]);
   if(start==end)
       return root;
   root->left=makeBst(a,start,m-1);
   root->right=makeBst(a,m+1,end);
   //return root;
}
void print(Node *node)
   {
       if(node==NULL)
         return;
         cout<<node->data<<" ";
         print(node->left);
         print(node->right);
   }
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n<0)
	     return 0;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	        Node* node=makeBst(a,0,n-1);
	        print(node);
	        cout<<endl;
	}
	return 0;
}