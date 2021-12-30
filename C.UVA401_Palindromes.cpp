// CPE_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <stdlib.h>
using namespace std;

enum string_type {
	NORMAL, PALIN, MIRROR, MIRROR_PALIN
};

int main(void) {
	char Test_string[100];
	map<char, char> char_reverse;
	//insert element
	char_reverse.insert(pair<char, char>('A', 'A'));
	char_reverse.insert(pair<char, char>('E', '3'));
	char_reverse.insert(pair<char, char>('H', 'H'));
	char_reverse.insert(pair<char, char>('I', 'I'));
	char_reverse.insert(pair<char, char>('J', 'L'));
	char_reverse.insert(pair<char, char>('L', 'J'));
	char_reverse.insert(pair<char, char>('M', 'M'));
	char_reverse.insert(pair<char, char>('O', 'O'));
	char_reverse.insert(pair<char, char>('S', '2'));
	char_reverse.insert(pair<char, char>('T', 'T'));
	char_reverse.insert(pair<char, char>('U', 'U'));
	char_reverse.insert(pair<char, char>('V', 'V'));
	char_reverse.insert(pair<char, char>('W', 'W'));
	char_reverse.insert(pair<char, char>('X', 'X'));
	char_reverse.insert(pair<char, char>('Y', 'Y'));
	char_reverse.insert(pair<char, char>('Z', '5'));
	char_reverse.insert(pair<char, char>('1', '1'));
	char_reverse.insert(pair<char, char>('2', 'S'));
	char_reverse.insert(pair<char, char>('3', 'E'));
	char_reverse.insert(pair<char, char>('5', 'Z'));
	char_reverse.insert(pair<char, char>('8', '8'));

	while (cin >> Test_string) {
		string_type s_type = MIRROR_PALIN;
		int s_len = strlen(Test_string);

		for (int i = 0; i < s_len / 2; i++) {
			//if it's not mirror 
			if (char_reverse.find(Test_string[i]) == char_reverse.end() || char_reverse[Test_string[i]]!=Test_string[s_len-1-i]) {
				if (Test_string[i] != Test_string[s_len - 1 - i]) {
					s_type = NORMAL;
					break;
				}
				else if (s_type != PALIN) {
					s_type = PALIN;
				}
			}
			else if(char_reverse[Test_string[i]]==Test_string[s_len-1-i]){//if it's a mirror
				if (s_type != MIRROR && s_type != MIRROR_PALIN)
					continue;
				if (Test_string[i] == Test_string[s_len - 1 - i]) {
						continue;
				}
				else {
					s_type = MIRROR;
				}
			}

		}

		switch (s_type) {
			case NORMAL:
				cout << Test_string << " -- is not a palindrome."<<endl<<endl;
				break;
			case PALIN:
				cout << Test_string << " -- is a regular palindrome."<<endl<<endl;
				break;
			case MIRROR:
				cout << Test_string << " -- is a mirrored string."<<endl<<endl;
				break;
			case MIRROR_PALIN:
				cout << Test_string << " -- is a mirrored palindrome."<<endl<<endl;
				break;
		}
	}

	return 0;
}
