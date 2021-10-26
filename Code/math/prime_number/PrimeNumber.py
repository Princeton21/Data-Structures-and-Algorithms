
start = int(input("start of the range: "))
end = int(input("end of the range: "))

for i in range(start, end+1):
	if i > 1:
		for j in range(2, i):
			if(i % j == 0):
				break
		else:
			print(i)
