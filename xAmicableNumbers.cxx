#include <vector>
#include <list>
#include <iostream>
long d(long n)
{
    long sum = 0;

    for (long number = 1; number < n; number++)
    {
        if (n % number == 0)
            sum += number;
    } return sum;
}

bool areAmicable(long a, long b)
{
    if ((d(a) == b) && (d(b) == a) && (a != b)) return true;
    else return false;
}

bool amicableAlreadyExists(long x, long y, std::list<long> amicablesV)
{
    bool foundX = false, foundY = false;
    for (auto &&num : amicablesV)
    {
        if (num == x)
            foundX = true;
        if (num == y)
            foundY = true;
        if (foundX && foundY)
            return true;
    } return false;
}

int main(int argc, char const *argv[])
{
    std::list<long> amicables;
    long res = 0, n = 10001;
    for (long x = 0; x <= n; x++)
        for (long y = x; y <= n; y++) 
            if (areAmicable(x, y) == true)
                if (amicableAlreadyExists(x, y, amicables) == false)
                    {
                        amicables.push_back(x);
                        amicables.push_back(y);
                        res += x + y;
                        std::cout << "Amicable found : [" << x << "," << y << "]" << std::endl;
                    }
        
    
    std::cout << "Sum of all the amicable numbers under 10000 : " << res << std::endl;
    return 0;
}
