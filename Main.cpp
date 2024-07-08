#include<iostream>
#include <vector>
#include <string>
#include <time.h>
#include "Acc.h"
#include "Chat.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int user_id = 0;
	int lastMsg = 0;
	Acc* usr[2]; // минммум 2 юзера
	Chat* cht[2];
	string n_name;
	string u_pswd;
	string u_name;
	string newmsgs;
	string nwadr;
	usr[0] = new Acc((n_name),(u_pswd),(u_name));
	//cht[0] = new Chat((newmsgs),(nwadr));
	//cht[0] = new Chat(0, 0,(newmsgs));
	vector <Acc *> allusrs;
	allusrs.push_back(usr[0]);
	vector <Chat *> allmsgs;
	//allmsgs.push_back(cht[0]);
	char switchLogon = 'w'; // , switchLogoff;
	time_t t; // Определяем переменные для работы с датой и временем
	struct tm *t_m;

	while (switchLogon != 'q')
	{
		cout <<"Создать аккаунт введите: 'c'" << endl;
		cout <<"Авторизоваться введите:  'l'" << endl;
		cout <<"Для выхода введите:  'q'" << endl;
		std::cin >> switchLogon;
		switch(switchLogon)
		{
		case 'c':
		{
			std::cout << "придумайте никнейм " << endl;
			std::cin >> n_name;
			//usr[0]->set_Acc((n_name));

			std::cout << "создайте пароль " << endl;
			std::cin >> u_pswd;
			//usr[0]->set_Pswd((u_pswd));
			//usr[0]->Show();

			std::cout << "укажите ваше имя: ";
			std::cin >> u_name;
			//usr[0]->set_Acc((n_name));

		
			//usr[user_id] = new Acc(n_name, u_pswd, u_name);
			allusrs.push_back(new Acc(n_name, u_pswd, u_name));
			// Следующий пользователь будет с ID+1
			user_id++;
			t = time(NULL);
			t_m = localtime(&t);
			//string msgTime = " " + (t_m->tm_mday) + "." + (t_m->tm_mon+1) + "." + (t_m->tm_year+1900) + " ";
			//string msgTime =  std::format (" %d.%d.%d ", t_m->tm_mday, t_m->tm_mon+1, t_m->tm_year+1900);
			string msgTime = 	" " + std::to_string(t_m->tm_mday) + "-" + std::to_string(t_m->tm_mon+1) + "-" + std::to_string(t_m->tm_year+1900) + 
								" " + std::to_string(t_m->tm_hour) + ":" + std::to_string(t_m->tm_min) + ":" + std::to_string(t_m->tm_sec);
			allmsgs.push_back(new Chat(user_id, 5-user_id, (u_name), msgTime));  // Добавляем очередное сообщение в вектор
			lastMsg++; // Увеличиваем счётчик сообщений

			break;
		}
		case 'l':
		{
			std::cout << "введите никнейм " << endl;
			std::cin >> n_name;
			for (int i=0; i < sizeof usr[0]; i++)
			{
				if (n_name == n_name)
				{
					std::cout << "введите пароль " << endl;
					std::cin >> u_pswd;
				
					if (u_pswd == u_pswd)// тут пока не пойму как пароль сверить
					{
						// start messeging

					}
				}
				else
				{
					// переход в начало к авторизуйтесь
				}

			}
			
			break;
		}
		case 'q':
		{
			//allmsgs.push_back(cht[0]);
			//std::vector<int> data = {1, 2, 3, 4, 5};
			//for (int elem : data) {
			//	std::cout << elem << " ";
			//}
			//std::cout << "\n";

			//int x;
			//std::vector<int> data;
			int msgId = user_id;
			while (msgId--) {  // читаем числа, пока не закончится ввод
				allmsgs[msgId]->ShowC();  // добавляем очередное число в вектор
			}

			cout << "Всего сообщений в базе: " << allmsgs.size() << endl;
			while (user_id--) {
				// Пока вектор не пуст и последний элемент равен нулю

				cout << "ник: " << allusrs[user_id]->get_Acc() << " ";  // проверить ник
				cout << "пароль: ";
				//allusrs[user_id]->Show();
				cout << " ";  // проверить пароль
				cout << endl;

			}

			cout << "ник: " << allusrs[0]->get_Acc() << endl;  // проверить ник
			cout << "ник: " << allusrs[1]->get_Acc() << endl;  // проверить ник
			cout << "ник: " << allusrs[2]->get_Acc() << endl;  // проверить ник

			cout << "Всего пользователей зарегистрировано: " << allusrs.size() << endl;

			std::cout << "До встречи! Завершение работы..." << endl;
			break;
		}
			
		default:
			break;
		}

	}
	
	
	
	delete usr[0];
	delete cht[0];
	return 0;
};