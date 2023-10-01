/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {

        if(head == null){
            return null;
        }

        ListNode oddHead = head;
        ListNode evenHead = head.next;

        ListNode odd = head;
        ListNode even = head.next;

        

        while((even != null) && (even.next != null)){

            odd.next = odd.next.next;
            even.next = even.next.next;

            odd = odd.next;
            even = even.next;
        }


        odd.next = evenHead;

        return head;
    }
}
