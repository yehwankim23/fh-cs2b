// Student ID: 20382528
// Quest: The Platypus-Bodied Duck

#include "Playlist.h"

#include <iostream> // cout

using namespace std;

int main()
{
    Playlist playlist;

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    playlist.push_back(Playlist::Song_Entry(1, "3.14"));

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    playlist.push_front(Playlist::Song_Entry(2, "1592"));

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    playlist.advance_cursor();
    playlist.insert_at_cursor(Playlist::Song_Entry(3, "6535"));
    playlist.rewind();

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    cout << "Current: " << playlist.get_current_song() << endl << endl;

    playlist.remove_at_cursor();

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    playlist.find_by_id(1) = Playlist::Song_Entry(4, "8979");
    playlist.find_by_name("6535") = Playlist::Song_Entry(5, "3238");

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    playlist.circular_advance_cursor();

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    playlist.circular_advance_cursor();

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    playlist.circular_advance_cursor();

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << endl;

    playlist.clear();

    cout << "Size: " << playlist.get_size() << endl;
    cout << playlist.to_string() << flush;
    return 0;
}

/* Output
Size: 0
Playlist: 0 entries.

Size: 1
Playlist: 1 entries.
{ id: 1, name: 3.14 } [T]

Size: 2
Playlist: 2 entries.
{ id: 2, name: 1592 }
{ id: 1, name: 3.14 } [T]

Size: 3
Playlist: 3 entries.
{ id: 2, name: 1592 }
{ id: 3, name: 6535 }
{ id: 1, name: 3.14 } [T]

Current: { id: 2, name: 1592 }

Size: 2
Playlist: 2 entries.
{ id: 3, name: 6535 }
{ id: 1, name: 3.14 } [T]

Size: 2
Playlist: 2 entries.
{ id: 5, name: 3238 }
{ id: 4, name: 8979 } [T]

Size: 2
Playlist: 2 entries.
{ id: 4, name: 8979 } [T]

Size: 2
Playlist: 2 entries.

Size: 2
Playlist: 2 entries.
{ id: 5, name: 3238 }
{ id: 4, name: 8979 } [T]

Size: 0
Playlist: 0 entries.

*/
