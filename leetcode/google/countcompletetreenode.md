```c++
class Solution {
public:
    int getHeight(TreeNode* root) {
       int height = 0;
       while (root->left) {
            root = root->left;
            height += 1;
       }
       return height;
   }
    
   bool exist(int index, int depth, TreeNode* root) {
        int left=0, right=pow(2,depth)-1;
        for (int i=0; i<depth; i++) {
            int mid = left + (int)((right-left)/2);
            if (index <= mid) {
                root = root->left;
                right = mid;
            }else {
                root = root->right;
                left = mid+1;
            }
        }
        return (root != NULL);
   }
    
   int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        
        int height = getHeight(root);
       if (height == 0) return 1;
        
       // Check by binary search if leaf node exist
       int left = 1, right = pow(2,height) - 1;
       while (left <= right) {
            int mid = left + (int)((right-left)/2);
            if (exist(mid, height, root)) {
                left = mid + 1;
            } else {
                right = mid -1;
            }
       }

        return pow(2, height) - 1 + left;
   }
};

```