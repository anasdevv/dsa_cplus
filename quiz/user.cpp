#include<iostream>
#include <cassert>
#include <functional>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
#include "lib_songs.h"
#include "lib_avl.h"
#include "lib_playlist.h"
class User{
	int id;
	string role;
	DoublyLinkedList<Playlist> playlists;
};
