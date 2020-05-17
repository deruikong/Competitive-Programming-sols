n = int(__import__("sys").stdin.readline())
a = 1
cnt = 0
while(a < n):
	cnt += 1;
	a *= 100
print(cnt)