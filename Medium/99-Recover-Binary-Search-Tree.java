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
    private TreeNode first = null;
    private TreeNode second = null;
    private TreeNode prev = new TreeNode(Integer.MIN_VALUE);

    // In-order traversal to find the two swapped nodes
    private void inorder(TreeNode root) {
        if (root == null) return;
        
        // Traverse the left subtree
        inorder(root.left);
        
        // Find the first and second nodes that are out of order
        if (first == null && prev.val > root.val) {
            first = prev;
        }
        if (first != null && prev.val > root.val) {
            second = root;
        }
        
        // Update the previous node
        prev = root;
        
        // Traverse the right subtree
        inorder(root.right);
    }

    public void recoverTree(TreeNode root) {
        inorder(root);
        
        // Check if both first and second nodes are identified before swapping
        if (first != null && second != null) {
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }
    }
}
