//最长公共子序列
//LCS(longest common sequence)
//给出两个字符串S1和S2,求这两个字符串的最长公共子序列的长度
//S1 = ABcD
//S2 = AeBD		最长公共子序列为3 ABD
//LCS(m, n)	S1[0...m]和S2[0...n]的最长公共子序列的长度
//S1[m] == S2[n]:
//LCS(m,n) = 1 + LCS(m-1, n-1)
//S1[m] != S2[n]:
//LCS(m,n) = max( LCS(m-1, n), LCS(m, n-1))
//

