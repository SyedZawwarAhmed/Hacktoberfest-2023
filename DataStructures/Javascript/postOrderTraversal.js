/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node|null} root
 * @return {number[]}
 */
var postorder = function (root) {
    const result = [];
    postOrderTraversal(root, result);
    return result;
};

function postOrderTraversal(root, arr) {
    if (!root) { return };
    if (root.children) {
        for (const child of root.children) {
            postOrderTraversal(child, arr);
        }
    }
    arr.push(root.val);
}