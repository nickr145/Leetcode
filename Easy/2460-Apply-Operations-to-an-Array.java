class Solution {
    public static void moveElementsToEnd(int[] arr, int numToMove) {
        int n = arr.length;
        int index = 0;
        // Step 1: Move all elements that are not equal to elementToMove to the front
        for (int i = 0; i < n; i++) {
            if (arr[i] != numToMove) {
                arr[index++] = arr[i];
            }
        }
        // Step 2: Fill the rest of the array with the elementToMove
        while (index < n) {
            arr[index++] = numToMove;
        }
    }

    public int[] applyOperations(int[] nums) {
        for (int i = 0; i < nums.length-1; ++i) {
            if (nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        moveElementsToEnd(nums,0);

        return nums;
    }
}
