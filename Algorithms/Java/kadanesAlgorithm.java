import java.util.*;

//Kadane's algorithm is used to find the maximum subarray sum within an array of numbers. 
public class kadanesAlgorithm {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array:");
        int n = sc.nextInt();
        System.out.print("Enter the elements of the array:");
        int arr[] = new int[n];

        // Input: Read elements into the array
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int x = maxSubarray(arr);
        System.out.println("Largest Contiguous sum is : " + x);
    }

    public static int maxSubarray(int arr[]) {
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;

        // Iterate through the array to find the maximum sum
        for (int i = 0; i < arr.length; i++) {
            currSum += arr[i];
            
            // Update maxSum if a larger sum is found
            if (maxSum < currSum) {
                maxSum = currSum;
            } else if (currSum < 0) {
                // Reset the current sum to 0 if it becomes negative
                currSum = 0;
            }
        }

        return maxSum; 
    }
}


/*
Ex:input arr = {-1, 2, 3, -4, 2, 1}

Enter size of array:6
Enter the element of array:-1 2 3 -4 2 1

OUTPUT:
Largest contiguous subarray sum is : 4

 */