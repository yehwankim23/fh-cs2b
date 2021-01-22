// Student ID: 20382528
// Quest: Hare Today Hanoi Tomorrow

#ifndef Hanoi_h
#define Hanoi_h

#include <string> // string
#include <vector> // vector

using namespace std;

class Hanoi
{
private:
    vector<vector<vector<string>>> _cache;

    string lookup_moves(int num_discs, int src, int dst);
    string get_moves(int num_discs, int src, int dst, int tmp);

public:
    string solve(int num_discs, int src, int dst, int temp);

    friend class Tests;
};

#endif
