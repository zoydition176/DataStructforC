#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    return 1;
}

char *longestCommonPrefix(char **strs, int strsSize) //字符串数组最长字符串公共前缀
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

bool isValid(char *s) //符号匹配
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

char *longestPalindrome(char *s) //最长回文子串
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
    int mid = 0; //中位下标 二分查找

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
    char *mark = (char *)malloc(sizeof(char) * 100); //尽可能大的空间
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
        key = mark[0]; //声明key为第一个关键字
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
        strcpy(mark, temp); //复制给新生成的字符串继续计数
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
        for (j = i; j < numsSize; j++) //缩小循环相加 全部求一遍数组和 取最小  待优化。。
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


// 计算行列式上三角元素的和
int sumFun(int *p,int n){
    int res = 0;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            res = res + p[i*n+j];//二维数组用一维数组的方式表达
        }
    }
    return res;
}

// 计算行列式上三角元素的和
int sumSys(int *p, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res + p[i * n + i];
    }
    for (int j = n - 1; j >= 0; j--)
    {
        res = res + p[j * n + (n - j)];
    }
    if(n%2==0){
        return res;
    }else{
        return res - p[((n / 2) + 1) * (n + 1)];
    }
    
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
    if (head == 0){
        return 0;
    }     
    short length = 1;
    struct ListNode *tmp = head;
    while (tmp->next != 0)
    {
        tmp = tmp->next;
        length++;
    }
    tmp->next = head;//链接头尾链表节点
    k = length - k % length;   
    for(int i = k;k>0;k--){
        tmp = tmp->next;
    }
    head = tmp->next;//返回对应位置节点 重置为头结点
    tmp->next = 0;
    return head;
}

int mySqrt(int x)//二分查找求开方
{
    int mid = 0;
    int min = 0;
    int max = x;
    if (x < 0){
        return -1;
    }
    if (x <= 1){
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
    if (0 == num || (num & 1)){
        return 0;
    }      
    int i = 1;
    int sum = 1;
    int sq = sqrt(num);// 利用开方。考虑不用开方的方法
    for (i = 2; i < sq; ++i){
        if (num % i == 0){
            sum += i + num / i;
        }       
    }
        
    if (num % sq == 0){
        if (num / sq == sq)
        {
            sum = sum + sq;
        }else{
            sum = sum +  (sq + num / sq);
        }
    }       
    if(sum == num){
        return 1;
    }else{
        return 0;
    }
}

/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
*/
bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{ 
    int count = 0;//最大可以种植量计数
    if (flowerbedSize == 1)
    { 
        if (flowerbed[0] == 0){
            count = 1;
        }            
    }
    else if (flowerbedSize == 2)
    { 
        if (flowerbed[0] == 0 && flowerbed[1] == 0){
            count = 1;
        }     
    }// 排除两种特殊情况
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
    return (count>n);
}


/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
*/

bool validPalindrome(char *s)//判断非回文字符串能否成为回文字符串
{
    int length = strlen(s);
    int low = 0, high = length - 1; //字符串头尾的位置，两边逼近扫描字符串
    int posi, posj;                 //删除的元素个数
    while (low < high)
    {
        if (s[low] != s[high]) //两个数不相等,删除一个数
        {
            if ((high - low) == 1){
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

            if (posi == posj || posi > posj){
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
            if (posi == posj || posi > posj){
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