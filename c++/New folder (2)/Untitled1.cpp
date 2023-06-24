#include<iostream>
using namespace std;
class Movie{
	string title;
	string studio;
	string rating;
	public:
		static int objectCount;
		Movie(string title,string studio,string rating){
			this->title = title;
			this->studio = studio;
			this->rating = rating;
			objectCount++;
		}
		Movie(string title, string studio){
			this->title = title;
			this->studio = studio;
			rating = "PG";
			objectCount++;
		}
};
int Movie::objectCount = 0;
int main(){
	Movie a("ABC","ABC");
	return 0;
}
