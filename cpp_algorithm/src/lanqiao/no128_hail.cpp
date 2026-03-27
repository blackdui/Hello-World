// https://www.lanqiao.cn/problems/128/learning/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

bool is_prime(int num)
{
  return (num % 2 == 0) ? true : false;
}
int main()
{
  // 请在此输入您的代码
  long long  num;
  cin >> num;
  vector<long long> result;
  while (num != 1) {
    if (is_prime(num))
      num = num / 2;
    else
      num = num*3 + 1;
    result.push_back(num);
  }

  // for(auto num : result)
  // {
  //   cout << num << " ";
  // }
  
  int max = 1;
  for (int i = 0; i < result.size(); i++) {
    if (result[max] < result[i])
        max = i;
  }
  cout << result[max] << endl;
  return 0;
}
