#include <iostream>
using namespace std;
/*song class*/

class Song
{
private:
	int id;
	int year_of_release;
	string song_name;
	string artist_name;
	string album_name;
	string song_genre;

public:
	Song(){};
	~Song(){};
	Song(int id, string song_name, string artist_name, string album_name, string song_genre, int year_of_release);

	void set_id(int id);
	void set_song_name(string song_name);
	void set_artist_name(string artist_name);
	void set_album_name(string album_name);
	void set_song_genre(string song_genre);
	void set_year_of_release(int year_of_release);
	int get_id();
	string get_song_name();
	string get_artist_name();
	string get_album_name();
	string get_song_genre();
	int get_year_of_release();
	void print_song();


};
/* constructor*/
Song::Song(int id, string song_name, string artist_name, string album_name, string song_genre, int year_of_release)
{
	this->id = id;
	this->song_name = song_name;
	this->artist_name = artist_name;
	this->album_name = album_name;
	this->song_genre = song_genre;
	this->year_of_release = year_of_release;
}

// setters
void Song::set_id(int id)
{
	this->id = id;
}
void Song::set_song_name(string song_name)
{
	this->song_name = song_name;
}
void Song::set_artist_name(string artist_name)
{
	this->artist_name = artist_name;
}
void Song::set_album_name(string album_name)
{
	this->album_name = album_name;
}
void Song::set_song_genre(string song_genre)
{
	this->song_genre = song_genre;
}
void Song::set_year_of_release(int year_of_release)
{
	this->year_of_release = year_of_release;
}

// getters
int Song::get_id()
{
	return id;
}
string Song::get_song_name()
{
	return song_name;
}
string Song::get_artist_name()
{
	return artist_name;
}
string Song::get_album_name()
{
	return album_name;
}
string Song::get_song_genre()
{
	return song_genre;
}
int Song::get_year_of_release()
{
	return year_of_release;
}

void Song::print_song()
{
	cout << endl
		 << endl;
	cout << "id: " << this->id << endl;
	cout << "Song Name: " << this->song_name << endl;
	cout << "Artist: " << this->artist_name << endl;
	cout << "Album: " << this->album_name << endl;
	cout << "Song Genre: " << this->song_genre << endl;
	cout << "Year Of Release : " << this->year_of_release << endl;
	cout << endl;
}