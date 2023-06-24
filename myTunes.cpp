#include <iostream>
#include <cassert>
#include <functional>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
#include "lib_songs.h"
#include "lib_avl.h"


using json = nlohmann::json;
using namespace std;

class Exception
{
public:
	Exception(const string &msg) : msg_(msg) {}
	~Exception() {}

	string getMessage() const
	{
		return (msg_);
	}

private:
	string msg_;
};

int main()
{
	AvlTree tree;
	ifstream f("data.json");
	json data = json::parse(f);
	for (auto &s : data)
	{ /* for each loop*/
		/* s is object of song class*/
		json artist = s["artist"];
		json album = s["album"];
		int id = s["id"];
		string song_name = s["name"];
		int year_of_rel = s["year"];
		string artist_name = artist["name"];
		string song_genre = artist["genre"];
		string album_name = album["name"];
		/* id, song_name, artist, album,genre,year*/
		Song song(id, song_name, artist_name, album_name, song_genre, year_of_rel);
		tree.insertSong(song);
	}
	tree.inorder();
	return 0;
}
