/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 */
var Solution = function (head) {
    this.head = head;
};

// USING RESERVOIR SAMPLING
/**
 * RESERVOIR SAMPLING is  a family of randomized algorithms for randomly choosing k samples 
 * from a list of n items, where n is a either a very large or an unknown number.
 */


/**
 * @return {number}
 */
Solution.prototype.getRandom = function () {
    var curr = this.head;
    let index = 1;
    let res = 0;

    while (curr != null) {
        if (Math.random() < (1.0 / index)) {
            // take this value
            res = curr.val;
        }
        index++;
        curr = curr.next;
    }
    return res;
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(head)
 * var param_1 = obj.getRandom()
 */