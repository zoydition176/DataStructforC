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


// 7 .  8


/*
给定一个正整数数组 nums。

找出该数组内乘积小于 k 的连续的子数组的个数。

输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。

*/
int numSubarrayProductLessThanK(int *nums, int numsSize, int k)
{
    int l = 0;//数组左数下标
    int r = 0;//数组右数下标
    int res = 0;
    if (numsSize == 0 || k <= 1)
    {
        return 0;
    }
    int sum = nums[0];
    while (l < numsSize)
    {
        while (sum < k)
        {
            res += (r - l) + 1;
            r++;
            if (r == numsSize)
            {
                return res;
            }
            sum =sum * nums[r];
        }
        sum = sum/nums[l];
        l++;
    }
    return res;
}




// 三数之和的最接近值
int cmp(int *a, int *b)
{
    return *a - *b;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
    int i = 0;
    int j = 10000;
    int temp = 0;
    int res;
    int left = 0;
    int right = numsSize - 1;
    int mid;
    int k = 1;
    if (numsSize == 3)
    {
        res = nums[0] + nums[1] + nums[2];
        return res;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    while (left < numsSize - 2)
    {
        mid = left + 1;
        while (mid < right)
        {
            temp = nums[left] + nums[right] + nums[mid];
            if (temp > target)
            {
                i = temp - target;
                k = 1;
                right--;
            }
            else
            {
                i = target - temp;
                k = 0;
                mid++;
            }
            if (i == 0)
            {
                return temp;
            }
            j = i < j ? i : j;
        }
        left++;
    }
    if (k)
    {
        return target + j;
    }
    else
    {
        return target - j;
    }
}

// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *p, *q, *dev;
    dev = (struct ListNode *)malloc(sizeof(struct ListNode));
    dev->val = 0;
    dev->next = head; //可能出现很短的链表，创建一个新的节点，该节点位于head之前
    p = dev;
    q = dev;
    int count = 0;
    while (p)
    { //双指针，扫描完链表最后的差值就是要截断的部分
        count++;
        p = p->next;
        if (count > n + 1)
        {
            q = q->next;
        }
    }
    q->next = q->next->next; //删除倒数第n个节点
    return dev->next;
}

int mySqrt(int x) //求开方
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

// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1){
        return l2;
    }    
    if (!l2){
        return l1;
    }     
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *t = head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            t->next = l1;
            l1 = l1->next;
        }
        else
        {
            t->next = l2;
            l2 = l2->next;
        }
        t = t->next;
    }
    if (l1){
        t->next = l1;
    }else if (l2){
        t->next = l2;
    }   
    return head->next;
}

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。
*/
int searchInsert(int *nums, int numsSize, int target)
{
    int low = 0;
    int high = numsSize - 1;
    int mid = 0;

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

