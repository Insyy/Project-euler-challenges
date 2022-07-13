from typing import Iterable
import random
import collections

class CalledNumber:
    def __init__(self, number):
        self.number = number
        self.turnsInMemory = 0
        self.turnsNoCall = 0

    def addTurnInMem(self):
        self.turnsInMemory += 1

    def addTurnNoCall(self):
        self.turnsNoCall += 1

    def resetCall(self):
        self.turnsNoCall = 0


class Player(Iterable):
    def __init__(self):
        self.score = 0
        self.memory = list()

    def __iter__(self):
        for number in self.memory:
            yield number

    def __str__(self):
        result = ''
        for calledNumber in self:
            result += str(f' {calledNumber.number}')
        return result

    def larryPlays(self, number):
        remembers = False
        for n in self:
            if n.number == number:
                #print(f'Number {n.number} in memory!')
                self.score += 1
                n.resetCall()
                #print(f'Resetted turns to {n.turnsNoCall} without having been called for number {n.number}')
                remembers = True
            else:
                n.addTurnNoCall()
        if not remembers:
            if len(self.memory) < 5:
                #print(f'{number} added')
                self.memory.append(CalledNumber(number))
            else:
                maxCallNum = CalledNumber
                maxCall = 0
                for calledNumber in self:
                    if calledNumber.turnsNoCall > maxCall:
                        maxCall = calledNumber.turnsNoCall
                        maxCallNum = calledNumber
               # print(f'{maxCallNum.number} ({maxCallNum.turnsNoCall}) replaced by {number} in memory :(')
                self.memory.remove(maxCallNum)
                self.memory.append(CalledNumber(number))

    def robinPlays(self, number):
        remembers = False
        for n in self:
            if n.number == number:
                #print(f'Number {n.number} in memory!')
                self.score += 1
                #print(f'Resetted turns to {n.turnsNoCall} without having been called for number {n.number}')
                remembers = True
            else:
                n.addTurnInMem()
        if not remembers:
            maxCalls = 0
            if len(self.memory) < 5:
                #print(f'{number} added')
                self.memory.append(CalledNumber(number))
            else:
                maxNMem = CalledNumber
                maxMem = 0
                for calledNumber in self:
                    if calledNumber.turnsInMemory > maxMem:
                        maxMem = calledNumber.turnsInMemory
                        maxNMem = calledNumber
               # print(f'{maxCallNum.number} ({maxCallNum.turnsNoCall}) replaced by {number} in memory :(')
                self.memory.remove(maxNMem)
                self.memory.append(CalledNumber(number))

def getEVfromDensity(data: dict, n):
    EV = 0
    for key in data.keys():
        EV += int(key) * data[key] / n
    return EV


def main():
    turnsForEachIter = 50
    numberIterations = 1000000
    differences = []
    LarryScores = {}
    RobinScores = {}
    LarryTotalValues = 0
    RobinTotalValues = 0
    for n in range(1,numberIterations + 1):
        larry = Player()
        robin = Player()

        difference = 0

        for nTurn in range(1, turnsForEachIter + 1):
            rand = random.randint(1,10)
            larry.larryPlays(rand)
            robin.robinPlays(rand)

        if str(larry.score) in LarryScores:
            LarryScores[str(larry.score)] += 1
        else:
            LarryScores[str(larry.score)] = 1
        if str(robin.score) in RobinScores:
            RobinScores[str(robin.score)] += 1
        else:
            RobinScores[str(robin.score)] = 1

        difference += abs(larry.score - robin.score)
        differences.append(difference)
    print(sum(differences)/numberIterations)

    for value in LarryScores.values():
        LarryTotalValues += value
    for value in RobinScores.values():
        RobinTotalValues += value
    for key in sorted(LarryScores.keys()):
        print(f"Probability of Larry to finish a game with a score of {key} = {LarryScores[key]/LarryTotalValues*100}%")
    print('\n')
    for key in sorted(RobinScores.keys()):
        print(f"Probability of Robin to finish a game with a score of {key} = {RobinScores[key]/RobinTotalValues*100}%")
    
    LarryEV = getEVfromDensity(LarryScores, LarryTotalValues)
    RobinEV = getEVfromDensity(RobinScores, RobinTotalValues)
    print(f'Expected value of Larry\'s score is {LarryEV}')
    print(f'Expected value of Robin\'s score is {RobinEV}')
    expectedDiff = abs(LarryEV - RobinEV)
    print(f'Expected difference is {expectedDiff}')
if __name__ == '__main__':
    main()
