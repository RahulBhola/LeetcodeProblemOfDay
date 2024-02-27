class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

class Solution {
    int maxDiameter = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;
        depth(root);
        return maxDiameter;
    }

    private int depth(TreeNode node) {
        if (node == null)
            return 0;

        int leftDepth = depth(node.left);
        int rightDepth = depth(node.right);

        maxDiameter = Math.max(maxDiameter, leftDepth + rightDepth);

        return Math.max(leftDepth, rightDepth) + 1;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        // Example 1:
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(3);
        root1.left.left = new TreeNode(4);
        root1.left.right = new TreeNode(5);

        System.out.println("Example 1: " + sol.diameterOfBinaryTree(root1));

        // Example 2:
        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);

        System.out.println("Example 2: " + sol.diameterOfBinaryTree(root2));
    }
}
