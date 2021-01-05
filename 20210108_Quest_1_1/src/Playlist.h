// Student ID: 20382528
// Quest: The Platypus-Bodied Duck

#ifndef Playlist_h
#define Playlist_h

#include <sstream> // ostringstream
#include <string> // string

using namespace std;

class Playlist
{
public:
    class Song_Entry
    {
    private:
        int _id;
        string _name;

    public:
        Song_Entry(int id = 0, string name = "Unnamed") : _id(id), _name(name)
        {}

        int get_id() const { return _id; }
        string get_name() const { return _name; }

        bool set_id(int id);
        bool set_name(string name);

        bool operator==(const Song_Entry& that)
        {
            return this->_id == that._id && this->_name == that._name;
        }
        bool operator!=(const Song_Entry& that)
        {
            return !(*this == that);
        }
        friend std::ostream& operator<<(ostream& os, const Song_Entry& s)
        {
            return os << "{ id: " << s.get_id() << ", name: " << s.get_name()
                << " }";
        }

        friend class Tests;
    };

private:
    class Node
    {
    private:
        Song_Entry _song;
        Node* _next;

    public:
        Node(const Song_Entry& song = Song_Entry())
            : _song(song), _next(nullptr)
        {}
        ~Node();

        Song_Entry& get_song() { return _song; }
        Node* get_next() { return _next; }

        Node* insert_next(Node* p);
        Node* remove_next();

        friend class Tests;
    };

private:
    Node* _head, * _tail, * _prev_to_current;
    size_t _size;

public:
    Playlist();
    ~Playlist();

    size_t get_size() const { return _size; }
    Song_Entry& get_current_song() const;

    Playlist* clear();
    Playlist* rewind();
    Playlist* push_back(const Song_Entry& s);
    Playlist* push_front(const Song_Entry& s);
    Playlist* insert_at_cursor(const Song_Entry& s);
    Playlist* remove_at_cursor();
    Playlist* advance_cursor();
    Playlist* circular_advance_cursor();

    Song_Entry& find_by_id(int id) const;
    Song_Entry& find_by_name(string songName) const;

    string to_string() const;

    friend class Tests;
};

#endif
