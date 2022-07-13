import math

def isPrime(n):
    if n <= 3:
        return n > 1
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i ** 2 <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def  main():
    nPrime = 0
    i=2
    sum = 0
    while i <= 2000000:
        if isPrime(i):
            nPrime += 1
            sum += i
            print (f'Prime n{nPrime} : {i}')
        i += 1
    print(f'Sum of all the primes below two million = {sum}')
    

if __name__ == "__main__":
    main()