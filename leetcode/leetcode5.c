#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    return 1;
}

// 旋转链表
struct ListNode
{
    int val;
    struct ListNode *next;
};
// 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == 0)
    {
        return 0;
    }
    short length = 1;
    struct ListNode *tmp = head;
    while (tmp->next != 0)
    {
        tmp = tmp->next;
        length++;
    }
    tmp->next = head; //链接头尾链表节点
    k = length - k % length;
    for (int i = k; k > 0; k--)
    {
        tmp = tmp->next;
    }
    head = tmp->next; //返回对应位置节点 重置为头结点
    tmp->next = 0;
    return head;
}

int mySqrt(int x) //二分查找求开方
{
    int mid = 0;
    int min = 0;
    int max = x;
    if (x < 0)
    {
        return -1;
    }
    if (x <= 1)
    {
        return x;
    }
    while ((min + 1) < max)
    {
        mid = min + (max - min) / 2;

        if ((x / mid) < mid)
        {
            max = mid;
        }
        else
        {
            min = mid;
        }
    }

    return min;
}

// 求完美数
//对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。

//给定一个 整数 n， 如果他是完美数，返回 True，否则返回 False

bool checkPerfectNumber(int num)
{
    if (0 == num || (num & 1))
    {
        return 0;
    }
    int i = 1;
    int sum = 1;
    int sq = sqrt(num); // 利用开方。考虑不用开方的方法
    for (i = 2; i < sq; ++i)
    {
        if (num % i == 0)
        {
            sum += i + num / i;
        }
    }

    if (num % sq == 0)
    {
        if (num / sq == sq)
        {
            sum = sum + sq;
        }
        else
        {
            sum = sum + (sq + num / sq);
        }
    }
    if (sum == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
*/
bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    int count = 0; //最大可以种植量计数
    if (flowerbedSize == 1)
    {
        if (flowerbed[0] == 0)
        {
            count = 1;
        }
    }
    else if (flowerbedSize == 2)
    {
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            count = 1;
        }
    } // 排除两种特殊情况
    else
    {
        for (int i = 0; i < flowerbedSize; i++)
        {
            if (i == 0)
            {
                if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                {
                    count++;
                    flowerbed[i] = 1;
                }
            }
            else if (i == flowerbedSize - 1)
            { //最后一个元素
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
                {
                    count++;
                    flowerbed[i] = 1;
                }
            }
            else
            {
                if (flowerbed[i] == 0)
                {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                    {
                        count++;
                        flowerbed[i] = 1;
                    }
                }
            }
        }
    }
    return (count > n);
}

/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
*/

bool validPalindrome(char *s) //判断非回文字符串能否成为回文字符串
{
    int length = strlen(s);
    int low = 0, high = length - 1; //字符串头尾的位置，两边逼近扫描字符串
    int posi, posj;                 //删除的元素个数
    while (low < high)
    {
        if (s[low] != s[high]) //两个数不相等,删除一个数
        {
            if ((high - low) == 1)
            {
                return true;
            }
            posi = low + 1, posj = high; //删除左边的
            while (posi < posj)
            {
                if (s[posi] != s[posj])
                {
                    break;
                }
                posi++;
                posj--;
            }

            if (posi == posj || posi > posj)
            {
                return true;
            }
            posi = low, posj = high - 1; //删除左边的
            while (posi < posj)
            {
                if (s[posi] != s[posj])
                {
                    break;
                }
                posi++;
                posj--;
            }
            if (posi == posj || posi > posj)
            {
                return true;
            }

            return false;
        }
        while (low < high && s[low] == s[high])
        {
            low++;
            high--;
        }
    }
    return true;
}