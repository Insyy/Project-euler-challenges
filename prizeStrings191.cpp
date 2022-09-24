// C++ program to print all
// possible strings of length k
#include <bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
	
vector<string> possibilities;
int Pcount = 0;

bool isForfeit(string s){
	int absentCount = 0, lateCount = 0;
	for (auto &&ch : s)
	{
		if (ch == 'A') absentCount++;
		else absentCount = 0;
		if (ch == 'L') lateCount++;
		if (lateCount > 1 || absentCount == 3) return true;
	}
	
	return false;
}

// The main recursive method
// to print all possible
// strings of length k
void printAllKLengthRec(char set[], string prefix,
									int n, int k)
{
	
	// Base case: k is 0,
	// print prefix
	if (k == 0)
	{
		if (!isForfeit(prefix))
			//possibilities.push_back(prefix);
			Pcount++;
		//cout << (prefix) << endl;
		return;
	}

	// One by one add all characters
	// from set and recursively
	// call for k equals to k-1
	for (int i = 0; i < n; i++)
	{
		string newPrefix;
		
		// Next character of input added
		newPrefix = prefix + set[i];
		
		// k is decreased, because
		// we have added a new character
		printAllKLengthRec(set, newPrefix, n, k - 1);
	}

}


void printAllKLength(char set[], int k,int n)
{
	printAllKLengthRec(set, "", n, k);
}

// Driver Code
int main()
{
	
	char set1[] = {'L', 'O', 'A'};
	int setSize = 3;
	int days = 30;
	printAllKLength(set1, days, setSize);
/* 	for (auto &&p : possibilities)
	{
		cout << p << endl;
	} */
	cout << "Exactly " << Pcount << " prize strings exist during a " << days << " period." << endl;
}

// This code is contributed
// by Mohit kumar

