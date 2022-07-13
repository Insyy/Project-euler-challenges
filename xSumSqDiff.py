import math




def main():
    sumSquareDiff(100)
def sumOfSquares(n):
    res = 0
    num = 1
    for num in range(n+1):
        res += pow(num,2)
    return res
def sumSquareDiff(n):
    print(f'The difference between the sum of the squares of the first {n} natural numbers and the square of the sum is {squareOfSum(n)}-{sumOfSquares(n)}={squareOfSum(n)-sumOfSquares(n)}')
def squareOfSum(n):
    res = 0
    for num in range(1,n+1):
        res += num
    return pow(res,2)

if __name__ == '__main__':
  main()