import javax.swing.tree.TreeNode;
import java.util.HashSet;

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
    private boolean check(TreeNode root, int k, HashSet<Integer> hs) {
        if (root == null) {
            return false;
        }

        if (hs.contains(root.val)) {
            return true;
        }

        hs.add(k - root.val);
        return check(root.left, k, hs) || check(root.right, k, hs);
    }

    public boolean findTarget(TreeNode root, int k) {
        HashSet<Integer> hs = new HashSet<>();

        return check(root, k, hs);
    }
}