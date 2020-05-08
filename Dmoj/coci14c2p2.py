import sys
input = sys.stdin.readline

s = {}
n = int(input())
for i in range(n): s[input()]+=1
for i in range(n-1): s[input()]-=1
for k, v in s:
    if(v==0):
        print(k)
        break