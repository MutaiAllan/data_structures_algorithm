#include <iostream>

// gets the sum of the integers 
int summation(int arr[], int x) {
  int total = 0;
  for (int i = 0; i < x; i++) {
    total += arr[i];
  }
  return total;
}

// obtains the largest integer in the array
int maximum(int arr[], int x) {
  int max = arr[0];
  for (int i = 1; i < x; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}


int main() {

  int x;
  std::cout << "Enter the length of the array: ";
  std::cin >> x;

  int arr[x];
  for (int i = 0; i < x; i++) {
    std::cout << "Enter the numbers : ";
    std::cin >> arr[i];
  }

  int sum = summation(arr, x);
  std::cout << "Summation: " << sum << "\n";

  int max = maximum(arr, x);
  std::cout << "Maximum: " << max;

  return 0;
}