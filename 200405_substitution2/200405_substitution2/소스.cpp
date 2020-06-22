#include <iostream>
#include <random>
using namespace std;

string encryption(string text) {
	string result = "";
	int seedc, seeda;
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<> capital(65, 90);
	std::uniform_int_distribution<> small(97, 122);

	for (int i = 0; i < text.length(); i++) {
		seedc = capital(mersenne);
		seeda = small(mersenne);
		if (isupper(text[i])) {
			result += char(int(text[i] + seedc) % 26 + 65);
		}
		else
			result += char(int(text[i] + seeda) % 26 + 97);
	}
	return result;
}

int main() {
	string text = "";
	cout << "다중 치환 암호" << endl;
	cout << "평문 입력(대소문자 구분) : ";
	cin >> text;
	cout << "암호문 : " << encryption(text) << endl;

	return 0;
}