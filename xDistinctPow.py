import math

def main():
    combinations = []
    for a in range(2,101):
        for b in range(2,101):
            comb = pow(a,b)
            if(not (comb in combinations)):
                combinations.append(comb)
    print(f'Result :{len(combinations)}')

if __name__ == "__main__":
    main()