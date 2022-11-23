# #1 number-of-unequal-triplets-in-array
### Ideas
For each number $val$ in array, assume that $a$ is the number of numbers less than $val$, $b$ is the number of numbers equal to $val$,and $c$ is the number of numbers greater than $val$.The number $val$ 's contribution to the number of unequal triplets is $a*b*c$. So we can use ```map``` to stores the number of occurrences of each number.
### Complexity
Time: O(n), Memory: O(n)


# #2 closest-nodes-queries-in-a-binary-search-tree
### Ideas
Given a binary search tree, inOrder traversal of it can get sorted array. And For each number $val$ in queries array, binary search this array can get $x$ which is greater than or equal to $val$ and $y$ which is less than or equal to $val$.
### Complexity
Time: O(mlog(n)), Memory: O(n). m is the length of queries array and n is the number of node in tree.

# #3 minimum-fuel-cost-to-report-to-the-capital
### Ideas
Because there is a car and a people in each city, using car in each city can alwasy send a people to zero city. Therefore, we can assume the number of car is infinite. The goal is to use car as little as possible. Assume this graph as a tree(root node is zero node), For each $node$, the comsume depends on the number of subtree of this $node$. In details, the consumer is $\lceil sv/seats \rceil$,which $sv$ is the number of subtree of this $node$(because the number of car is infinite, we can assume all the people were reassigned to different cars at this $node$).

# #4 number-of-beautiful-partitions
### Ideas
TODO: