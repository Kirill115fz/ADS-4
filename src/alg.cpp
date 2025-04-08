// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    std::set<std::pair<int, int>> uniquePairs;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                uniquePairs.insert(std::make_pair(arr[i], arr[j]));
            }
        }
    }
    return uniquePairs.size();
}

int countPairs2(int *arr, int len, int value) {
    std::set<std::pair<int, int>> uniquePairs;
    int left = 0, right = len - 1;
    while (left < right) {
        if (arr[left] + arr[right] == value) {
            uniquePairs.insert(std::make_pair(arr[left], arr[right]));
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1]) {
                left++;
            }
            while (left < right && arr[right] == arr[right + 1]) {
                right--;
            }
        }
        else if (arr[left] + arr[right] < value) {
            left++;
        }
        else {
            right--;
        }
    }
    return uniquePairs.size();
}

int countPairs3(int *arr, int len, int value) {
    std::set<std::pair<int, int>> uniquePairs;
    for (int i = 0; i < len; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int left = i + 1, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == value - arr[i]) {
                uniquePairs.insert(std::make_pair(arr[i], arr[mid]));
                break;
            }
            else if (arr[mid] < value - arr[i]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return uniquePairs.size();
}
