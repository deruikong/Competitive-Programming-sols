input = __import__('sys').stdin.readline

for i in range(int(input())):
	lst = list(map(int, input().split()))
	lst[0] += 1
	front = (1e6, 1)
	for j in range(10):
		front = min(front, (lst[j], j))
	if(front[1] == 0):
		for j in range(1, 10):
			if(lst[j]):
				print(str(j), end='')
				break
	print(str(front[1]) * (front[0]), end = '')
	if(front[1] != 0):
		print(front[1])
	else:
		print()