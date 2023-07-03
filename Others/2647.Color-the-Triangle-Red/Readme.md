### 2647.Color-the-Triangle-Red

纯粹的贪心找规律。

初始，先将最后一行从左边开始，每隔一个cell进行染色。

然后，从最后一行开始，逐行扫描，按照顺序和逆序交替进行检查每个cell。如果已经被染色，则跳过。下面分情况讨论：
1. 如果该cell的列编号是奇数，说明是个正三角，它的下邻居必然已经染色（我们是逐行处理）。此时如果它之前的行邻居被染色了（通常情况下必然是的），那它自身必然会”被动“染色，故只标记，不加入答案。相反，如果它的左右行邻居都还没有被染色（意味着它本身是该行的第一个），则它无法被动染色。为了最大化效率，我们不直接染色它本身，而是染色它的下一个行邻居，这样它自身也可以”被动“染色。
2. 如果该cell的列编号是偶数，说明是个倒三角，它的上邻居必然还没有被染色。此时如果它的左右行邻居都已经被染色了（通常情况下前一个行邻居必然已经被染色，而下一个行邻居也有可能被跨行染色过），那它自身必然会”被动“染色，故只标记，不加入答案。相反，如果它的左右行邻居有任何一个没有被染色，意味着它无法被动染色。为了最大化效率，我们不直接染色它本身，而是染色它的上邻居，这样它自身也可以”被动“染色*（因为已经有一个行邻居）。

这种算法可能会收录{1,2}，我们要将其去掉，换成{1,1}。