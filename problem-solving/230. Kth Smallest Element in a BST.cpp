// Solution - 1
// Traverse the whole tree and collect the value in a vector.
// Then sort the vector to get the kth smallest element.
class Solution {
public:
    vector<int>vec;
    void kthSmallestHelper(TreeNode* root) {
        vec.push_back(root->val);
        if(root->left != NULL){
            kthSmallestHelper(root->left);
        }
        if(root->right != NULL){
            kthSmallestHelper(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k){
        kthSmallestHelper(root);
        sort(vec.begin(),vec.end());
        return vec[k-1];
    }
};


// Solution - 2 
// We can use inorder traversal. As the given tree is a BST,
// the inorder traversal will give us the sorted vector. 
// Then we can skip the vector sorting.
class Solution {
public:
    vector<int>vec;
    void kthSmallestHelper(TreeNode* root) {
        if(root->left != NULL){
            kthSmallestHelper(root->left);
        }
        vec.push_back(root->val);
        if(root->right != NULL){
            kthSmallestHelper(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k){
        kthSmallestHelper(root);
        return vec[k-1];
    }
};
