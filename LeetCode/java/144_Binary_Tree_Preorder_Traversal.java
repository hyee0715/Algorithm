import javax.swing.tree.TreeNode;
import java.util.ArrayList;
import java.util.List;

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
    public List<Integer> travel(TreeNode root, List<Integer> answer) {
        if (root == null) {
            return answer;
        }

        answer.add(root.val);

        travel(root.left, answer);
        travel(root.right, answer);

        return answer;
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> answer = travel(root, new ArrayList<>());

        return answer;
    }
}