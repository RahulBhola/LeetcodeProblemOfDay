import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int leftValue = 0;

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            boolean firstInLevel = true;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode node = queue.poll();

                if (firstInLevel) {
                    leftValue = node.val;
                    firstInLevel = false;
                }
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
        }
        return leftValue;
    }
}

public class BottomLeftTreeValue {
    public static TreeNode newNode(int val) {
        return new TreeNode(val);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        TreeNode root1 = newNode(2);
        root1.left = newNode(1);
        root1.right = newNode(3);
        System.out.println("Output for Example 1: " + solution.findBottomLeftValue(root1)); // Output: 1

        // Example 2
        TreeNode root2 = newNode(1);
        root2.left = newNode(2);
        root2.right = newNode(3);
        root2.left.left = newNode(4);
        root2.right.left = newNode(5);
        root2.right.right = newNode(6);
        root2.right.left.left = newNode(7);
        System.out.println("Output for Example 2: " + solution.findBottomLeftValue(root2)); // Output: 7
    }
}
