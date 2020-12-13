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
		cin.getline(sentence, size); // ñ÷èòûâàåì ñòðîêó âìåñòå ñ ïðîáåëàìè
		for (int i = 0; i < strlen(sentence); i++)
		{
			if (!('A' <= sentence[i] && sentence[i] <= 'Z') && !('a' <= sentence[i] && sentence[i] <= 'z') && sentence[i] != ' ') // ïðîâåðÿåì, âñå ëè ñèìâîëû ïðèíàäëåæàò àíãëèéñêîìó àëôàâèòó (+ ïðîáåë)
			{
				error1 = false;
				break;
			}
			else
				error1 = true;
		}
		if (error1 == false)
			cout << "error, please use only english letters and 'space' " << endl; // åñëè óñëîâèå íåóäîâëåòâîðåío, âûâîäèì ñîîáùåíèå îá îøèáêå (ñ ïîÿñíåíèåì)
	} while (error1 == false);


	do 
	{
		cout << "please enter the shift (number): ";
		cin >> shift;
		for (int i = 0; i < shift.length(); i++)
		{
			if (!( '0' <= shift[i] && shift[i] <= '9')) // ïðîâåðÿåì ââåäåíî ÷èñëî èëè æå ÷òî-òî äðóãîå
			{
				error2 = false;
				break;
			}
			else
				error2 = true;
		}
		if (error2 == false)
		{
			cout << "error, please only use numbers " << endl; // åñëè ââåäåíî ÷òî-òî êðîìå öèôð âûâîäèì ñîîáùåíèå îá îøèáêå (ñ ïîÿñíåíèåì)
		}
	} while (error2 == false);
	int shift2 = atoi(shift.c_str()); // ïåðåâîäèì ñäâèã â ÷èñëîâóþ ïåðåìåííóþ


	while (shift2 > 26 || shift2 < 0)
	{
		cout << "please enter the shift in interval from 0 to 26 (quantity of letters in english alphabet): "; // ïðîñèì ââåñòè ÷èñëî ñäâèãà
		cin >> shift2;
		if (shift2 > 26 || shift2 < 0) // ïðîâåðÿåì ââåäåíî ëè ÷èñëî â ïðåäåëàõ ðàçìåðîâ àíãëèéñêîãî àëôàâèòà (26 áóêâ)
			cout << "error, "; // âûâîäèì ñîîáùåíèå îá îøèáêå (ñðàçó çà íèì âûâåäåòñÿ ñîîáùåíèå, ñ ïðîñüáîé ââåñòè ÷èñëî ñäâèãà, èç íà÷àëà öèêëà) 
	}


	cout << "coding or decoding? please enter letters 'c' or 'd': "; // ïðîñèì ââåñòè ðåæèì (Êîäèðîâêà èëè äåêîäèðîâêà)
	while (mode != 'c' && mode != 'd') 
	{
		cin >> mode;
		if (mode != 'c' && mode != 'd') //ïðîâåðÿåì ââåäåí ëè îäèí èç íóæíûõ ñèìâîëîâ
			cout << "error, please enter letters 'c' or 'd': " << endl; // âûâîäèì óâåäîìëåíèå îá îøèáêå (ñ ïîÿñíåíèåì)
	}
	if (mode == 'd') 
		shift2 = 26 - shift2; // ïðè äåêîäèðîâêå íàì íóæíî âåðíóòüñÿ ê èçíà÷àëüíîìó ñèìâîëó, è òàê êàê ìû ïîñëå 26 âîçâðàùàåìñÿ íà èñõîäíóþ ïîçèöèþ, òî ìîæåì èñïîëüçîâàòü òó æå ôîðìóëó, òîëüêî èñïîëüçóÿ ÷èñëî, êîòîðîå âåðíåò íàñ íà èñõîäíóþ ïîçèöèþ (shift + (26 - shift) = 26)



	for (int i = 0; sentence[i] != 0; i++) // ðàññ÷èòûâàåì íîìåð ñèìâîëà, êîòîðûé áóäåò ïîñëå êîäèðîâêè/äåêîäèðîâêè       
	{
		if ('A' <= sentence[i] && sentence[i] <= 'Z')
			sentence[i] = (sentence[i] - 'A' + shift2) % 26 + 'A'; // âû÷èòàåì èç íîìåðà ñèìâîëà íîìåð À ÷òîáû ïîëó÷èòü ïîðÿäêîâûé íîìåð ñèìâîëà â àëôàâèòå, ïðèáàâëÿåì ê íåìó ÷èñëî ñäâèãà òåì ñàìûì ïîëó÷àåì íîìåð èòîãîâîãî ñèìâîëà, áåðåì îñòàòîê îò äåëåíèÿ íà 26, ÷òîáû åñëè ó íàñ íàïðèìåð íîìåð 29 ýòî ñ÷èòàëîñü êàê íîìåð 3, ïðèáàâëÿåì îáðàòíî íîìåð À ÷òîáû ïîëó÷èòü íîìåð ñèìâîëà â òàáëèöå þíèêîäà
		else if ('a' <= sentence[i] && sentence[i] <= 'z')
			sentence[i] = (sentence[i] - 'a' + shift2) % 26 + 'a';
		else if (sentence[i] == ' ')
			sentence[i] = sentence[i];
	}


	if (mode == 'c') 
		cout << "coded sentence: " << sentence << endl;   // âûâîäèì èòîã êîäèðîâêè
	else 
		cout << "decoded sentence: " << sentence << endl; // âûâîäèì èòîã äåêîäèðîâêè

	return 0;
}
