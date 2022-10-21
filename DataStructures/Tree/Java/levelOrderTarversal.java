//  Code to return the level order traversal of its nodes' values, given the root of a binary tree.

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> fin = new LinkedList<List<Integer>>();
        if (root == null) {
            return fin;
        }
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);

        while (!q.isEmpty()) {
            List<Integer> l1 = new LinkedList<>();
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode node = q.peek();
                l1.add(q.peek().val);
                q.remove();
                if (node.left != null) {
                    q.add(node.left);
                }
                if (node.right != null) {
                    q.add(node.right);
                }
            }
            fin.add(l1);
        }

        return fin;
    }
}