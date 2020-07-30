//https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void leafNodes(TreeNode* root, vector<TreeNode*> & leaf)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
            leaf.push_back(root);
        
        leafNodes(root->left,leaf);
        leafNodes(root->right,leaf);

    }
    
    bool findPath(TreeNode* root,TreeNode* node,vector<TreeNode*> &path)
    {
        if(root==NULL)
            return false;
        
        bool l=findPath(root->left,node,path);
        bool r=findPath(root->right,node,path);
        
        if(root==node)
        {
            path.push_back(root);
            return true;
        }
        
        if(l || r)
        {
            path.push_back(root);
            return true;
        }
        else
            return false;
    }
    
    TreeNode* findLCA(TreeNode* root,TreeNode* n1,TreeNode* n2)
    {
        vector<TreeNode*> path1,path2;
        findPath(root,n1,path1);
        findPath(root,n2,path2);
        
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        
        for(int i=0;i<min(path1.size(),path2.size());i++)
        {
            if(path1[i]!=path2[i])
                return path1[i-1];
        }
        return NULL;
    }
    
    
    int depth(TreeNode* root,TreeNode* node)
    {
        vector<TreeNode*> path;
        findPath(root,node,path);
        
        return path.size()-1;
    }
    

    
    
//     int countPairs(TreeNode* root, int distance) {
        
//         vector<TreeNode*> leaf;
//         leafNodes(root,leaf);
        
        
//         int count=0;
//         for(int i=0;i<leaf.size();i++)
//         {
//             for(int j=i+1;j<leaf.size();j++)
//             {
//                 TreeNode* lca=findLCA(root,leaf[i],leaf[j]);
//                 int dis=depth(root,leaf[i])+depth(root,leaf[j])-2*depth(root,lca);
//                 //cout<<leaf[i]->val<<" "<<leaf[j]->val<<" "<<depth(root,leaf[i])<<" "<<depth(root,leaf[j])<<" "<<depth(root,lca)<<endl;
//                 if(dis<=distance)
//                     count++;
                
//             }
//         }
        
//         return count;
//     }
    
    
    
  //************ Efficient Approach**********************
    int ans=0;
    vector<int> helper(TreeNode* root, int dis)
    {
        if(root==NULL)
            return {};
        
        if(root->left==NULL && root->right==NULL)
            return {1};
        
        auto left=helper(root->left,dis);
        auto right=helper(root->right,dis);
        
        for(auto l:left)
        {
            for(auto r:right)
            {
                if(l&&r&&(l+r<=dis))
                    ans++;
            }
        }
        
        vector<int> res;
        
        for(auto l:left)
        {
           if(l && l+1<dis)
               res.push_back(l+1);
            
        }
        
        for(auto r:right)
        {
            if(r && r+1<dis)
                res.push_back(r+1);
        }
        
        return res;
    }
    
    
    int countPairs(TreeNode* root, int distance)
    {
        helper(root,distance);
        return ans;
    }
    
};
