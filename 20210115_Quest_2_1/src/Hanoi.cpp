// Student ID: 20382528
// Quest: Hare Today Hanoi Tomorrow
// Trophies: 15/23

#include "Hanoi.h"

#include <sstream> // ostringstream
#include <string> // string
#include <vector> // vector

using namespace std;

string Hanoi::lookup_moves(int num_discs, int src, int dst)
{
    string result;

    if (unsigned(num_discs) < _cache.size())
    {
        if (unsigned(src) < _cache[num_discs].size())
        {
            if (unsigned(dst) < _cache[num_discs][src].size())
            {
                result = _cache[num_discs][src][dst];
            }
        }
    }

    return result;
}

string Hanoi::get_moves(int num_discs, int src, int dst, int tmp)
{
    string result = lookup_moves(num_discs, src, dst);

    if (result.length() == 0)
    {
        if (num_discs == 1)
        {
            ostringstream oss;
            oss << src;
            result += oss.str() + "->";
            oss.str("");
            oss.clear();
            oss << dst;
            result += oss.str() + "\n";
        }
        else if (num_discs > 1)
        {
            result += get_moves(num_discs - 1, src, tmp, dst);
            result += get_moves(1, src, dst, tmp);
            result += get_moves(num_discs - 1, tmp, dst, src);
        }

        while (!(_cache.size() > unsigned(num_discs)))
        {
            _cache.push_back({});
        }

        while (!(_cache[num_discs].size() > unsigned(src)))
        {
            _cache[num_discs].push_back({});
        }

        while (!(_cache[num_discs][src].size() > unsigned(dst)))
        {
            _cache[num_discs][src].push_back({});
        }

        _cache[num_discs][src][dst] = result;
    }

    return result;
}

string Hanoi::solve(int num_discs, int src, int dst, int temp)
{
    string result;
    result += "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n";
    result += get_moves(num_discs, src, dst, temp);
    return result;
}
