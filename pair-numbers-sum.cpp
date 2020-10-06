#include <iostream>
#include <cmath>
using namespace std;
// Find a pair of numbers in an array that adds to a given sum
int main()
{
    int arr[] = {2, 3, 6, 8};
    int sum = 5;
    int arrSize = (sizeof(arr)/sizeof(arr[0])) - 1;
    int index = 0;
    int num1 = arr[index];

    while(index <= arrSize && num1 < sum)
    {
      int i = index + 1;
      while(i < arrSize && ((sum - num1) >= arr[i]))
      {
        if (num1 + arr[i] == sum)
        {
          cout << num1 << " " << arr[i] << endl;
          i = arrSize;
        }
        else
        {
          i++;
        }
      }
      index++;
      num1 = arr[index];
    }
    return 0;
}
