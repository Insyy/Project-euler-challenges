import itertools as iter

def main():
    permutations = iter.permutations('0123456789', 10)
    i = 0
    for permutation in permutations:
        i += 1
        if i == 1000000:
            print(permutation.__str__().replace('\'','').replace('(','').replace(')','').replace(',','').replace(' ',''))
if __name__ == '__main__':
    main()