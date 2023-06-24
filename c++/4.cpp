#include<fstream>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class Voter{
	int id;
	string vote;

	public:
		Voter(int id,string vote){
			ofstream f;
			f.open("votes.txt",ios::app);
			this->id = id;
			this->vote = vote;
			f << id << " " << vote << "\n";
			f.close();
		}
		Voter(string vote,int id){
			this->vote = vote;
			this->id = id;
		}
		void getVoteDetails(int n){
			n--;
		ifstream g;
		g.open("votes.txt");	
			string s;
			int id;
			while(g){
				g >> id >> s;
				if(id == this->id){
					cout << "Your Vote For Option " << n + 1 << " Was" << s[n] << endl;
					break;
				}
			}
		}
		void display(){
			cout << id << "\t" << vote << endl;
		}
};
int main(){
	
	Voter v1(4925,"CDGH");
	Voter v2(4926,"AEGH");
	Voter v3(4927,"CDGI");
	Voter v4(4928,"BEGI");
	Voter v5(4929,"ADFH");
	v5.getVoteDetails(2);
	ifstream w;
	w.open("votes.txt");
	int id;
	string vote;
	vector <Voter> voters;
	while(w){
		w >> id >> vote;
	voters.push_back(Voter(vote,id));
	}
 w.close();
	for(auto it = voters.begin() ; it != voters.end() ; it++){
		it->display();
	}
}
