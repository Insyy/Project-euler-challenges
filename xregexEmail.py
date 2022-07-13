import re

def main():
  res = ' '
  f = open('data/emailRegex.txt', 'r')
  for line in f:
    s = re.search('([a-zA-Z0-9_]+(\.[a-zA-Z0-9_]+)*)@([a-zA-Z0-9_]+(\.[a-zA-Z0-9_]+)+)',line)
    if s != None:
      temp = s.group()
      if res != None:
        if res[len(res)] != ";":
          temp += ";"
      res += temp



if __name__ == '__main__':
  main()

