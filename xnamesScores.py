import re

def main():
    namesFile = open('data/p022_names.txt')
    for lines in namesFile:
        nameList = lines.replace('"','').split(',')
    nameList.sort()
    globalScore = 0
    for name in nameList:
        print(name)
        score = 0
        for character in name:
            score += ord(character) - 64
            print(character,ord(character) - 64)

        globalScore += score * (nameList.index(name)+1)
    print(globalScore)

if __name__ == '__main__':
    main()
    