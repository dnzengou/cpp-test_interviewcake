#include <iostream>
#include <vector>
using namespace std;
// Using an array to store each digit of a number, add one to the final digit
int main()
{
    int arr[] = {3, 5, 8};
    int arrSize = (sizeof(arr)/sizeof(arr[0])) - 1;
    vector <int> result;
    int carry = 1;
    int sumHolder = 0;

    for(int i=arrSize; i >= 0; i--)
    {
      sumHolder = arr[i] + carry;
      if(sumHolder >= 10)
      {
        result.push_back(sumHolder % 10);
        carry = 1;
      }
      else
      {
          result.push_back(sumHolder);
          carry = 0;
      }
    }
    if (carry == 1)
    {
      result.push_back(carry);
      carry =0;
    }
    for (int i=result.size()-1; i >=0; i--)
    {
      cout << result.at(i);
    }
    return 0;
}
