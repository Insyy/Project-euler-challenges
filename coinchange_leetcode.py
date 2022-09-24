""" You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin. """

class Solution:
        
    def coinChange(self, coins: list[int], amount: int) -> int:
        self.possibilities = []
        sortedCoins = sorted(coins)
        coinListQuantities: list[int] = []
        for i in sortedCoins:
            coinListQuantities.append(0)
            
        self.fillQuantities(amount, sortedCoins, coinListQuantities, len(coins) - 1)
        
        if len(self.possibilities) == 0:
            return -1
        return min(self.possibilities)
    
    
    def fillQuantities(self, remainingAmount: int, availableCoins: list[int], coinQuantities: list[int], lastIndex: int):
        print(f'\tRemaining amount {remainingAmount}, coin quantities are {coinQuantities}, last index {lastIndex}')
        if remainingAmount == 0:
            self.possibilities.append(sum(coinQuantities))
            print(f'\t\tPossibilities: {self.possibilities}')
        
        if lastIndex == -1:
            for i in range(len(availableCoins) - 1, 0, -1):
                print(f'Checking if coins of index {i} are available')
                if coinQuantities[i] > 0:
                    print(f'Adding a coin to amount from index {i}')
                    remainingAmount += availableCoins[i]
                    coinQuantities[i] -= 1
                    self.fillQuantities(remainingAmount, availableCoins, coinQuantities, i - 1)
                    break
            return

        
        if remainingAmount >= availableCoins[lastIndex]:
            print(f'Removing {availableCoins[lastIndex]} from remaining amount')
            coinQuantities[lastIndex] += remainingAmount // availableCoins[lastIndex]
            remainingAmount -= availableCoins[lastIndex] * (remainingAmount // availableCoins[lastIndex])
            
        self.fillQuantities(remainingAmount, availableCoins, coinQuantities, lastIndex - 1)

def main():
    """ solve([1,2,5], 11)
    solve([2], 3)
    solve([1], 0) """
    solve([186,419,83,408], 6249)

def solve(coins, amount):
    solution = Solution()
    print(solution.coinChange(coins, amount))
    
main()