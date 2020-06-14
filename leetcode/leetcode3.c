#include <stdio.h>
#include <stdlib.h>
int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main()
{
    return 1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i;
    int n = 2;
    int *c = (int *)malloc(sizeof(int) * n);
    if (c == NULL)
    {
        printf("内存分配不成功！\n");
    }
    else
    {
        for (i = 0; i < numsSize; i++)
        {
            for (int j = i + 1; j < numsSize; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    c[0] = i;
                    c[1] = j;
                    *returnSize = 2;
                    return c;
                }
            }
        }
    }
    return 0;
}

/*
var lengthOfLongestSubstring = function(s)
{
    var k = 0;
    for (let i = 0; i < s.length; i++)
    {
        var b = [];
        b.push(s[i]);
        for (var j = i + 1; s[i] != s[j] && j < s.length; j++)
        {
            if (!b.includes(s[j]))
            {
                b.push(s[j]);
            }
            else
            {
                break;
            }
        }
        if (k < b.length)
        {
            k = b.length;
        }
    }
    return k;
};
*/