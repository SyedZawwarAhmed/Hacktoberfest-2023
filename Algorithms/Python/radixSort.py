def radix_sort(arr):
    # Find the maximum number to determine the number of digits
    max_num = max(arr)
    # Get the number of digits in the maximum number
    num_digits = len(str(max_num))
    
    # Initialize the buckets for each digit (0-9)
    buckets = [[] for _ in range(10)]
    
    # Loop through each digit, from the least significant to the most significant
    for digit in range(num_digits):
        # Place each element in the appropriate bucket based on the current digit
        for num in arr:
            # Get the digit at the current position (from right to left)
            digit_at_pos = (num // 10**digit) % 10
            buckets[digit_at_pos].append(num)
        
        # Reconstruct the array from the buckets
        arr = [num for bucket in buckets for num in bucket]
        
        # Clear the buckets for the next iteration
        buckets = [[] for _ in range(10)]
    
    return arr

arr = [170, 45, 75, 90, 802, 24, 2, 66]

sorted_arr = radix_sort(arr)

print(sorted_arr)
