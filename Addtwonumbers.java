import java.util.Scanner;

// Definition for singly-linked list node
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}
public class Addtwonumbers{

    // Function to add two numbers represented as linked lists
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = null;
        ListNode current = null;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int sum = carry;
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            carry = sum / 10;
            sum %= 10;

            ListNode newNode = new ListNode(sum);

            if (result == null) {
                result = newNode;
                current = result;
            } else {
                current.next = newNode;
                current = current.next;
            }
        }

        return result;
    }

    // Function to print a linked list
    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " -> ");
            node = node.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x, y;

        // Input for first linked list
        System.out.print("Enter the number of elements for the first linked list: ");
        x = scanner.nextInt();
        ListNode l1 = null;
        System.out.println("Enter the elements for the first linked list in reverse order:");
        for (int i = 0; i < x; i++) {
            int val = scanner.nextInt();
            ListNode node = new ListNode(val);
            node.next = l1;
            l1 = node;
        }

        // Input for second linked list
        System.out.print("Enter the number of elements for the second linked list: ");
        y = scanner.nextInt();
        ListNode l2 = null;
        System.out.println("Enter the elements for the second linked list in reverse order:");
        for (int i = 0; i < y; i++) {
            int val = scanner.nextInt();
            ListNode node = new ListNode(val);
            node.next = l2;
            l2 = node;
        }

        // Add the two numbers represented by l1 and l2
        ListNode sumList = addTwoNumbers(l1, l2);

        // Print the resulting sum
        System.out.println("Resulting sum of the two numbers:");
        printList(sumList);

        // No need to free memory explicitly in Java due to automatic garbage collection
    }
}
