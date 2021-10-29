def mod(a, b):
	return (a%b + b)%b
def mod_exp(x, y, p):
	res = 1 # Initializing result
	x = mod(x, p) # Update x if it is more than or equal to p
	if x == 0:
		return 0 # In case x is divisible by p
	while y > 0:

		# If y is odd, multiply x with result
		if y&1:
			res = mod(res*x, p)

		# y must be even before this step
		y = y >> 1
		x = mod(x*x, p)
	return res

print(mod_exp(2, 5,100))