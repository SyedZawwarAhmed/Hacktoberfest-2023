// returns index of the target, in array else -1.
// Binary Search assumes that the input array is sorted.
function binarySearch(array, target) {
    let left = 0;
    let right = array.length - 1;

    while (left <= right) {
        let mid = left + Math.floor((right - left) / 2);

        if (array[mid] === target) 
            return mid;

        if (array[mid] > target) 
            right = mid - 1;
        else
            left = mid + 1;        
    }

    return -1;
}