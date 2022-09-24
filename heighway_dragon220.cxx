#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <math.h>

#define PI 3.14159265


typedef std::chrono::high_resolution_clock Clock;

using namespace std;

double cos315 = cos(315*PI/180);
double sin315 = sin(315*PI/180);
double sqrt2 = sqrt(2.0);


/* string deriveStringReplace(string str)
{
    int len = str.length(), i = 0;

    while (i < len)
    {
        if (str[i] == 'a')
        {
            str.replace(i, 1, "aRbFR");
            i += 5;
            len += 5;
        }
        else if (str[i] == 'b')
        {
            str.replace(i, 1, "LFaLb");
            i += 5;
            len += 5;
        }
        i++;
    }
    return str;
}

string deriveNReplace(int n)
{
    string dn = "Fa";

    for (size_t i = 0; i < n; i++)
    {
        dn = deriveStringReplace(dn);
    }
    return dn;
}; */

string deriveStringClever(string str)
{
    string result = str;
    result.push_back('R');
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == 'R')
            result.push_back('L');
        else if (str[i] == 'L')
            result.push_back('R');
        else
            result.push_back(str[i]);
    }
    result.push_back('R');
    return result;
}

string deriveNClever(int n)
{
    string dn = "Fa";

    for (size_t i = 0; i < n; i++)
    {
        dn = deriveStringClever(dn);
    }
    return dn;
};

void moveForward(int &x, int &y, const int angle)
{
    int realAngle = angle % 360;
    switch (realAngle)
    {
    case 0:
        y++;
        break;
    case 90:
        x++;
        break;
    case 180:
        y--;
        break;
    case 270:
        x--;
        break;

    default:
        break;
    }
}

void followPathString(string path, int &x, int &y, int &angle)
{
    int steps = 0;
    for (auto &&c : path)
    {
        /* if (steps == 500)
        {
            cout << "500 steps reached | Location (x: " << x << ", y: " << y << ")  with angle " << angle << endl;
        } */

        if (c == 'R')
            angle += 90;
        else if (c == 'L')
            angle -= 90;
        else if (c == 'F')
        {
            moveForward(x, y, angle);
            steps++;
        }
    }
}

void reposition(const char order, int &x, int &y, int &angle)
{
    if (order == 'R')
        angle += 90;
    else if (order == 'L')
        angle -= 90;
    else if (order == 'F')
    {
        moveForward(x, y, angle);
    }
}

void printState(const int x, const int y, const int angle)
{
    cout << "Location (x: " << x << ", y: " << y << ")  with angle " << angle << endl;
}

/* void compareTime(){
    int n = 3;

    auto t1 = Clock::now();
    string path = deriveNReplace(n);
    cout << path << endl;
    auto t2 = Clock::now();
    cout << "Derivation by replacement duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;


    auto t3 = Clock::now();
    path = deriveNClever(n);
    cout << path << endl;
    auto t4 = Clock::now();
    cout << endl << "Derivation by deduction duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count() << " nanoseconds" << endl;

} */

string generateAndFollowNewPath(string path, int &x, int &y, int &angle, int &stepCount, const int stepGoal)
{
    path.push_back('R');
    reposition('R', x, y, angle);
    int count = 0;
    
    for (int i = path.length() - 2; i >= 0; i--)
    {
        char order = path[i];
        if (count < 50)
            cout << order;
        if (order == 'R')
        {
            path.push_back('L');
            reposition('L', x, y, angle);
        }

        else if (order == 'L')
        {
            path.push_back('R');
            reposition('R', x, y, angle);
        }
        else if (order == 'F')
        {
            path.push_back('F');
            reposition('F', x, y, angle);
            stepCount++;
            /* if (stepCount % 1000 == 0){
                cout << "step count: " << stepCount << endl;
                printState(x, y, angle);
            } */
        }
        count++;
    }
    cout << endl;

    path.push_back('R');
    reposition('R', x, y, angle);

    return path;
}

void run(int n, int stepsGoal)
{
    int angle = 0, x = 0, y = 0, stepCount = 0;
    string path = "F";

    cout << "Initial move" << endl;
    cout << path << endl;
    reposition('F', x, y, angle);
    stepCount++;
    // printState(x, y, angle);

    for (size_t i = 0; i < n; i++)
    {
        cout << "Path length: " << path.length() << "With " << count(path.begin(), path.end(), 'F') << " F" << endl;
        cout << "Iteration " << i + 1 << endl;
        cout << "Angle is " << angle << endl;

        path = generateAndFollowNewPath(path, x, y, angle, stepCount, stepsGoal);

        // cout << path << endl;
        printState(x, y, angle);
    }
}

int computeNeededIterations(int stepsGoal)
{
    int n = 1;
    while (pow(2, n) < stepsGoal)
        n++;
    cout << pow(2, n) << endl;
    return n;
}

void computeNextValues(long &x, long &y){
    double approxX = (cos315 * x - sin315 * y) * sqrt2;
    double approxY = (sin315 * x + cos315 * y) * sqrt2;
    x = (long) round(approxX);;
    y = (long) round(approxY);
}

string generateLongEnoughPath(int minimumSize){
    string path = "F";
}

int main(int argc, char const *argv[])
{
    run(30, 500);
    long x = 0, y = 1;
    int stepsGoal  = 500;
    /* for (size_t i = 0; i < 10; i++)
    {
        computeNextValues(x, y);
        cout << "x: " << x << "y: " << y << endl;
    } */
    
    return 0;
}

