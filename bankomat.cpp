//***********************************************************************************************//
// Мой вариант программы банкомат.                                                               //
// Программа использует библиотеку iostream. Так компактнее.                                     //
// Работать только с цифровой клавиатурой.                                                       //
// Изменять размер базы данных банкомата можно с помощью переменной razmer в основной программе. //
// Чтобы посмотреть заполнение масивов -> убрать звездочку в строке " /*/ Смотрим... ".          //
// Варианты диалога могут дополнятся, но пока незнаю чем :)                                      //
// Накодил всё это с нуля - Сидоренко Анатолий.                                                  //
// Он же до сих пор непонимает зачем нужна * при объявлении масива :)                            //
//***********************************************************************************************//

#include <iostream>
using namespace std;

int DataBaseKartochek(int max, int* array, int size)		//Масив базы карточек
{
	int num=max;
	for (int i=0; i<size; i++)
		{
			array[i]=num;
			num ++;
		}
	return 0;
}

float DataBaseSchetov(int max, float* array, int size)			//Масив базы денег на счетах
{
	float num=max;
	for (int i=0; i<size; i++)
		{
			array[i]=num;
			num += 100;
		}
	return 0;
}

int NomerKartu(int* array, int size)				//Поиск карточки в базе
{
	int uslovie=1;
	int nomer=0,tempnomer=0;
	cout << "Vvedi nomer kartu (ot 0 do " << size << "): ";
	cin >> nomer;
	while (tempnomer!=nomer)								// Повтор ввода номера для поиска
	{
		for (int i=0; i<size; i++)
		{
			if (array[i]==nomer) 
				{
					tempnomer=nomer;
					return tempnomer;
				}
		}
	cout << "Takogo nomera nety. Povtorite vvod: ";
	cin >> nomer;
	}
	//cout << "Done." << endl;
	return nomer;
}

float Balance(int* arrayKart, float* arraySchet, int Kartochka, int size)		//Отображение баланса на карточке
{
	for (int i=0; i<size; i++)
		if (arrayKart[i]==Kartochka)
			{cout << "Na schety: " << arraySchet[i] << endl << endl;}
	return 0;
}

float Nalichka(int* arrayKart, float* arraySchet, int Kartochka, int size)	//Вывод денег
{
	float summa=0;
	cout << "Vvedite symmy: ";
	cin >> summa;
	for (int i=0; i<size; i++)
		if (arrayKart[i]==Kartochka)
			{
				cout << "Vozmite dengi." << endl << endl;
				arraySchet[i]=arraySchet[i]-summa;
				//cout << endl << arraySchet[i] << endl;
			}
	return 0;
}

int Interface(int* arrayK, float* arrayS, int Nomer, int Razmer)			//Диалоговое меню
{
	int variant=0;
	cout << endl << "Karta podtvergdena!" << endl << endl;
	do
	{
		cout << "(----------------------------)" << endl << endl;
		cout << "1 - Proverit schet" << endl << "2 - Vidat dengi" << endl << "3 - Vuhod" << endl;
		cout << endl <<  "Vuberite deistvie: ";
		cin >> variant;
		cout << "(----------------------------)" << endl << endl;
		switch (variant)
		{
	
			case 1: {Balance(arrayK,arrayS,Nomer,Razmer); break;}
			case 2: {Nalichka(arrayK,arrayS,Nomer,Razmer); break;}
			case 3: {break;}
		default: {cout << "Takogo varianta nety. Povtorite vvod." << endl << endl;}
		}
	}
	while (variant!=3);
	return 0;
}

int main()
{
	cout << "\t*********************" << endl;
	cout << "\t*   Bank Smile!     *" << endl;
	cout << "\t* Privetstvyem vas! *" << endl;
	cout << "\t*********************" << endl << endl;
	int razmer = 10;							//Размер базы данных
	float BasaSchetov[10];
	int NomerK;
	BasaSchetov[razmer]=DataBaseSchetov(100,BasaSchetov,razmer); //Создаем масив с деньгами
	int BasaKart[10];
	BasaKart[razmer]=DataBaseKartochek(1,BasaKart,razmer);		//Создаем масив базы карточек
	
	/*/ Смотрим наполненость масивов	
	// ==========================
	for (int i=0; i<razmer; i++)
		cout << BasaSchetov[i] << endl;
	cout << endl;
	for (int i=0; i<razmer; i++)
		cout << BasaKart[i] << endl;
	// ==========================/*/

	NomerK = NomerKartu(BasaKart,razmer);			//Запрашиваем и проверяем номер карточки
	
	Interface(BasaKart,BasaSchetov,NomerK,razmer);		//Выводим интерфейс выбора действия
	BasaKart[10]=0;
	cout << endl << "Spasibo za doverie." << endl;
	return 0;
}