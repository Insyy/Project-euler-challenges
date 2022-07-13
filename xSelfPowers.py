import math

def self_powers():
	res = 0
	for i in range(1,1001):
	 res += pow(i,i)
	stringRep = str(res)
	final = stringRep[len(stringRep)-10:]
	print(final)
def main():
	self_powers()

if __name__ == "__main__":
    main()