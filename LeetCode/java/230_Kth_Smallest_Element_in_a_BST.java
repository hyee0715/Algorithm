import javax.swing.tree.TreeNode;
import java.util.PriorityQueue;

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
    private PriorityQueue<Integer> check(TreeNode root, PriorityQueue<Integer> low) {
        if (root == null) {
            return low;
        }

        low.add(root.val);
        check(root.left, low);
        check(root.right, low);

        return low;
    }

    public int kthSmallest(TreeNode root, int k) {
        PriorityQueue<Integer> low = new PriorityQueue<>();

        check(root, low);

        int answer = 0;

        for (int i = 0; i < k; i++) {
            answer = low.poll();
        }

        return answer;
    }
}