
def main():
    for x in range(500):
        for y in range(500):
            for z in range(500):
                if (isPythagorean(x,y,z)):
                    if (x+y+z == 1000):
                      print(f'{x}+{y}+{z}=1000    abc = {x*y*z}')
 
def isPythagorean(a,b,c):
    return(((a*a + b*b) == c*c) and a < b < c)



if __name__ == "__main__":
    main()