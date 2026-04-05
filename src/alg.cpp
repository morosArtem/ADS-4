// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k++;
        while (j + 1 < len && arr[j] == arr[j + 1]) j++;
      }
    }
    while (i + 1 < len && arr[i] == arr[i + 1]) i++;
  }
  return k;
}

int countPairs3(int* arr, int len, int value) {
  int k = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      k++;
      left++;
      right--;
      while (left < right && arr[left] == arr[left - 1]) left++;
      while (left < right && arr[right] == arr[right + 1]) right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return k;
}

int countPairs2(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;

    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int found = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        found = mid;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (found != -1) {
      k++;
    }
  }
  return k;
}
