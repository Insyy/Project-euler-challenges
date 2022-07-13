def d(n):
    sum = 0
    for number in range(1,n):
        if n % number == 0:
            sum += number
    return sum

def areAmicable(a,b):
    return d(a) == b and d(b) == a and a != b

def main():
    amicables = []
    res = 0
    n = 10001
    for x in range(n):
        for y in range(x,n):
            if areAmicable(x,y):
                if (not x in amicables and not y in amicables):
                    amicables.append(x)
                    amicables.append(y)
                    res += x + y
                    print(f'Amicable [{x},{y}]')
    print(f'All amicables: {amicables}\nSum of all the amicable numbers under {n} : {res}')
if __name__ == "__main__":
    main()