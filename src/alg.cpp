// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}


// Функция countPairs2: поиск с двух концов (упрощенный) (O(n))
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        (arr[left] + arr[right] == value) ? (count++, left++, right--) :
        (arr[left] + arr[right] < value) ? left++ : right--;
    }
    return count;
}

// Функция countPairs3: бинарный поиск (упрощенный) (O(n log n))
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int left = i + 1, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == value - arr[i]) {
                count++;
                break;
            } else if (arr[mid] < value - arr[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
