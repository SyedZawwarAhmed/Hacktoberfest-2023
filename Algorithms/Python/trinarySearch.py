def trinary_search(array, key):
    """
    Perform trinary search to find the index of a key in a sorted array.
    Time Complexity: O(log3(n))        Space Complexity: O(1)
    Args:
    array (list): The sorted list to search within.
    key: The element to search for.

    Returns:
    int: The index of the key in the array if found, or -1 if not found.

    """
    left, right = 0, len(array) - 1  # Initialize left and right pointers

    while left <= right:
        # Calculate the two dividing points
        div1 = left + (right - left) // 3
        div2 = left + 2 * (right - left) // 3

        if array[div1] == key:
            return div1  # Key found at the first dividing point
        elif array[div2] == key:
            return div2  # Key found at the second dividing point

        # If the key is smaller than the element at div1, search in the first third
        if key < array[div1]:
            right = div1 - 1
        # If the key is larger than the element at div2, search in the last third
        elif key > array[div2]:
            left = div2 + 1
        # If the key is between the elements at div1 and div2, search in the middle third
        else:
            left = div1 + 1
            right = div2 - 1

    # Key not found in the array
    return -1
