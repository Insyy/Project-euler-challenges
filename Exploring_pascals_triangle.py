# A O(n^2) time and O(n^2) extra 
# space method for Pascal's Triangle
def buildPascal(n:int):
  
    # An auxiliary array to store 
    # generated pascal triangle values
    arr = [[0 for x in range(n)] 
              for y in range(n)] 
    count = 0
    memo = {}
    # Iterate through every line
    # and print integer(s) in it
    for line in range (0, n):
  
        # Every line has number of 
        # integers equal to line number
        for i in range (0, line + 1):
  
            # First and last values 
            # in every row are 1
            if(i == 0 or i == line):
                arr[line][i] = 1
                print(arr[line][i], end = " ") 
  
            # Other values are sum of values
            # just above and left of above 
            else:
                value = (arr[line - 1][i - 1] + 
                                arr[line - 1][i])
                arr[line][i] = value
                if value in memo:
                    if memo[value] == True:
                        count += 1
                else:
                    memo[value] = 
                
                print(arr[line][i], end = " ")
                print(memo[arr[line][i]])
        print("\n", end = "")
  
  
""" def printRow(int: n) -> int:
    last = 1
    for k in range(1, (n // 2) + 1): """
        
        
# Driver Code
n = 5
buildPascal(n)
  
# This code is contributed 
# by Sanju Maderna