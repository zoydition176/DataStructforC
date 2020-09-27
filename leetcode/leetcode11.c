#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define max(a,b) a>b?a:b
struct ListNode {
    int val;
    struct ListNode *next;
 };
 
/*
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
*/
bool isIsomorphic(char * s, char * t){
    int i;
    int x = strlen(s);
    int y = strlen(t);
    if(x!=y){
        return false;
    }
    int *a = (int *)malloc(sizeof(int) * 200);
    memset(a, -1, sizeof(int) * 200);
    // memset(b, 0, sizeof(int) * 200);

    for(i = 0;i < x;i++)
    {
        if(a[s[i]] == -1)//字符没有被使用的情况 就是没有出现重复字符 用-1代替asc码
        {
            for(int j = 0;j < 200;j++)
            {
                if(a[j] == t[i])
                    // a[s[i]] != t[i];
                    return false;
            }
            a[s[i]] = t[i];//建立一个对应关系
        }else
        {
            if(a[s[i]] != t[i])
                return false;
        }
    }
    return true;
}


/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。
*/

int maxProfit(int *prices, int pricesSize)
{
    int i;
    int min;
    int tmp;
    int res = 0;
    if (pricesSize == 0 || pricesSize == 1) {
        return 0;
    }
    min = prices[0];
    for (i = 1; i < pricesSize; i++) {
        // if(!prices[i]){
        //     return false;
        // }
        if (prices[i - 1] < min) {
            // min = prices[i];
            min = prices[i - 1];//min保存最小值
        }        
        tmp = prices[i] - min;
        if (tmp > res) {
            res = tmp;
        }
    }
    return res;
}

/*
你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。

给定一个数字 n，找出可形成完整阶梯行的总行数。

n 是一个非负整数，并且在32位有符号整型的范围内。
*/
int arrangeCoins(int n){
    if(n == 0)return 0;
    int left=1;
    int j=n;
    while(left < j){
        long mid = left + (j-left)/2;
        if((1+mid)*mid/2 < n){
                if( mid == left && j==(left+1)){
                    return left;
                }
            left = mid;
        }else if((1 + mid) * mid / 2 > n){
            j = mid;
        }
        else{
            return mid;
        }
    }
    return left;
}

int arrangeCoins222(int n){
    int count = 0;
    while(n > count){
        count++;
        n -= count;
    }
    return count;
}

/*
如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
*/
bool checkRecord(char * s){
    int size=0;
    int absent=0;
    int late=0;
    int i=0;
    size=strlen(s);
    if(size==0)
    {
        return 0;
    }
    for( i=0;i<size;i++ )//判断是否超过一个'A'
    {
        // if(s[i]!='A')
        // {
        //     absent++;
        //     i++;
        // }
        if(s[i]=='A')
        {
            absent++;
        }
    }
    for(i=0;i<size-2;i++)//判断是否不超过两个连续的'L'
    {
        // if(s[i]=='L'||(s[i+1]=='L'&&s[i+2]=='L'))
        if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L')
        {
            late=1;
        }
    }
    if(absent<=1&&late==0)//都为真返回1 
    {
        return 1;
    }
    return 0;
}

char **board; 
char ***res, ***tmp; 
int sz; 
int cap; 
//0~k行已经处理好了
void solve(int n, int k)
{
    if (k == n - 1)
    {
        char** answer = (char**)malloc(n * sizeof(char*)); 
        for (int l = 0; l < n; ++l)
            answer[l] = (char*)malloc((n + 1) * sizeof(char)), answer[l][n] = '\0'; 
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                answer[x][y] = board[x][y] ? 'Q' : '.'; 
        if (sz == cap)
        {
            tmp = (char***)malloc((cap *= 2) * sizeof(char**)); 
            memcpy(tmp, res, sz * sizeof(char**)); 
            free(res); 
            res = tmp; 
        }
        res[sz++] = answer; 
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            //检查第k - j行
            int j = 0; 
            for (; j <= k; ++j)
            {
                if 
                (
                    board[k - j][i] 
                    || (i - j - 1 >= 0 && board[k - j][i - j - 1]) 
                    || (i + j + 1 < n && board[k - j][i + j + 1])
                ) 
                    break; 
            }
            if (j > k)
            {
                board[k + 1][i] = 1; 
                solve(n, k + 1); 
                board[k + 1][i] = 0; 
            }
        }
    }
}
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    sz = 0; 
    cap = 8; 
    res = (char***)malloc(cap * sizeof(char**)); 
    board = (char**)malloc(n * sizeof(char*)); 
    for (int i = 0; i < n; ++i)
    {
        board[i] = (char*)malloc(n * sizeof(char)); 
        memset(board[i], 0, n * sizeof(char)); 
    }
    for (int i = 0; i < n; ++i)
    {
        board[0][i] = 1; 
        solve(n, 0); 
        board[0][i] = 0; 
    }
    for (int i = 0; i < n; ++i)
        free(board[i]); 
    free(board); 
    *returnSize = sz; 
    *returnColumnSizes = (int*)malloc(sz * sizeof(int)); 
    for (int i = 0; i < sz; ++i){
        (*returnColumnSizes)[i] = n; 
    }
        
        

    return res; 
}


int maxProfit(int* prices, int pricesSize){
    if(!prices){
        return 0;
    }
        
    int *temp = (int *)calloc(pricesSize - 1,sizeof(int));
    int i;
    int res = 0;
    
    for(i = 0; i < pricesSize - 1; i++)
    {
        temp[i] = prices[i+1] - prices[i];
    }
    
    for(i = 0;i < pricesSize - 1; i++)
    {
        res += max(diff[i],0);
    }
    return res;
}




/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。
*/
void sortColors(int* nums, int numsSize){

    int zero_tail = 0;

    int one_tail = 0;

    int two_tail = 0;
    int Idx = 0;
    while (Idx < numsSize)
    { 
        // 如果遍历到0
        if (nums[Idx] == 0) {
            // 两者不相等，说明曾经扫描到2了，则将最前面的2换到最后面位置（为前面插0预留位置）
            if (one_tail != two_tail) {
                nums[two_tail] = 2;
            }

            // 两者不相等 说明曾经扫描到1了，将最前面的1换到1后面（也就是前面2空出来）的位置
            if (zero_tail != one_tail) {
                nums[one_tail] = 1;
            }

            //在0的后面插入0
            nums[zero_tail] = 0;  

            //所有的tail都往后移动1
            zero_tail++;
            one_tail++;
            two_tail++;      
        }
        else if (nums[Idx] == 1)  // 如果遍历到1
        {

            if (one_tail != two_tail)  //曾经扫描到过2，将2换到最后
            {
                nums[two_tail] = 2;
            }
            nums[one_tail] = 1;  // 1最后面（2最前面空出来的位置）插入1

            //1和2的tail都移动1
            one_tail++;
            two_tail++;
        }
        else // 如果是2,2的tail直接移动
        {
            two_tail++;
        }
        Idx++;
    }
    return;
}


/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。
*/
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *p1Head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2Head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p1=p1Head;
    struct ListNode *p2=p2Head;
    struct ListNode *p=head;
    while(p){
        if(p->val<x){
            p1->next=p;
            p1=p;
        }
        else{
            p2->next=p;
            p2=p;
        }
        p=p->next;
    }
    p2->next=NULL;
    p1->next=p2Head->next;
    return p1Head->next;
}

/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
*/
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int row = 0;
    int col = 0;
    int** ppRes = (int**)malloc(numRows * sizeof(int*));//二维数组的分配方式
    for (row = 0; row <= numRows - 1; row++)
    {
        ppRes[row] = (int*)malloc(numRows * sizeof(int));
    }

    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (row = 0; row <= numRows - 1; row++)
    {
        for (col = 0; col <= row; col++)
        {
            if (0 == col || row == col)
            {
                ppRes[row][col] = 1;
            }
            else
            {
                ppRes[row][col] = ppRes[row - 1][col - 1] + ppRes[row - 1][col];
            }
        }

        (*returnColumnSizes)[row] = row + 1;
    }
    
    return ppRes;
}

/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
*/
int* getRow(int rowIndex, int* returnSize){
    int *res = (int *)calloc(10000, sizeof(int));
    if(rowIndex == 0)
    {
        *returnSize = 1;
        res[0] = 1;
        return res;
    }
    int size = rowIndex;
    *returnSize = size;
    int *lastRow = getRow(rowIndex - 1, returnSize);
    int i;
    
    for(i = 0;i <= rowIndex;i++)
    {
        if(i == 0 || i == rowIndex)
        {
            res[i] = 1;
        }
        else
        {
            res[i] = lastRow[i - 1] + lastRow[i];
        }
    }
    *returnSize = i;
    return res;
    
}


/*
给定一个正整数，返回它在 Excel 表中相对应的列名称。
*/
char * convertToTitle(int n){
    char *a=(char*)malloc(sizeof(char)*10);  //分配10个空间
    int i=8;
    while(n)   //取模一次，再相除就能得到两位的情况
    {
        n--;
        a[i--]=n%26+'A';
        n=n/26;
    }
    a[9]='\0';
    return &a[i+1];
}


/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/
int kkk(int a, int b){
    return a>b?a:b;
}

int rob(int* nums, int numsSize){
    if(numsSize == 0)
    {
        return 0;
    }

    if(numsSize == 1)
    {
        return nums[0];
    }

    int first = nums[0];//一直在前
    int second = kkk(nums[0], nums[1]);

    for(int i=2; i<numsSize; i++)
    {
        int temp = second;
        second = kkk(first+nums[i], second);//从3的情况开始每次找最大的金额
        first = temp;
    }
    return second;
}


/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
*/
int mmm(int a, int b) {
	return a>b?b:a;
}

int minSubArrayLen(int s, int* nums, int numsSize){
    if(nums==NULL) return 0;

    // 滑动窗口
    int l = 0, r = 0, sum = 0, minLen = numsSize; 
    while(r<numsSize) {
        sum += nums[r];  
        while(sum >= s && r>=l) { 
        	minLen = mmm(minLen, (r-l+1));  
			sum -= nums[l];   
			l++;
		}
		r++;
        if(r-l==numsSize && sum<s) {  
            minLen= 0;
        }

    }
	return minLen;

}

// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
bool isPalindrome(char * s){// 栈的方法
    if(s == "")
        return 1;

    int len = strlen(s);
    char *stk = (char*)malloc(sizeof(char) * len);
    int top = -1, i;
    for(i = 0; i < len; i++){
        if(isupper(s[i])){
            stk[++top] = s[i] + 32;
        }
        else if(islower(s[i]) || isdigit(s[i])){
            stk[++top] = s[i];
        }
    }
    for(i = 0; i < len; i++){
        if(isupper(s[i])){
            char t = stk[top];
            if(s[i] + 32 != t)
                return 0;
            top--;
        }
        else if(islower(s[i]) || isdigit(s[i])){
            char t = stk[top];
            if(s[i] != t)
                return 0;
            top--;
        }
    }
    if(top >= 0)
        return 0;
    return 1;
}

char * convert(char * s, int numRows){
    int len = strlen(s);
    if(len<=2||numRows<=1) return s;    //特殊情况

    int numLines;   //算列数
    if((len-numRows)%(numRows-1)==0){
        numLines = (len-numRows)/(numRows-1)+1;
    }else{
        numLines = (len-numRows)/(numRows-1)+2;
    }
    int chMap[numRows][numLines];// 可以用函数解决
    memset(chMap,0,sizeof(chMap));
    int i = 1;  //第一个字符直接赋值从第二个开始
    int row = 0,line = 0;
    while(line<numLines){
        if(line%2==0){  //偶数列从上到下
            row = 1;
            while(s[i] && row<numRows){ 
                chMap[row][line] =(int)s[i];
                i++;
                row++;
            }
        }else{      //奇数列从下到上
            row = numRows-2;
            while(row>=0 && s[i]){
                chMap[row][line] =(int)s[i];
                i++;
                row--;
            }
        }
        line++;
    }

    char *a = (char *)malloc(len+1);
    a[0] = s[0];
    i = 1;
    for(row = 0;row<numRows;row++){     //二维数组写入一维数组
        for(line = 0;line<numLines;line++){
            if(chMap[row][line]){
                a[i] = (char)chMap[row][line];
                i++;
            }  
        }
    }
    a[len] = '\0';
    return a;
}

int maxProfitII(int* prices, int pricesSize){
    
    if (pricesSize == 0||pricesSize == 1) {
        return 0;
    }
    
    int profit = 0;
    int lastPrice = prices[0];
    
    for (int i = 1; i < pricesSize; i++) {
        
        if (prices[i] > lastPrice) {
            profit = profit + prices[i] - lastPrice;
        }
       
        lastPrice = prices[i];
    }
    return profit;
}

int singleNumber(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        int  j = 0;
        for(j = 0; j < numsSize; j++){
            if(i != j && nums[i] == nums[j]) {
                break;
            }
        }
        if(j == numsSize) return nums[i];
    }
    return 0;
}


bool hasCycle(struct ListNode *head) {
    bool bRet= false;
    struct ListNode* pQuick= NULL;
    struct ListNode* pSlow= NULL;

    if(NULL == head) return false;

    pQuick = head;
    pSlow = head;

    while(NULL != pQuick)
    {
        pSlow = pSlow->next;
        pQuick = pQuick->next;
        if(NULL == pQuick) break;
        pQuick = pQuick->next;

        if(pQuick == pSlow)
        {
            bRet = true;
            break;
        }
    }
    return bRet;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0) {
        return "";
    }
    int index=0,j;
    while(1){
        for(j=0;j<strsSize;j++)
            if (strs[j][index]!=strs[0][index]||strs[j][index]==0) {
                break;
            }
        if (j==strsSize) {
            index++;
        }
        else {
            break;
        }
    }
    char s[index+1];
    for (j=0;j<index;j++)
        s[j]=strs[0][j];   
    s[index]=0;
    char* str=s;
    return str;
}



int main(){
    return 0;
}



