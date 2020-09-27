#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
 };
 




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


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (!matrixSize) {
        return false;
    }
    
    int low = 0;
    int high = matrixSize * matrixColSize[0] - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int i = mid / matrixColSize[0];
        int j = mid % matrixColSize[0];
        if (matrix[i][j] > target) {
            high = mid - 1;
        } else if (matrix[i][j] < target) {
            low = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = matrixSize - 1;
    int j = 0;

    while (i >= 0 && j < matrixColSize[0]) {//j是列数
        if (target > matrix[i][j]) {
            ++j;
        } else if (target < matrix[i][j]) {
            --i;
        } else {
            return true;
        }
    }
    return false;
}
// Definition for a binary tree node.
struct TreeNode {
     int val;
     struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p && !q) { 
        return true;
    }
    if((p && !q) || (!p && q)) {
        return false;
    }
    if(q->val != p->val) {
        return false;
    }
    // while(!q->left&&!q->right){
    //     int a = q->left
    // }
    // else if(){
        //isSameTree(p->left, q->left)&&isSameTree(p->right, q->right)
    // }
    if(isSameTree(p->left, q->left)&&isSameTree(p->right, q->right)){
        return true;
    }else{
        return false;
    }
}

int maxDepth(struct TreeNode* root){
    if(!root){
        return 0;
    }
    // if(root->right==NULL){
    //     return false;
    // }
    //从下往上的计数
    int right = maxDepth(root->right)+1;
    int left = maxDepth(root->left)+1;
    
    if(right>=left){
        return right;
    }else{
        return left;
    }
}

int minDepth(struct TreeNode* root){
    if (root==NULL )
    {
        return 0;
    }
    if (root->left == NULL)
    {
        return minDepth(root->right) + 1;
    }
    if (root->right == NULL)
    {
        return minDepth(root->left) + 1;
    }
    int left = minDepth(root->left) + 1;
    int right = minDepth(root->right) + 1;
    if(left<right){
        return left;
    }else{
        return right;
    }
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *p,*q;
    int temp;
    p = head;
    q = head;
    // struct ListNode *q = p->next;
    while(p!=NULL)
    {
        while(q!=NULL)
        {
            if((p->val) > (q->val))
            {
                temp = p->val;
                p->val = q->val;
                q->val = temp;
            }
            q = q->next;
        }
        q = p->next;
        p = p->next;
    }
    return head;
}


char findTheDifference(char * s, char * t)
{
    int len = strlen(s);
    int i = 0;
    // int s1[26] = {0};
    // int t1[26] = {0};
    int *s1 = (int *)malloc(sizeof(int) * 26);
    int *t1 = (int *)malloc(sizeof(int) * 26);
    memset(s1, 0, sizeof(int) * 26);
    memset(t1, 0, sizeof(int) * 26);
    for(i = 0;i<len;i++)// 初始化
    {
        s1[s[i] - '0']++;
        t1[t[i] - '0']++;
    }
    t1[t[i] - '0']++;
    for(i = 0;i<26;i++)
    {
        if(s1[i] != t1[i])
            return i+'0';
    }
    return NULL;
}



#define LEN 20
typedef struct queue{
    int *data;
    int head;
    int rear;
    int size;
}Queue;

typedef struct {
    Queue *q1,*q2;
} MyStack;

Queue *initQueue(int k){
    Queue *obj=(Queue *)malloc(sizeof(Queue));
    obj->data=(int *)malloc(k*sizeof(int));
    obj->head=-1;
    obj->rear=-1;
    obj->size=k;
    return obj;
}
void enQueue(Queue *obj,int e){
    if(obj->head==-1){
      obj->head=0;
    }
    obj->rear=(obj->rear+1)%obj->size;
    obj->data[obj->rear]=e;
}
int deQueue(Queue *obj){
    int a=obj->data[obj->head];
    if(obj->head==obj->rear){
        obj->rear=-1;
        obj->head=-1;
        return a;
    }
    obj->head=(obj->head+1)%obj->size;
    return a;
}
int isEmpty(Queue *obj){
    return obj->head==-1;
}

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj=(MyStack *)malloc(sizeof(MyStack));
    obj->q1=initQueue(LEN);
    obj->q2=initQueue(LEN);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(isEmpty(obj->q1)){
    enQueue(obj->q2,x);
  }else{
    enQueue(obj->q1,x);
  }

}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(isEmpty(obj->q1)){
        while(obj->q2->head != obj->q2->rear){
            enQueue(obj->q1,deQueue(obj->q2));
        }
        return  deQueue(obj->q2);
    }
    while(obj->q1->head != obj->q1->rear){
        enQueue(obj->q2,deQueue(obj->q1));
    }
    return  deQueue(obj->q1);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(isEmpty(obj->q1)){
        return obj->q2->data[obj->q2->rear];
    }
    return obj->q1->data[obj->q1->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->q1->head==-1 && obj->q2->head==-1){
        return true;
    }
    return false;

}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    obj->q1->data=NULL;
    free(obj->q1);
    obj->q1=NULL;
    free(obj->q2->data);
    obj->q2->data=NULL;
    free(obj->q2);
    obj->q2=NULL;
    free(obj);
    obj=NULL;

}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/


int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize-1;
    int temp = 0;
    int res = 0;
    while(right-left){
        // if(right-left > height[left]){

        // }
        // temp1 = (right-left)?;
        temp = (right-left) * ((height[right]>height[left])?height[left]:height[right]);
        if(temp>res){
            res = temp;
        }       
        if(height[right]>height[left]){
            left++;
        }
        else{
            right--;
        }
    }
    return res;
}

int sumOfLeftLeaves(struct TreeNode* root){   
    if(!root) {
        return 0;
    }
    // if(root->left == NULL){
    //     return 0;
    // }
    // if(root->right == NULL){
    //     return 0;
    // }
    int sum=0;
    if(root->left)
    {
        if(!root->left->left&&!root->left->right)
        {
            sum += root->left->val;
        }
        else
        {
            sum += sumOfLeftLeaves(root->left);
        }
    }
    if(root->right)
    {
        sum += sumOfLeftLeaves(root->right);
    }
    return sum;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    
    int num = 0;
    int left = 0;
    int right = 0;
    if(flowerbedSize==0){
        return false;
    }
    if(flowerbedSize==1&&flowerbed[left]==0){
        num++;
    }
    if(flowerbedSize>=2){
        if(flowerbed[left]==0&&flowerbed[right]==0){
            num++;
        }
        while(right<flowerbedSize){
            if(right-left>1&&flowerbed[right]!=1&&flowerbed[right+1]!=1){
                left = right;
                num++;
            }
            right++;
        }    
    }
    if(num>=n){
        return true;
    }else{
        return false;
    }
}


char * toLowerCase(char * str){
    int length = 0;
    int i;
    while(str[length]!=0) {
        length++;
    }
    char s[10000];
    for(i=0;i<length;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            s[i] = str[i]+32;
        }else{
            s[i] = str[i];
        }      
    }      
    s[length]=0;
    char* string;
    string = s;
    return string;
}




int compare(const void *a, const void *b)
{
    return (*(int*)a) - (*(int*)b);
}

bool isNStraightHand(int* hand, int handSize, int W)
{   
    int test[10000];
    int i;
    int j;
    int k;
    int flag;    
    int start;
    int end;
    if (handSize % W != 0) {
        return false;
    }
    qsort(hand, handSize, sizeof(int), compare);    
    for (i = 0; i < handSize; i++) {
        test[i] = false;
    }
    for (i = 0; i < handSize; i++) {
        if (test[i] == false) {            
            start = hand[i];
            end = start + W - 1;//分段
            for (j = start; j <= end; j++) {
                flag = false;
                for (k = i; k < handSize; k++) {
                    if ((test[k] == false) && (hand[k] == j)) {//反复的追赶
                        test[k] = true;
                        flag = true;
                        break;
                    }
                    if (hand[k] > j) {
                        break;
                    }
                }
                if (flag == false) {
                    return false;
                }
            }
        }
    }   
    return true;
}

int maxPower(char * s){
    int len = strlen(s);
    int max = 1;
    int tmpMax = 1;
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) {
            // max = tmpMax + 1;
            tmpMax++;
            if(max < tmpMax){
                max = tmpMax;
            }else{
                max = max;
            }        
        } else {
            tmpMax = 1;
        }
    }
    return max;
}

int numWaterBottles(int numBottles, int numExchange){
    int empty=numBottles;
    int sum=numBottles;
    if(empty < numExchange){
        return empty;
    }
    while(empty>=numExchange){    
        // sum=sum+numBottles/numExchange;
        // numBottles=numBottles/numExchange+numBottles%numExchange;
        numBottles=empty/numExchange;   //更新
        empty=empty%numExchange+numBottles; //空瓶的数量
        sum=numBottles + sum;    
    }
    return sum;
}

bool tree_cmp(struct TreeNode *lef,struct TreeNode *rig){
    if(lef==NULL&&rig==NULL){
        return true;
    }    
    if((lef==NULL&&rig!=NULL)||(lef!=NULL&&rig==NULL)){
        return false;
    }  
    if(lef->val==rig->val){
        return tree_cmp(lef->right,rig->left)&&tree_cmp(lef->left,rig->right);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root){
    if(root==NULL){
        return true;
    }  
    //struct TreeNode *lef=root->left,*rig=root->right;
    return tree_cmp(root->left,root->right);
}


typedef struct {
    int len;
    int top1;
    int top2;
    int *s1;
    int *s2;
} CQueue;
CQueue* cQueueCreate() {
    CQueue* Q = (CQueue *)calloc(1,sizeof(CQueue));
    Q->len = 10000;
    Q->top1 = -1;
    Q->top2 = -1;
    Q->s1 = (int *)calloc(Q->len,sizeof(int));
    Q->s2 = (int *)calloc(Q->len,sizeof(int));   
    return Q;
}

void cQueueAppendTail(CQueue* obj, int value) {
    if(obj->top1 == -1)
    {
        while(obj->top2 > -1)
        {
            obj->s1[++obj->top1] = obj->s2[obj->top2--];//每个操作反转第二个栈
        }
    }
    obj->s1[++obj->top1] = value;
}

int cQueueDeleteHead(CQueue* obj) {
    if(obj->top2 == -1)
    {
        while(obj->top1 > -1)
        {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];//反转第二个栈
        }
    }
    
    return obj->top2 == -1 ? -1 : obj->s2[obj->top2--];
}

void cQueueFree(CQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/

int diagonalSum(int** mat, int matSize, int* matColSize){
    int value=0;
    int l=0;
    int r = matSize-1;
    for(int i=0;i<matSize;i++)
    {
        value=value+mat[i][l];
        if(l!=r){
            value=value+mat[i][r];
        }   
        l++;//一次循环解决
        r--;
    }
    return value;
 
}

char * modifyString( char * s ){
    int k = 0;
    int p = 0;
    for( int i = 0;s[i] != '\0';i++) {
        if(s[i] == '?') {
            char ch='a';
            // while(s[i+1]!='\0'&&ch==s[i + 1]){
            //     k=1;
            // }
            // while((i > 0&&ch == s[i - 1])){
            //     ch++;
            // }
            while(s[i+1]!='\0'){
                if(ch==s[i + 1]){
                    k=1;
                }
                if((i > 0&&ch == s[i - 1])){
                    p =1;
                }
                if(k==1&&p==1){
                    ch++;
                }
            }
            
            s[i] = ch;
        }
    }
    return s;
}


int main(){
    return 0;
}



