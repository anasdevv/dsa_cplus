#include<iostream>
#include <cassert>
#include <functional>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
#include "lib_songs.h"
#include "lib_avl.h"
#include "lib_linkedList.h"

using namespace std;
class Playlist{
	int playlistId;
	string playlistName;
	DoublyLinkedList<Song> songs;
	public:
		Playlist(){};
		void addSong(Song s){
			songs.push(s);
		}
		void displayAllSongs(){
			songs.displayList();
		}
};
