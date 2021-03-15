// Student ID: 20382528
// Quest: Krazy the Koala
// Trophies: 40/40

#include "Tree.h"

#include <iostream> // ostream
#include <string> // string
#include <vector> // vector

using namespace std;

Tree::Node::Node(const Node& that)
{
    *this = that;
}

const Tree::Node& Tree::Node::operator=(const Tree::Node& that)
{
    if (this != &that)
    {
        _data = that._data;
        _sibling = nullptr;
        _child = nullptr;

        if (that._sibling != nullptr)
        {
            _sibling = new Node(*that._sibling);
        }
        if (that._child != nullptr)
        {
            _child = new Node(*that._child);
        }
    }

    return *this;
}

Tree::Node::~Node()
{
    if (_sibling != nullptr)
    {
        delete _sibling;
        _sibling = nullptr;
    }
    if (_child != nullptr)
    {
        delete _child;
        _child = nullptr;
    }
}

Tree::Node* Tree::Node::insert_sibling(Node* p)
{
    Node* temp = this;

    while (temp->_sibling != nullptr)
    {
        temp = temp->_sibling;
    }

    temp->_sibling = p;
    return p;
}

Tree::Node* Tree::Node::insert_child(Node* p)
{
    if (_child == nullptr)
    {
        _child = p;
    }
    else
    {
        _child->insert_sibling(p);
    }

    return p;
}

string Tree::Node::to_string() const
{
    string result = _data + " :";
    Node* temp = _child;

    while (temp != nullptr)
    {
        result += " " + temp->_data;
        temp = temp->_sibling;
    }

    result += "\n";
    temp = _child;

    if (temp != nullptr)
    {
        result += "# Child of " + _data + "\n";
        result += temp->to_string();
    }

    temp = _sibling;

    if (temp != nullptr)
    {
        result += "# Next sib of " + _data + "\n";
        result += temp->to_string();
    }

    return result;
}

bool Tree::Node::operator==(const Node& that) const
{
    return is_equal(this, &that);
}

bool Tree::Node::operator!=(const Node& that) const
{
    return !(*this == that);
}

bool Tree::Node::is_equal(const Node* p1, const Node* p2)
{
    bool result = false;

    if (p1 == nullptr && p2 == nullptr)
    {
        result = true;
    }
    else if (p1 != nullptr && p2 != nullptr)
    {
        result = true;

        if (p1->_data.compare(p2->_data) != 0)
        {
            result = false;
        }
        else if (!is_equal(p1->_sibling, p2->_sibling))
        {
            result = false;
        }
        else if (!is_equal(p1->_child, p2->_child))
        {
            result = false;
        }
    }

    return result;
}

Tree::Tree()
{
    _root = new Node("ROOT");
}

Tree::~Tree()
{
    delete _root;
    _root = nullptr;
}

Tree& Tree::operator=(const Tree& that)
{
    if (this != &that)
    {
        _root = nullptr;

        if (that._root != nullptr)
        {
            _root = new Node(*that._root);
        }
    }

    return *this;
}

string Tree::to_string() const
{
    string result = "# Tree rooted at " + _root->_data + "\n";
    result += "# The following lines are of the form:\n";
    result += "#   node: child1 child2...\n";
    result += _root->to_string();
    result += "# End of Tree\n";
    return result;
}

void Tree::make_special_config_1(const vector<string>& names)
{
    Node* curr = _root->insert_sibling(new Node(names[0]));
    curr->insert_child(new Node(names[4]))->insert_child(new Node(names[12]));
    curr->insert_child(new Node(names[5]))->insert_child(new Node(names[13]));
    curr = _root->insert_sibling(new Node(names[1]));
    curr->insert_child(new Node(names[6]))->insert_child(new Node(names[14]));
    curr->insert_child(new Node(names[7]))->insert_child(new Node(names[15]));
    curr = _root->insert_sibling(new Node(names[2]));
    curr->insert_child(new Node(names[8]))->insert_child(new Node(names[16]));
    curr->insert_child(new Node(names[9]))->insert_child(new Node(names[17]));
    curr = _root->insert_sibling(new Node(names[3]));
    curr->insert_child(new Node(names[10]))->insert_child(new Node(names[18]));
    curr->insert_child(new Node(names[11]))->insert_child(new Node(names[19]));
}

bool Tree::operator==(const Tree& that) const
{
    bool result = false;

    if (Node::is_equal(_root, that._root))
    {
        result = true;
    }

    return result;
}

bool Tree::operator!=(const Tree& that) const
{
    return !(*this == that);
}

ostream& operator<<(ostream& os, const Tree& tree)
{
    os << tree.to_string();
    return os;
}
