import sys
input = sys.stdin.readline

for i in range(int(input())):
	cur = input().lower()
	for j in cur:
		if(j == 'a'): print("Hi!", end = ' ')
		elif (j == 'e'): print("Bye!", end = ' ')
		elif (j == 'i'): print("How are you?", end = ' ')
		elif (j == 'o'): print("Follow me!", end = ' ')
		elif (j == 'u'): print("Help!", end = ' ')
		elif (j.isdigit()): print("Yes!", end = ' ')
	print()