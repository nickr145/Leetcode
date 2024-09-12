/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private boolean isValidBSTHelper(TreeNode node, Integer min, Integer max) {
        // Check if the current node 
        if (node == null) return true;
        
        // Check if current node violates the BST property
        if ((min != null && node.val <= min) || (max != null && node.val >= max)) return false;
        
        // Recursively check the left and right subtrees with updated min and max values
        return isValidBSTHelper(node.left, min, node.val) && 
               isValidBSTHelper(node.right, node.val, max);
    }

    public boolean isValidBST(TreeNode root) {
        return isValidBSTHelper(root, null, null);
    }
}
