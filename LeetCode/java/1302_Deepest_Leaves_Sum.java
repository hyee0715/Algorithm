import javax.swing.tree.TreeNode;
import java.util.HashMap;
import java.util.Map;

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
    public int deepestLeavesSum(TreeNode root) {
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<>();

        check(root, map, 0);

        int maxNum = -1;

        for (int key : map.keySet()) {
            if (key > maxNum) {
                maxNum = key;
                answer = map.get(key);
            }
        }

        return answer;
    }

    private void check(TreeNode root, Map<Integer, Integer> map, int depth) {
        if (root == null) {
            return;
        }

        map.put(depth, map.getOrDefault(depth, 0) + root.val);

        check(root.left, map, depth + 1);
        check(root.right, map, depth + 1);
    }
}