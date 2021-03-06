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

//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
bool isPalindrome(int x)//非字符串法
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

/*
罗马数字转整数
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
*/
int romanToInt(char *s)
{
    int num = 0;
    while (*s)
    {
        if (*s == 'V')
            num += 5;
        else if (*s == 'L'){
            num += 50;
        }
           
        else if (*s == 'D'){
            num += 500;
        }
        else if (*s == 'M'){
            num += 1000;
        }
            
        else if (*s == 'I'){
            num = (*(s + 1) == 'V' || *(s + 1) == 'X') ? num - 1 : num + 1;
        }
           
        else if (*s == 'X'){
            num = (*(s + 1) == 'L' || *(s + 1) == 'C') ? num - 10 : num + 10;
        }
            
        else{
            num = (*(s + 1) == 'D' || *(s + 1) == 'M') ? num - 100 : num + 100;
        }        
        s++;
    }
    return num;
}

char *longestCommonPrefix(char **strs, int strsSize)//字符串数组最长字符串公共前缀
{
    if (strsSize == 0)
    {
        return "";
    }
    char t;
    int p = 0;
    int n = 0;
    int i = 0;
    while (strs[0][n] != '\0')
    {
        t = strs[0][n];
        for (i = 1; i < strsSize; i++)
        {
            if (strs[i][n] != t || n == strlen(strs[i]))
            {
                strs[0][n] = '\0';
                return strs[0];
            }
        }
        n++;
    }
    return strs[0];
}

bool isValid(char *s)//符号匹配
{
    if (strlen(s) == 0)
    {
        return true;
    }
    char st[strlen(s)];
    int a1 = -1;
    int res = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            a1++;
            st[a1] = '(';
        }
        else if (s[i] == '[')
        {
            a1++;
            st[a1] = '[';
        }
        else if (s[i] == '{')
        {
            a1++;
            st[a1] = '{';
        }
        else if (s[i] == ')')
        {
            if (a1 < 0)
            {
                return false;
            }
            if (st[a1] == '(')
            {
                a1--;
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '}')
        {
            if (a1 < 0)
            {
                return false;
            }
            if (st[a1] == '{')
            {
                a1--;
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (a1 < 0)
            {
                return false;
            }
            if (st[a1] == '[')
            {
                a1--;
            }
            else
            {
                return false;
            }
        }
    }
    if (a1 < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char *longestPalindrome(char *s)//最长回文子串
{
    int N = strlen(s);
    int start = 0;
    int len = 0; // N 字符串长度， start 子串起始位置， len 子串长度
    for (int i = 0; i < N; i++)
    { // 如果是奇数长度的回文子串
        int left = i - 1, right = i + 1;
        while (left >= 0 && right < N && s[left] == s[right])
        {
            left--;
            right++; // 以 i 为中心，向两侧延伸，直到不再满足回文
        }            // left+1 ~ right-1 则为以i为中心的最大回文子串
        if (right - left - 1 > len)
        { // 若更长，则保存该子串信息
            start = left + 1;
            len = right - left - 1;
        }
    }
    for (int i = 0; i < N; i++)
    {                                // 如果是偶数长度的回文子串
        int left = i, right = i + 1; // 以 i+0.5 为中心，向两侧延伸
        while (left >= 0 && right < N && s[left] == s[right])
        {
            left--, right++;
        }
        if (right - left - 1 > len)
        {
            start = left + 1;
            len = right - left - 1;
        }
    }
    s[start + len] = '\0'; // 修改字符串尾
    return (s + start);
}

int searchInsert(int *nums, int numsSize, int target) 
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
{
    int low = 0;
    int high = numsSize - 1;
    int mid = 0;//中位下标 二分查找

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (target > nums[mid])
        {
            low = mid + 1;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else if (target == nums[mid])
        {
            return mid;
        }
    }

    return low;
}

/*
给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
*/
char *countAndSay(int n) //输出外观数列
{
    char *mark = (char *)malloc(sizeof(char) * 100);//尽可能大的空间
    char *temp = (char *)malloc(sizeof(char) * 100);
    mark[0] = '1';
    mark[1] = '\0'; //结束标志
    int i = 0;
    int count = 0;
    int j = 0;
    char *p;
    char key = '\0';
    for (i = 1; i < n; i++)
    {
        j = 0;
        key = mark[0];//声明key为第一个关键字
        count = 0;
        p = mark;
        while (*p != '\0')
        {
            if (*p == key) //同样数字的情况下，直接计数
                count++;
            else
            {
                temp[j++] = count + '0'; //先存计数器
                count = 1;
                temp[j++] = key; //再存关键字
                key = *p;
            }
            p++;
        }
        temp[j++] = count + '0'; //先存计数器
        temp[j++] = key;         //再存关键字
        temp[j] = '\0';
        strcpy(mark, temp);//复制给新生成的字符串继续计数
    }
    return mark;
}

//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
int maxSubArray(int *nums, int numsSize)
{
    int i = 0;
    int j = 0;
    int m = nums[0];
    int temp = 0;

    for (i = 0; i < numsSize; i++)
    {
        temp = 0;
        for (j = i; j < numsSize; j++)//缩小循环相加 全部求一遍数组和 取最小
        {
            temp += nums[j];
            if (temp > m)
            {
                m = temp;
            }
        }
    }

    return m;
}