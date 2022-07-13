from enum import Enum
import math
from xSummationPrimes import isPrime


EnergyCost= {
    0 : '1011111',
    1 : '0000011',
    2 : '1110110',
    3 : '1110011',
    4 : '0101011',
    5 : '1111001',
    6 : '1111101',
    7 : '1001011',
    8 : '1111111',
    9 : '1011111'
}
def compare2Digits(a, b):
    bitsA = EnergyCost[int(a)]
    bitsB = EnergyCost[int(b)]
    result = ""
    for i in range(7):
        if bitsA[i] == '1' and bitsB[i] == '1':
            result += '1'
        else:
            result += '0'
    return result


def digit_sum(x: int, b: int) -> int:
    total = 0
    while x > 0:
        total = total + (x % b)
        x = x // b
    return total

def digital_root(x: int, b: int):
    seen = []
    while x not in seen:
        seen.append(x)
        x = digit_sum(x, b)
    return seen

def getTransitionsSamClock(n):
    steps = digital_root(n, 10)
    total = 0
    for step in steps:
        for number in str(step):
            total += 2*EnergyCost[int(number)].count('1') 
    return total

def getTransitionsMaxClock(n):
    steps = digital_root(n, 10)
    total = getTransitionsSamClock(n)
    #print('N transitions with normal clock: ' + str(total))
    for i in range(0,len(steps)):
        if i < len(steps) - 1:
            transitionsUnneeded = getUnneededTransitions(steps[i], steps[i+1])
            total -= 2*transitionsUnneeded
            #print(f'Transitions substracted on iteration {str(i)}: 2*{transitionsUnneeded} from {steps[i]} and {steps[i+1]}')
            #print('Transitions substracted from total on iteration: ' + str(i) + ',' + str(2*getUnneededTransitions(steps[i], steps[i+1])))

    return total


def getUnneededTransitions(a, b):
    nMin = min(a, b)
    minStr = str(nMin)
    total = 0
    for i in reversed(range(len(minStr))):
        total += compare2Digits(str(a)[i], str(b)[i]).count('1')
        #print(compare2Digits(str(a)[i], str(b)[i]) + '  '+ str(compare2Digits(str(a)[i], str(b)[i]).count('1')))
    return total

        
def main():
    difference = 0

    for index in range(pow(10,7), 2*pow(10,7)):
        if isPrime(index):
            difference += getTransitionsMaxClock(index) - getTransitionsSamClock(index)
    print(difference)
if __name__ == '__main__':
    main()
    