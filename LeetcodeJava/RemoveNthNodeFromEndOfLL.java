class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class RemoveNthNodeFromEndOfLL {
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || n <= 0) // Handling edge cases
            return null;

        ListNode dummy = new ListNode(0); // Dummy node to handle cases where the head needs to be removed
        dummy.next = head;

        ListNode fast = dummy;
        ListNode slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            if (fast == null)
                return null; // Out of range
            fast = fast.next;
        }

        // Move fast to the end, maintaining the gap of n between fast and slow
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        // Remove the nth node from the end
        // ListNode toDelete = slow.next;
        slow.next = slow.next.next;

        return dummy.next; // Return the head of the modified list
    }

    // Function to print the linked list
    public static void printList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Example usage
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);
        head1.next.next.next.next = new ListNode(5);

        System.out.print("Original list: ");
        printList(head1);

        int n = 2;
        head1 = removeNthFromEnd(head1, n);

        System.out.print("List after removing " + n + "th node from end: ");
        printList(head1);
    }
}
