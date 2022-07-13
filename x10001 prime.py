import math
def isPrime(n: int) -> bool:
    if n <= 3:
        return n > 1
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i ** 2 <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 7
    return True



def  main():
    nPrime = 0
    i=2
    while nPrime <= 10001:
        if isPrime(i):
            nPrime += 1
            print (f'Prime n{nPrime} : {i}')
        i += 1
    

if __name__ == "__main__":
    main()