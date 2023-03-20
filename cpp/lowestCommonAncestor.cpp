#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val):val(_val){
    }
    /* data */
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* left, TreeNode* right){
    if(!root || root == left || root == right){
        return root;
    }
    TreeNode* l = lowestCommonAncestor(root->left, left, right);
    TreeNode* r = lowestCommonAncestor(root->right, left, right);
    if(l){
        return l;
    }else if(r){
        return r;
    }else if(l && r){
        return root;
    }else{
        return nullptr;
    }
}

int get_dis(TreeNode* x, TreeNode* y){
    queue<TreeNode*> q;
    int dis = 0;
    q.push(x);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==y){
                return dis;
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        dis++;
    }
    return -1;
}

int main(){

    return 0;
}