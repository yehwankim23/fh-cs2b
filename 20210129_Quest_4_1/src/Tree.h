// Student ID: 20382528
// Quest: Krazy the Koala

#ifndef Tree_h
#define Tree_h

#include <iostream> // ostream
#include <string> // string
#include <vector> // vector

using namespace std;

class Tree
{
private:
    struct Node
    {
        string _data;
        Node* _sibling, * _child;

        static bool is_equal(const Node* p1, const Node* p2);

        Node(string s = "");
        Node(const Node& that);
        const Node& operator=(const Node& that);
        ~Node();

        string get_data() const { return _data; }
        void set_data(string s) { _data = s; }

        Node* insert_sibling(Node* p);
        Node* insert_child(Node* p);

        string to_string() const;

        bool operator==(const Node& that) const;
        bool operator!=(const Node& that) const;
    };

    Node* _root;

public:
    Tree();
    ~Tree();

    Tree(const Tree& that) { *this = that; }
    Tree& operator=(const Tree& that);

    string to_string() const;
    void make_special_config_1(const vector<string>& names);

    bool operator==(const Tree& that) const;
    bool operator!=(const Tree& that) const;

    friend ostream& operator<<(ostream& os, const Tree& tree);

    friend class Tests;
};

#endif
