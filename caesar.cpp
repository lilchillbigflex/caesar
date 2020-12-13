#include <iostream>
#include <string> 
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
 {
	int size = 1028; // �������� �����
	char sentence[1028] = {};
	bool error1 = true;
	string shift;
	bool error2 = true;
	char mode = 0;


	do 
	{
		cout << "please enter the sentence: ";
		cin.getline(sentence, size); // ��������� ������ ������ � ���������
		for (int i = 0; i < strlen(sentence); i++)
		{
			if (!('A' <= sentence[i] && sentence[i] <= 'Z') && !('a' <= sentence[i] && sentence[i] <= 'z') && sentence[i] != ' ') // ���������, ��� �� ������� ����������� ����������� �������� (+ ������)
			{
				error1 = false;
				break;
			}
			else
				error1 = true;
		}
		if (error1 == false)
			cout << "error, please use only english letters and 'space' " << endl; // ���� ������� ��������������o, ������� ��������� �� ������ (� ����������)
	} while (error1 == false);


	do 
	{
		cout << "please enter the shift (number): ";
		cin >> shift;
		for (int i = 0; i < shift.length(); i++)
		{
			if (!( '0' <= shift[i] && shift[i] <= '9')) // ��������� ������� ����� ��� �� ���-�� ������
			{
				error2 = false;
				break;
			}
			else
				error2 = true;
		}
		if (error2 == false)
		{
			cout << "error, please only use numbers " << endl; // ���� ������� ���-�� ����� ���� ������� ��������� �� ������ (� ����������)
		}
	} while (error2 == false);
	int shift2 = atoi(shift.c_str()); // ��������� ����� � �������� ����������


	while (shift2 > 26 || shift2 < 0)
	{
		cout << "please enter the shift in interval from 0 to 26 (quantity of letters in english alphabet): "; // ������ ������ ����� ������
		cin >> shift2;
		if (shift2 > 26 || shift2 < 0) // ��������� ������� �� ����� � �������� �������� ����������� �������� (26 ����)
			cout << "error, "; // ������� ��������� �� ������ (����� �� ��� ��������� ���������, � �������� ������ ����� ������, �� ������ �����) 
	}


	cout << "coding or decoding? please enter letters 'c' or 'd': "; // ������ ������ ����� (��������� ��� �����������)
	while (mode != 'c' && mode != 'd') 
	{
		cin >> mode;
		if (mode != 'c' && mode != 'd') //��������� ������ �� ���� �� ������ ��������
			cout << "error, please enter letters 'c' or 'd': " << endl; // ������� ����������� �� ������ (� ����������)
	}
	if (mode == 'd') 
		shift2 = 26 - shift2; // ��� ����������� ��� ����� ��������� � ������������ �������, � ��� ��� �� ����� 26 ������������ �� �������� �������, �� ����� ������������ �� �� �������, ������ ��������� �����, ������� ������ ��� �� �������� ������� (shift + (26 - shift) = 26)



	for (int i = 0; sentence[i] != 0; i++) // ������������ ����� �������, ������� ����� ����� ���������/�����������       
	{
		if ('A' <= sentence[i] && sentence[i] <= 'Z')
			sentence[i] = (sentence[i] - 'A' + shift2) % 26 + 'A'; // �������� �� ������ ������� ����� � ����� �������� ���������� ����� ������� � ��������, ���������� � ���� ����� ������ ��� ����� �������� ����� ��������� �������, ����� ������� �� ������� �� 26, ����� ���� � ��� �������� ����� 29 ��� ��������� ��� ����� 3, ���������� ������� ����� � ����� �������� ����� ������� � ������� �������
		else if ('a' <= sentence[i] && sentence[i] <= 'z')
			sentence[i] = (sentence[i] - 'a' + shift2) % 26 + 'a';
		else if (sentence[i] == ' ')
			sentence[i] = sentence[i];
	}


	if (mode == 'c') 
		cout << "coded sentence: " << sentence << endl;   // ������� ���� ���������
	else 
		cout << "decoded sentence: " << sentence << endl; // ������� ���� �����������

	return 0;
}