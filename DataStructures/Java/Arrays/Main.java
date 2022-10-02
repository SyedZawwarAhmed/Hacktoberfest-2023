package Arrays;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = { 4, 9, -12, 31, 6, 78 };

        // Array traversal
        traverse(arr);

        // max & min element in the array
        int max = maxInArray(arr);
        int min = minInArray(arr);
        System.out.println("\n\nMAX: " + max + " | MIN: " + min);

        // insertion operation
        System.out.println("\nBefore Insertion");
        System.out.println(Arrays.toString(arr));
        insert(arr, 3, 99);
        System.out.println("\nAfter Insertion");
        System.out.println(Arrays.toString(arr));

        // deletion operation
        System.out.println("\nBefore Deletion");
        System.out.println(Arrays.toString(arr));
        delete(arr, 2);
        System.out.println("\nAfter Deletion");
        System.out.println(Arrays.toString(arr));
    }

    static void traverse(int[] arr) {
        int size = arr.length;

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    static int maxInArray(int[] arr) {
        int max = Integer.MIN_VALUE;

        for (int el : arr) {
            max = Math.max(max, el);
        }

        return max;
    }

    static int minInArray(int[] arr) {
        int min = Integer.MAX_VALUE;

        for (int el : arr) {
            min = Math.min(min, el);
        }

        return min;
    }

    static void insert(int[] arr, int pos, int el) {
        int idx = pos - 1;
        int size = arr.length;

        for (int i = size - 1; i > idx; i--) {
            arr[i] = arr[i - 1];
        }

        arr[idx] = el;
    }

    static void delete(int[] arr, int pos) {
        int idx = pos - 1;
        int size = arr.length;

        for (int i = idx; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        arr[size - 1] = 0;
    }
}
