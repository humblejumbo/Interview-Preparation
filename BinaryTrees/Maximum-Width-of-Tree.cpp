//https://leetcode.com/problems/maximum-width-of-binary-tree/

//Not getting AC but correct approach though

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
    
    int hi=0;
    void helper(TreeNode* root,int arr[10000],int index)
    {
        if(root==NULL)
            return;       
        
        arr[index]=root->val;
        hi=index;
        helper(root->left,arr,2*index);
        helper(root->right,arr,2*index+1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        
          int arr[10000];
          int minArr[10000],maxArr[10000];          
          memset(arr,-1,sizeof(arr));
          fill(minArr,minArr+10000,INT_MAX);
          fill(maxArr,maxArr+10000,INT_MIN);
          
         

          helper(root,arr,1);
        
       // cout<<hi<<"*"<<arr[22]<<endl;
        
         for(int i=1;i<10000;i++)
         {
             if(arr[i]!=-1)
             {
                 int k=(int)log2(i);
                 //cout<<minArr[k]<<"*"<<maxArr[k]<<endl;
                 if(minArr[k]>i)
                     minArr[k]=i;
                 
                 if(maxArr[k]<i)
                     maxArr[k]=i;
             }
         }

        // for(int i=1;i<=hi;i++)
        //     cout<<arr[i]<<endl;
        
        
        
        int maxDiff=-1;
        
         int levels=(int)log2(10000);
        cout<<levels<<endl;
        
        for(int i=0;i<=levels;i++)
        {
            if(maxArr[i]!=INT_MIN && minArr[i]!=INT_MAX )
                maxDiff=max(maxDiff,maxArr[i]-minArr[i]+1);
            else
                break;
            //cout<<minArr[i]<<" "<<maxArr[i]<<endl;
        }
          
        return maxDiff;
    }   
      
};
