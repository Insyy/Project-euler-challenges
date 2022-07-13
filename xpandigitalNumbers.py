class Pandigitals:
    
    panArray = []

    def generatePandigitalNumbers(self, k, A):
        if k == 1:
            if A[0] != 0:
                self.panArray.append(arrayToInt(A))
        else:
            self.generatePandigitalNumbers(k-1,A)
            for i in range(0,k-1):
                if k % 2 == 0:
                    A = swap(A,i,k-1)
                else:
                    A = swap(A,0,k-1)
                self.generatePandigitalNumbers(k-1,A)
    def __init__(self):
        self.generatePandigitalNumbers(10,[1,2,3,4,5,6,7,8,9,0])

def main():
    pandigitals = Pandigitals()
    res = 0
    print(f'Pandigitals that follow the property found:')
    for number in pandigitals.panArray:
        if checkProperty(number):
            print(number)
            res += number
    print(f'The sum of all 0 to 9 pandigital numbers with this property is equal to {res}')


def arrayToInt(Arr):
    res = ''
    for number in Arr:
        res += str(number)
    return int(res)

def swap(list,a, b):
    list[a],list[b] = list[b],list[a]
    return list
       
def isPandigitalNumber(num):
    found = []
    strNumb = str(num)
    if len(strNumb) != 10:
        return False
    for i in range(10):
        if int(strNumb[i]) in found:
            return False
        else:
            found.append(int(strNumb[i]))
    return True
        

def checkProperty(x):
    divisibles = [2,3,5,7,11,13,17]
    numStr = str(x)
    for i in range(len(divisibles)):
        strTemp = numStr[i+1] + numStr[i+2] + numStr[i+3]
        numbTemp = int(strTemp)
        if (numbTemp % divisibles[i] != 0):
            return False
    return True

if __name__ == '__main__':
  main()