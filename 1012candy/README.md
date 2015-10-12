There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

----
1. 开始的时候把题目想简单了，我以为测试数据应该是这样的{1, 3, 4, 2, 4},我一想这不就跟最大子列和一样吗，于是我就设定一个temp值，遇到下一个值大于前一个值就加一，然后sum+=temp，遇到变小则temp置为1.所以分到的糖果数应该是1+2+3+1+2.
2. 实际是不可行的，因为还有{1, 3, 4, 3, 2, 1}这种情况，按上面的思路4后面的3只分到1个糖果，然而由于3后面还有比3小的2，最终是1+2+3+1+1+1，这样就不符合题意了。我又想，对其正向逆向各扫一遍，逆向的时候temp置为0，这样正向扫完是1+2+3+1+1+1，逆向是0+0+3+2+1+0，但这样4那个位置被加了两次，最终是15，而我们手算可得应该是14，还是不行。
3. 实在想不出来，最后还是看了戴方勤的LeetCode题解，他把这个temp弄成了数组，也是来回扫，但是只取扫出来的最高值。
 
```
class Solution {
public:
    int candy(vector<int>& ratings) {
        int temp = 0,
            n = ratings.size();
        vector<int> temp_arr(n);
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                temp += 1;
            }
            else
                temp = 0;
            temp_arr[i] = temp;
        }
        temp = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                temp += 1;
            }
            else
                temp = 0;
            temp_arr[i - 1] = temp > temp_arr[i - 1] ? temp : temp_arr[i - 1];
        }
        return accumulate(&temp_arr[0], &temp_arr[0] + n, n);
    }
};
```
