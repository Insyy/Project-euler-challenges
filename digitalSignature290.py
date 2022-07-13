
def main():
    count = 0
    for n in range(pow(10,18) - 1):
        if digitSum(n) == digitSum(137 * n):
            count += 1

def digitSum(n):
    total = 0
    for digitChar in str(n):
        total += int(digitChar)
    return total
if __name__ == '__main__':
    main()
    