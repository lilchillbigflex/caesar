#include <iostream>
#include <string> 
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
 {
	int size = 1028; // выделяем место
	char sentence[1028] = {};
	bool error1 = true;
	string shift;
	bool error2 = true;
	char mode = 0;


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
			cout << "error, please use only english letters and 'space' " << endl; // если условие неудовлетворенo, выводим сообщение об ошибке (с пояснением)
	} while (error1 == false);


	do 
	{
		cout << "please enter the shift (number): ";
		cin >> shift;
		for (int i = 0; i < shift.length(); i++)
		{
			if (!( '0' <= shift[i] && shift[i] <= '9')) // проверяем введено число или же что-то другое
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
		}
	} while (error2 == false);
	int shift2 = atoi(shift.c_str()); // переводим сдвиг в числовую переменную


	while (shift2 > 26 || shift2 < 0)
	{
		cout << "please enter the shift in interval from 0 to 26 (quantity of letters in english alphabet): "; // просим ввести число сдвига
		cin >> shift2;
		if (shift2 > 26 || shift2 < 0) // проверяем введено ли число в пределах размеров английского алфавита (26 букв)
			cout << "error, "; // выводим сообщение об ошибке (сразу за ним выведется сообщение, с просьбой ввести число сдвига, из начала цикла) 
	}


	cout << "coding or decoding? please enter letters 'c' or 'd': "; // просим ввести режим (Кодировка или декодировка)
	while (mode != 'c' && mode != 'd') 
	{
		cin >> mode;
		if (mode != 'c' && mode != 'd') //проверяем введен ли один из нужных символов
			cout << "error, please enter letters 'c' or 'd': " << endl; // выводим уведомление об ошибке (с пояснением)
	}
	if (mode == 'd') 
		shift2 = 26 - shift2; // при декодировке нам нужно вернуться к изначальному символу, и так как мы после 26 возвращаемся на исходную позицию, то можем использовать ту же формулу, только используя число, которое вернет нас на исходную позицию (shift + (26 - shift) = 26)



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
		cout << "coded sentence: " << sentence << endl;   // выводим итог кодировки
	else 
		cout << "decoded sentence: " << sentence << endl; // выводим итог декодировки

	return 0;
}
