#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    return 1;
}
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
int lengthOfLongestSubstring(char *s)
{
    int i = 0;
    int j = 0;
    int k = strlen(s);
    int max = 0;
    for (i = 0; i < k; i++)
    {
        for (int x = j; x < i; x++)
        {
            if (s[x] == s[i])
            {
                if (max < i - j)
                {
                    max = i - j;
                }
                j = x + 1;
            }
        }
        if (max < i - j + 1)
        {
            max = i - j + 1;
        }
    }
    return max;
}