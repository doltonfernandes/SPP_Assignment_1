from random import randint

p = 1000
q = 1000
r = 1000

print(p,q,r)

for i in range(p):
	for j in range(q):
		print(randint(0,1000),end=" ")
	print()

for i in range(q):
	for j in range(r):
		print(randint(0,1000),end=" ")
	print()