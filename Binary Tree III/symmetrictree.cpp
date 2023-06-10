/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool find(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2){
    if(root1==nullptr || root2==nullptr) return root1==root2;
    if(root1->data!=root2->data) return false;
    
    return find(root1->left,root2->right) && find(root1->right,root2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root==nullptr) return true;
      
    if(root->left && root->right){
        return find(root->left,root->right);
    } 
    return false;
}