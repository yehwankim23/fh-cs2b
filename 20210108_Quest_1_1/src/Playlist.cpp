// Student ID: 20382528
// Quest: The Platypus-Bodied Duck
// Trophies: 33/33

#include "Playlist.h"

#include <sstream> // ostringstream
#include <string> // string

using namespace std;

bool Playlist::Song_Entry::set_id(int id)
{
    bool result = false;

    if (id >= 0)
    {
        _id = id;
        result = true;
    }

    return result;
}

bool Playlist::Song_Entry::set_name(string name)
{
    bool result = false;

    if (name.length() > 0)
    {
        _name = name;
        result = true;
    }

    return result;
}

Playlist::Node::~Node()
{
    // Do not do recursive free.
}

Playlist::Node* Playlist::Node::insert_next(Node* p)
{
    this->_next = p;
    return p;
}

Playlist::Node* Playlist::Node::remove_next()
{
    this->_next = this->_next->_next;
    return this;
}

Playlist::Playlist()
{
    _head = new Node(Song_Entry(-1, "HEAD"));
    _tail = _prev_to_current = _head;
    _size = 0;
}

Playlist::~Playlist()
{
    clear();
    _head = nullptr;
    delete _head;
}

Playlist::Song_Entry& Playlist::get_current_song() const
{
    if (_prev_to_current->get_next() == nullptr)
    {
        return _head->get_song();
    }

    return _prev_to_current->get_next()->get_song();
}

Playlist* Playlist::clear()
{
    rewind();

    while (_prev_to_current != nullptr)
    {
        _head = _prev_to_current->get_next();
        _prev_to_current = nullptr;
        delete _prev_to_current;
        rewind();
    }

    _head = new Node(Song_Entry(-1, "HEAD"));
    _tail = _prev_to_current = _head;
    _size = 0;
    return this;
}

Playlist* Playlist::rewind()
{
    _prev_to_current = _head;
    return this;
}

Playlist* Playlist::push_back(const Song_Entry& s)
{
    Node* prev = _prev_to_current;
    _prev_to_current = _tail;
    insert_at_cursor(s);
    _tail = _prev_to_current->get_next();
    _prev_to_current = prev;
    return this;
}

Playlist* Playlist::push_front(const Song_Entry& s)
{
    Node* prev = _prev_to_current;
    _prev_to_current = _head;
    insert_at_cursor(s);
    _prev_to_current = prev;
    return this;
}

Playlist* Playlist::insert_at_cursor(const Song_Entry& s)
{
    Node* new_node = new Node(s);
    new_node->insert_next(_prev_to_current->get_next());
    _prev_to_current->insert_next(new_node);
    _size++;

    if (_head == _tail)
    {
        _tail = _tail->get_next();
    }

    return this;
}

Playlist* Playlist::remove_at_cursor()
{
    _prev_to_current->insert_next(_prev_to_current->get_next()->get_next());
    _size--;
    return this;
}

Playlist* Playlist::advance_cursor()
{
    if (_prev_to_current == _tail)
    {
        return nullptr;
    }

    _prev_to_current = _prev_to_current->get_next();
    return this;
}

Playlist* Playlist::circular_advance_cursor()
{
    if (_prev_to_current == _tail)
    {
        _prev_to_current = _head;
    }
    else
    {
        _prev_to_current = _prev_to_current->get_next();
    }

    return this;
}

Playlist::Song_Entry& Playlist::find_by_id(int id) const
{
    Node* curr = _head->get_next();

    while (curr != nullptr)
    {
        int result = curr->get_song().get_id();

        if (result == id)
        {
            return curr->get_song();
        }

        curr = curr->get_next();
    }

    return _head->get_song();
}

Playlist::Song_Entry& Playlist::find_by_name(string songName) const
{
    Node* curr = _head->get_next();

    while (curr != nullptr)
    {
        string result = curr->get_song().get_name();

        if (result == songName)
        {
            return curr->get_song();
        }

        curr = curr->get_next();
    }

    return _head->get_song();
}

string Playlist::to_string() const
{
    ostringstream oss;
    oss << _size;
    string result = "Playlist: " + oss.str() + " entries.\n";
    Node* curr = _prev_to_current->get_next();

    for (int i = 0; i < 25 && curr != nullptr; i++)
    {
        oss.str("");
        oss.clear();
        oss << curr->get_song().get_id();
        result += "{ id: " + oss.str() + ", name: "
            + curr->get_song().get_name() + " }";

        if (curr == _prev_to_current)
        {
            result += " [P]";
        }

        if (curr == _tail)
        {
            result += " [T]";
        }

        result += "\n";
        curr = curr->get_next();
    }

    if (_size > 25)
    {
        result += "...\n";
    }

    return result;
}
