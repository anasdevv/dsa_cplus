#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	ofstream outfile("FileData.txt");
	outfile << 1<< " " << 2 << " "<<  3 << " "<< 5;
	string str = "sdjfsjkdjfsdlrj3l4lksekl e lrskelrk lkj\nfjaksjfkajkf24skdjfjkkjf\n";
	for(int i = 0 ; i < str.length() ; i++)
		outfile.put(str[i]);
	outfile.close();
}
