from unittest import main

sortedRows = []

def findMaxPathSum():
    sum = 0
    lastIndex = -1
    for rowIndex in range(len(sortedRows)):
        for numberIndex in range(len(sortedRows[rowIndex])):
            print(sortedRows[rowIndex][numberIndex])
            number, index = sortedRows[rowIndex][numberIndex]
            if (isAdjacent(lastIndex, index)):
                print(str(number) + "is adjacent to last index " + str(lastIndex))
                lastIndex = index
                sum += number
                break
    
    return sum

def isAdjacent(colUpper, colLower):
    return colUpper == -1 or (colUpper == colLower or colLower == colUpper + 1)

def main():
    triangleStr = '75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23'
    tArr = triangleStr.split(' ')
    
    i = 0
    size = 1
    rows = []
    
    
    
    while i < len(tArr):
        row = []
        for j in range(i, i + size):
            row.append(int(tArr[j]))
            """ print(tArr[j], end=' ') """
        """ print('\n') """
        i += size
        size += 1
        rows.append(row)
    
    for rowIndex in range(len(rows)):
        sortedRows.append(sorted(rows[rowIndex], reverse=True))
        for sortedNumberIndex in range(len(sortedRows[rowIndex])):
            sortedNumber = sortedRows[rowIndex][sortedNumberIndex]
            sortedRows[rowIndex][sortedNumberIndex] = (sortedNumber, rows[rowIndex].index(sortedNumber))
            print(sortedRows[rowIndex][sortedNumberIndex], end='  ')
        print("")
    print(findMaxPathSum())
if __name__ == '__main__':
    main()
    
