// Copyright 2021 NNTU-CS
int binarySearch(int *arr, int l, int r, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return -1;
}

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    
    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == value) {
      
            int left_val = arr[left];
            int right_val = arr[right];
        
            int left_c = 1;
            while (left + 1 < right && arr[left + 1] == left_val) {
                left_count++;
                left++;
            }
            
   
            int right_c = 1;
            while (right - 1 > left && arr[right - 1] == right_val) {
                right_count++;
                right--;
            }
           
            if (left_val == right_val) {
                count += (left_c * (left_c - 1)) / 2;
            } else {
                count += left_c * right_c;
            }
            
            left++;
            right--;
        }
        else if (sum < value) {
            left++;
        }
        else {
            right--;
        }
    }
    
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        if (target < 0) continue;
        int j = binarySearch(arr, i + 1, len - 1, target);
        if (j != -1) {
            count++;
            int k = j + 1;
            while (k < len && arr[k] == target) {
                count++;
                k++;
            }
            k = j - 1;
            while (k > i && arr[k] == target) {
                count++;
                k--;
            }
        }
    }
    
    return count;
}
