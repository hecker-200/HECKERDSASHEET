
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
        
        cout << "Enter the right child of " << p->val << " if none -1" << endl;
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

void itpostorder(struct node*root){
    
    stack<node*>s1;
    stack<node*>s2;
    
    s1.push(root);
    
    while(!s1.empty()){
        
        node*x = s1.top();
        s1.pop();
        
        if(x->left) s1.push(x->left);
        if(x->right) s1.push(x->right);
        
        s2.push(x);
    }
    
    
    while(!s2.empty()){
        cout << s2.top()->val << " ";
        s2.pop();
    }
    
}

void singletraversal(struct node*root){
    
    stack<pair<node*,int>>st;
    
    st.push({root,1});
    
    vector<int>preorder;
    vector<int>inorder;
    vector<int>postorder;
    
    while(!st.empty()){
        
        pair<node*,int>p = st.top();
        st.pop();
        
        if(p.second == 1){
            
            preorder.push_back(p.first->val);
            p.second++;
            
            st.push(p);
            
            if(p.first->left){
                st.push({p.first->left,1});
            }
        }
        
        else if(p.second == 2){
            
            inorder.push_back(p.first->val);
            p.second++;
            
            st.push(p);
            
            if(p.first->right){
                st.push({p.first->right,1});
            }
        }
        
        else if(p.second == 3){
            
            postorder.push_back(p.first->val);
        }
    }
    
    for(auto a : preorder){
        cout << a << " ";
    }
    
    cout << endl;
    
    for(auto a : inorder){
        cout << a << " ";
    }
    
    cout << endl;
    
    for(auto a : postorder){
        cout << a << " ";
    }
    
    cout << endl;
}

int height(struct node*root){
    
    if(root == nullptr) return 0;
    
    int l = height(root->left);
    int r = height(root->right);
    
    return 1 + max(l,r);
}

int dist(struct node*root){
    
    if(root == nullptr) return 0;

    int l = height(root->left);
    int h = height(root->right);

    return  abs(l+h);
}

bool isitbalanced(struct node*root){
    
    if(root == nullptr) return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh) > 1) return false;
    
    bool checkleft = isitbalanced(root->left);
    bool checkright = isitbalanced(root->right);
    
    
    return checkright && checkleft;
}

int distanceofnode(struct node*root){
    
    queue<node*>q;
    
    q.push(root);
    
    int maxi = INT_MIN;
    
    while(!q.empty()){
        
        node*p = q.front();
        q.pop();
        
        if(p->left){
            q.push(p->left);
        }
        
        if(p->right){
            q.push(p->right);
        }
        
        maxi = max(maxi,dist(p));
    }
    
    return maxi;
    
}

int diameter(struct node*root,int&maxi){
    
    if(root == nullptr) return 0;
    
    int lh = diameter(root->left,maxi);
    int rh = diameter(root->right,maxi);
    
    maxi = max(maxi,(lh + rh));
    
    return 1 + max(lh,rh);
    
}

int diameter2(struct node*root){
    
    int maxi = 0;
    diameter(root,maxi);
    
    return maxi;
}

int ans(struct node*root,int &sum){
    
    if(root == nullptr) return 0;
    
    int l = (0,ans(root->left,sum));
    int r = max(0,ans(root->right,sum));
    
    int total = l + r + root->val;
    int maxi = max(maxi,total);
    
    
    return root->val + maxi;
    
    
}

void indexing(struct node*root){
    
    queue<pair<node*,long long>>q;
    
    long long width = 0;
    
    q.push({root,0});
    
    while(!q.empty()){
        
        long long n = q.size();
        long long l = q.front().second;
        long long r = q.back().second;
        
        width = max(width,r-l+1);
        
        for(int i = 0;i<n;i++){
            
            node*temp = q.front().first;
            long long id = q.front().second;
            q.pop();
            
            if(temp->left){
                q.push({temp->left,2*(id)+1});
            }
            
            if(temp->right){
                q.push({temp->right,2*(id)+2});
            }
            
            
        }
    }
    
    cout << width << endl;
    
    
}

int main()
{
    struct node*root = creatingbinarytree();
    
    indexing(root);
    


    return 0;
}