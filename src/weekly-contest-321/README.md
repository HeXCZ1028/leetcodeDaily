# #1: [find-the-pivot-integer](https://leetcode.cn/contest/weekly-contest-321/problems/find-the-pivot-integer/)
### Ideas
Assume $s$ is the sum of $1$ to $n$, Loop to determine if each $x$  between $1$ to $n$ is satisfied with $\sum_{1}^{x}i = \sum_{x}^{n}i$

# #2: [append-characters-to-string-to-make-subsequence](https://leetcode.cn/contest/weekly-contest-321/problems/append-characters-to-string-to-make-subsequence/)
### 描述
给定一个字符串s和字符t，需要在s的末尾添加多少个字符，使得t能成为s的一个子字符串,返回添加的字符串数量。
### 想法
利用贪心的思想，使用双指针求t的字符串t[0,i]是s的子字符串的最大下标i，然后t的剩余子字符串的长度就是要添加的字符串长度。

# #3: [remove-nodes-from-linked-list](https://leetcode.cn/contest/weekly-contest-321/problems/remove-nodes-from-linked-list/)
### 描述
给定一个链表，对于某个节点 $node$, 如果后面有严格大于$node$的节点，则移除$node$节点。
### 想法
维护一个单调递减栈，依次将链表中的元素插入到该单调递减栈中。

# #4:[count-subarrays-with-median-k](https://leetcode.cn/contest/weekly-contest-321/problems/count-subarrays-with-median-k/)
### 描述
对于包含 $1$ to $n$的随机排列的数组，计算中位数为$val$的子数组的个数。
### 想法
若一个子数组的中位数为$val$,那么该子数组中大于$val$的数字的数目等于小于$val$的数字的数目。