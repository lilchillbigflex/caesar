#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> 
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#pragma warning(disable: 4018)

using namespace std;
int main()
{
	int size = 1028; // выделяем место
	char sentence[1028] = {};
	bool error1 = true;
	string shift;
	bool error2 = true;
	char mode = 0;

	ofstream logtxt;
	string way = "C:\\Users\\lilch\\Desktop\\lab1\\log.txt";
	logtxt.open(way, fstream::in | fstream::out | fstream::app);

	do
	{
		cout << "please enter the sentence: ";
		cin.getline(sentence, size); // считываем строку вместе с пробелами
		for (int i = 0; i < strlen(sentence); i++)
		{
			if (!('A' <= sentence[i] && sentence[i] <= 'Z') && !('a' <= sentence[i] && sentence[i] <= 'z') && sentence[i] != ' ') // проверяем, все ли символы принадлежат английскому алфавиту (+ пробел)
			{
				error1 = false;
				break;
			}
			else
				error1 = true;
		}
		if (error1 == false)
		{
			cout << "error, please use only english letters and 'space' " << endl; // если условие неудовлетворенo, выводим сообщение об ошибке (с пояснением)
			const int memory7 = 128;
			char log7[128];
			time_t timing7 = time(0);
			strftime(log7, memory7, "time %H:%M:%S", localtime(&timing7));
			logtxt << log7 << " | ";
			logtxt << "entered sentence with wrong symbols \n ";
		}
	} while (error1 == false);

	const int memory1 = 128;
	char log1[128];
	time_t timing1 = time(0);
	strftime(log1, memory1, "date %d:%m:%Y\ntime %H:%M:%S", localtime(&timing1));
	logtxt << log1 << " | ";
	logtxt << "entered sentence: ";
	logtxt << sentence << "\n";

	do
	{
		cout << "please enter the shift (number): ";
		cin >> shift;
		for (int i = 0; i < shift.length(); i++)
		{
			if (!('0' <= shift[i] && shift[i] <= '9')) // проверяем введено число или же что-то другое
			{
				error2 = false;
				break;
			}
			else
				error2 = true;
		}
		if (error2 == false)
		{
			cout << "error, please only use numbers " << endl; // если введено что-то кроме цифр выводим сообщение об ошибке (с пояснением)
			const int memory8 = 128;
			char log8[128];
			time_t timing8 = time(0);
			strftime(log8, memory8, "time %H:%M:%S", localtime(&timing8));
			logtxt << log8 << " | ";
			logtxt << "entered wrong shift\n ";
		}
	} while (error2 == false);
	int shift2 = atoi(shift.c_str()); // переводим сдвиг в числовую переменную


	while (shift2 > 26 || shift2 < 0)
	{
		cout << "please enter the shift in interval from 0 to 26 (quantity of letters in english alphabet): "; // просим ввести число сдвига
		cin >> shift2;
		if (shift2 > 26 || shift2 < 0) // проверяем введено ли число в пределах размеров английского алфавита (26 букв)
		{
			cout << "error, "; // выводим сообщение об ошибке (сразу за ним выведется сообщение, с просьбой ввести число сдвига, из начала цикла) 
			const int memory9 = 128;
			char log9[128];
			time_t timing9 = time(0);
			strftime(log9, memory9, "time %H:%M:%S", localtime(&timing9));
			logtxt << log9 << " | ";
			logtxt << "entered wrong shift\n ";
		}
	}

	const int memory2 = 128;
	char log2[128];
	time_t timing2 = time(0);
	strftime(log2, memory2, "time %H:%M:%S", localtime(&timing2));
	logtxt << log2 << " | ";
	logtxt << "entered shift: ";
	logtxt << shift2 << "\n";

	cout << "please choose mode (coding or decoding?) "; // просим ввести режим (Кодировка или декодировка)
	while (mode != 'c' && mode != 'd')
	{
		cout << "please enter letters 'c' or 'd': ";
		cin >> mode;
		if (mode != 'c' && mode != 'd') //проверяем введен ли один из нужных символов
		{
			cout << "error, "; // выводим уведомление об ошибке (с пояснением)
			const int memory0 = 128;
			char log0[128];
			time_t timing0 = time(0);
			strftime(log0, memory0, "time %H:%M:%S", localtime(&timing0));
			logtxt << log0 << " | ";
			logtxt << "entered wrong mode\n ";
		}
	}
	if (mode == 'd')
		shift2 = 26 - shift2; // при декодировке нам нужно вернуться к изначальному символу, и так как мы после 26 возвращаемся на исходную позицию, то можем использовать ту же формулу, только используя число, которое вернет нас на исходную позицию (shift + (26 - shift) = 26)

	const int memory3 = 128;
	char log3[128];
	time_t timing3 = time(0);
	strftime(log3, memory3, "time %H:%M:%S", localtime(&timing3));
	logtxt << log3 << " | ";
	logtxt << "entered mode: ";
	if (mode == 'c')
	{
		logtxt << "code" << endl;
	}
	else if (mode == 'd')
	{
		logtxt << "decode" << endl;
	}

	for (int i = 0; sentence[i] != 0; i++) // рассчитываем номер символа, который будет после кодировки/декодировки       
	{
		if ('A' <= sentence[i] && sentence[i] <= 'Z')
			sentence[i] = (sentence[i] - 'A' + shift2) % 26 + 'A'; // вычитаем из номера символа номер А чтобы получить порядковый номер символа в алфавите, прибавляем к нему число сдвига тем самым получаем номер итогового символа, берем остаток от деления на 26, чтобы если у нас например номер 29 это считалось как номер 3, прибавляем обратно номер А чтобы получить номер символа в таблице юникода
		else if ('a' <= sentence[i] && sentence[i] <= 'z')
			sentence[i] = (sentence[i] - 'a' + shift2) % 26 + 'a';
		else if (sentence[i] == ' ')
			sentence[i] = sentence[i];
	}


	if (mode == 'c')
	{cout << "coded sentence: " << sentence << endl;   // выводим итог кодировки
	const int memory4 = 128;
	char log4[128];
	time_t timing4 = time(0);
	strftime(log4, memory4, "time %H:%M:%S", localtime(&timing4));
	logtxt << log4 << " | ";
	logtxt << "coded sentence: ";
	logtxt << sentence << "\n";
}
	else
	{
		cout << "decoded sentence: " << sentence << endl; // выводим итог декодировки
		const int memory5 = 128;
		char log5[128];
		time_t timing5 = time(0);
		strftime(log5, memory5, "time %H:%M:%S", localtime(&timing5));
		logtxt << log5 << " | ";
		logtxt << "decoded sentence: ";
		logtxt << sentence << "\n";
	}

	const int memory6 = 128;
	char log6[128];
	time_t timing6 = time(0);
	strftime(log6, memory6, "time %H:%M:%S", localtime(&timing6));
	logtxt << log6 << " | ";
	logtxt << "end of program \n \n ";
	logtxt.close();

	return 0;
}