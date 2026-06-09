#include <iostream>
#include<Windows.h>
#include<fstream>
#include <string>
#include <vector>


using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::endl;
using std::cin;


struct note {

	int freq;
	int duration;
};

vector<note> theMusic;
vector<int> f, d;

string input();
void title();
void LoadSong(vector<note>& S, ifstream& fileinput);
void player(const vector<note>& Music);

int main() {

	title();
	string theSong = input();
	ifstream fileinput(theSong);
	if (!fileinput.is_open()) {
		cout << theSong << "cannot be found"<< endl;
		exit(0);

	}
	LoadSong(theMusic, fileinput);
	player(theMusic);

}

void title() {

	cout << "Music Player\n";
	cout << "--------------\n";

}

string input() {

	cout << "Enter music File: " << endl;
	string songname;
	cin >> songname;
	return songname;

}

void LoadSong(vector<note>& S, ifstream& fileinput) {
	int freq, duration;
	do {
		fileinput >> freq >> duration;
		note temp;
		temp.freq = freq;
		temp.duration = duration;
		f.push_back(temp.freq);
		d.push_back(temp.duration);
	} while (!fileinput.eof());

	fileinput.close();

}

void player(const vector<note>& Music) {
	for (int i = 0; i < f.size(); ++i) {
		cout << f[i] << " " << d[i] << endl;
		Beep(f[i], d[i]);
	}
}