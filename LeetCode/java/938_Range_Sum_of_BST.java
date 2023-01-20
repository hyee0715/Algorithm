import javax.swing.tree.TreeNode;

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
    int check(TreeNode root, int low, int high) {
        if (root == null) {
            return 0;
        }

        if (root.val >= low && root.val <= high) {
            return check(root.left, low, high) + root.val + check(root.right, low, high);
        } else {
            return check(root.left, low, high) + check(root.right, low, high);
        }
    }

    public int rangeSumBST(TreeNode root, int low, int high) {
        int answer = check(root, low, high);

        return answer;
    }
}