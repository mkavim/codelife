# 动态规划   
动态规划问题，本质是最优公共子问题的叠加，利用备忘录解决D&C中重复计算公共子问题     

*DP问题和DC问题的区别：*   
- 都是将问题划分为子问题进行求解   
- DC是将问题拆成独立的子问题，然后分别求解，最后合并   
- DP的子问题之间是由底而上不断递进，子问题之间是相关的      
- DP通常用于最优化问题求解，这类问题一般有多个解，找到最优的解   
- DP解法一般时间复杂度为O(N^2)，并且是以空间换时间，备忘录方法      

*动态规划的解题步骤：*     
1. 分析最优解的结构特征
2. 递归定义最优解的值(最难一步)   
3. 自底向上的求解最优值    
4. 回溯，记录最优解  

*代码注意点：*  
1. 一般是双层循环   
2. 表的初始化
3. 数组的下标是从0开始      

*实现的主要题目:*   
1. 0-1背包问题:`algorthms/dp/knapsack`    
2. 最长公共子序列问题和最长公共连续子序列问题:`algorthms/dp/lcs`     
3. 最短编辑距离:`algorthms/dp/editDistance`      
4. viterbi解码:`algorthms/dp/viterbi`            
5. 钢条切割:`algorthms/dp/rodcut`      
6. 减绳子:`algorthms/dp/foroffer/question14`    
7. 最长回文串:`leetcode/5_longest-palindromic-subsing`   