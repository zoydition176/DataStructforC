#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

// 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int a[nums1Size + nums2Size];
    int index = 0, index1 = 0, index2 = 0;
    int ave = (nums1Size + nums2Size) / 2;
    for (int i = 0; i <= ave; i++)
    {

        if (index1 < nums1Size && index2 < nums2Size)// 非空数组合并，两个数组共同长度的部分
        {
            if (nums1[index1] <= nums2[index2])//每一位数组元素比较，小的数组元素进到后一位继续比较
            {
                a[index] = nums1[index1];
                index++;
                index1++;
            }
            else
            {
                a[index] = nums2[index2];
                index++;
                index2++;
            }
        }
        else if (index1 < nums1Size) // 第一个数组稍长  第二个数组排完了 将第一个数组剩下的部分直接放入合并的大数组中
        {
            a[index] = nums1[index1];
            index++;
            index1++;
        }
        else
        {
            a[index] = nums2[index2];
            index++;
            index2++;
        }
    }
    if ((nums2Size + nums1Size) % 2 != 0)// 若合并的大数组长度为奇数 直接得出中位值
    {
        return (double)a[ave];
    }else{
        return ((double)a[ave] + (double)a[ave - 1]) / 2;
    }   
}

/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

*/
int reverse(int x)
{
    long result = 0;
    while (x != 0)
    {
        result = result * 10 + x % 10;
        x = x / 10;
    }
    if (result != (int)result)
    {
        return 0;
    }
    return (int)result;
}



bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    long y = x;
    long res = 0;
    while (x != 0)
    {
        res = res * 10 + x % 10;
        x = x / 10;
    }
    if (res == y)
    {
        return true;
    }
    else
    {
        return false;
    }
}