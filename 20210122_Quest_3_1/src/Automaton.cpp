// Student ID: 20382528
// Quest: Merry Mynahs
// Trophies: 23/23

#include "Automaton.h"

#include <string> // string
#include <vector> // vector

using namespace std;

Automaton::Automaton(size_t num_parents, size_t rule)
{
    if (num_parents > MAX_PARENTS)
    {
        _is_valid = false;
        _num_parents = 0;
    }
    else
    {
        _num_parents = num_parents;
        set_rule(rule);
    }

    _extreme_bit = 0;
}

bool Automaton::set_rule(size_t rule)
{
    bool result = false;

    _rules.clear();
    _rules.resize(pow_2(_num_parents));

    if (_num_parents > MAX_PARENTS || rule >= pow_2(pow_2(_num_parents)))
    {
        _is_valid = false;
    }
    else
    {
        for (int i = 0; rule > 0; i++)
        {
            _rules[i] = rule % 2;
            rule /= 2;
        }

        _is_valid = true;
        result = true;
    }

    return result;
}

bool Automaton::equals(const Automaton& that)
{
    bool result = false;

    if (!(this->_is_valid || that._is_valid)
        || ((this->_is_valid && that._is_valid)
        && (this->_num_parents == that._num_parents)
        && (this->_extreme_bit == that._extreme_bit)
        && (this->_rules == that._rules)))
    {
        result = true;
    }

    return result;
}

bool Automaton::make_next_gen(const vector<int>& current_gen,
    vector<int>& next_gen)
{
    bool result = false;

    if (_is_valid && ((current_gen.size() % 2) || !current_gen.size()))
    {
        if (!current_gen.size())
        {
            next_gen = { 1 };
            _extreme_bit = 0;
        }
        else
        {
            vector<int> temp(current_gen);

            for (size_t i = 0; i < _num_parents - 1; i++)
            {
                temp.insert(temp.begin(), _extreme_bit);
                temp.push_back(_extreme_bit);
            }

            next_gen.resize(current_gen.size() + _num_parents - 1);

            for (size_t i = 0; i < next_gen.size(); i++)
            {
                next_gen[i] = _rules[translate_n_bits_starting_at(temp, i,
                    _num_parents)];
            }

            if (_extreme_bit)
            {
                _extreme_bit = _rules.back();
            }
            else
            {
                _extreme_bit = _rules.front();
            }
        }

        result = true;
    }

    return result;
}

string Automaton::get_first_n_generations(size_t n, size_t width)
{
    string result;

    if (_is_valid && width % 2)
    {
        vector<int> temp;

        while (n--)
        {
            make_next_gen(temp, temp);
            result += generation_to_string(temp, width) + "\n";
        }
    }

    return result;
}

string Automaton::generation_to_string(const vector<int>& gen, size_t width)
{
    string result;

    if (_is_valid && width % 2)
    {
        if (gen.size() > width)
        {
            for (size_t i = (gen.size() - width) / 2;
                i < gen.size() - (gen.size() - width) / 2; i++)
            {
                if (gen[i])
                {
                    result += "*";
                }
                else
                {
                    result += " ";
                }
            }
        }
        else
        {
            string extreme_bit = " ";

            if (_extreme_bit)
            {
                extreme_bit = "*";
            }

            for (size_t i = 0; i < (width - gen.size()) / 2; i++)
            {
                result += extreme_bit;
            }

            for (size_t i = 0; i < gen.size(); i++)
            {
                if (gen[i])
                {
                    result += "*";
                }
                else
                {
                    result += " ";
                }
            }

            for (size_t i = 0; i < (width - gen.size()) / 2; i++)
            {
                result += extreme_bit;
            }
        }
    }

    return result;
}

size_t Automaton::translate_n_bits_starting_at(const vector<int>& bits,
    size_t pos, size_t n)
{
    size_t result = 0;

    if (pos + n <= bits.size())
    {
        for (size_t i = pos; i < pos + n; i++)
        {
            result *= 2;
            result += bits[i];
        }
    }

    return result;
}
