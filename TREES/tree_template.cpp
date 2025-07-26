
#include <bits/stdc++.h>

using namespace std;

struct node{
    struct node*left;
    int val;
    struct node*right;
};


struct node* creatingbinarytree(){
    
    node*root = new node;
    int x;
    cout << "Enter the value of the root" << endl;
    cin >> x;
    root->val = x;
    root->right = root->left = nullptr;
    queue<node*>q;
    q.push(root);
    
    while(!q.empty()){
        node*p = q.front();
        q.pop();
        
        int x,y;
        
        cout << "Enter the left child of " << p->val << " if none -1" << endl;
        cin >> x;
        
        if(x != -1){
            
            p->left = new node;
            p->left->val = x;
            p->left->left = p->left->right = nullptr;
            q.push(p->left);
        }
        
        cout << "Enter the left child of " << p->val << " if none -1" << endl;
        cin >> y;
        
        if(y != -1){
            
            p->right = new node;
            p->right->val = y;
            p->right->left = p->right->right = nullptr;
            q.push(p->right);
        }
    }
    
    return root;
}


void preorder(struct node*root){
    
    if(root == nullptr) return;
    
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node*root){
    
    if(root == nullptr) return;
    
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(struct node*root){
    
    if(root == nullptr) return;
    
    
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelorder(struct node*root){
    queue<node*>q;
    q.push(root);
    
    while(!q.empty()){
        
        node*p = q.front();
        q.pop();
        
        if(p->left){
            q.push(p->left);
        }
        
        if(p->right){
            q.push(p->right);
        }
        
        cout << p->val << " ";
    }
    
    cout << endl;
}

void itpreorder(struct node*root){
    
    stack<node*>st;
    
    st.push(root);
    
    while(!st.empty()){
        
        node*p = st.top();
        st.pop();
        
        if(p->right){
            st.push(p->right);
        }
        
        if(p->left){
            st.push(p->left);
        }
        
        cout << p->val << " ";
    }
}

void itinorder(struct node*root){
    
    stack<node*>st;
    
    while(!st.empty() || root != nullptr){
        
        while(root != nullptr){
            
            st.push(root);
            root = root->left;
        }
        
        node*p = st.top();
        st.pop();
        
        cout << p->val << " ";
        
        root = p->right;
        
        
    }
}





int main()
{
    struct node*root = creatingbinarytree();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelorder(root);
    cout << endl;
    
    itpreorder(root);
    cout << endl;
    
    itinorder(root);
    cout << endl;
    
    

    return 0;
}