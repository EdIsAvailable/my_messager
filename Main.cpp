#include<iostream>
#include <vector>
#include <string>
#include <time.h>
#include "Acc.h"
#include "Chat.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS для localtime
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int user_id = 0; // Счётчик учётных записей пользователей
	int lastMsg = 0; // Счётчик отправленных сообщений

	string n_name; // Пере
	string u_pswd;
	string u_name;
	string newmsgs;
	vector <Acc *> allusrs; // Вектор учётных записей пользователей
	vector <Chat *> allmsgs; // Вектор отправленных сообщений пользователей
	char switchLogon = 'w'; // Выбор режима работы w - work / c - create user / l - login user / q - quit
	time_t t; // Определяем переменные для работы с датой и временем
	struct tm *t_m;

	while (switchLogon != 'q')
	{
		cout <<"Создать аккаунт введите: 'c'" << endl;
		cout <<"Авторизоваться введите:  'l'" << endl;
		cout <<"Для выхода введите:  'q'" << endl << endl;
		std::cin >> switchLogon;
		switch(switchLogon)
		{
		case 'c':
		{
			std::cout << "Придумайте никнейм: ";
			std::cin >> n_name;

			std::cout << "Создайте пароль: ";
			std::cin >> u_pswd;

			std::cout << "Укажите ваше имя: ";
			std::cin >> u_name;
			// Регистрируем пользователя - добавляем очередного пользователя в вектор
			allusrs.push_back(new Acc(n_name, u_pswd, u_name));
			// Следующий пользователь будет с ID+1
			user_id++;
			// Подготавливаем дату и время
			t = time(NULL);
			t_m = localtime(&t);
			// Формируем дату и время отправки сообщения
			string msgTime = 	" " + std::to_string(t_m->tm_mday) + "-" + std::to_string(t_m->tm_mon+1) + "-" + std::to_string(t_m->tm_year+1900) + 
								" " + std::to_string(t_m->tm_hour) + ":" + std::to_string(t_m->tm_min) + ":" + std::to_string(t_m->tm_sec);
			// "Отправляем сообщение" - Добавляем очередное сообщение в вектор
			allmsgs.push_back(new Chat(user_id, 5-user_id, u_name, msgTime));
			lastMsg++; // Увеличиваем счётчик сообщений

			break;
		}
		case 'l':
		{
			std::cout << "Ведите никнейм: ";
			std::cin >> n_name;
			// Перебор зарегистрированных пользователей из вектора для поиска логина (n_name)
			for (size_t i = 0; i < allusrs.size(); i++)
			{
				if (n_name == allusrs[i]->get_Acc())
				{
					int current_uid = i;
					std::cout << "Введите пароль: ";
					std::cin >> u_pswd;
					// Провреряем введённый пароль на соответствие учётной записи из вектора пользователей
					if (u_pswd == allusrs[i]->get_Pswd())
					{
						cout << "Введите сообщение: ";
						cin.get();
						getline(cin, newmsgs); //std::cin >> newmsgs;
						// Подготавливаем дату и время
						t = time(NULL);
						t_m = localtime(&t);
						// Формируем дату и время отправки сообщения
						string msgTime =" " + std::to_string(t_m->tm_mday) + "-" + std::to_string(t_m->tm_mon+1) + "-" + std::to_string(t_m->tm_year+1900) + 
										" " + std::to_string(t_m->tm_hour) + ":" + std::to_string(t_m->tm_min) + ":" + std::to_string(t_m->tm_sec);
						// "Отправляем сообщение" - Добавляем очередное сообщение в вектор
						allmsgs.push_back(new Chat(current_uid, 5-user_id, newmsgs, msgTime));
						lastMsg++; // Увеличиваем счётчик сообщений

					} else {
						cout << "Пароль не корректен!" << endl << endl;
					}
				}
			}
			
			break;
		}
		case 'q':
		{
			// Временная переменная для тестирования вектора сообщений
			int msgId = allmsgs.size(); //user_id;
			// Количество сообщений равно количеству зарегистрированных пользователей в данном тесте
			while (msgId--) {  // Обратный отсчёт
				allmsgs[msgId]->ShowC();  // Выводим содержимое вектора сообщений
			}

			cout << "Всего сообщений в базе: " << allmsgs.size() << endl;
			while (user_id--) {
				// Пока вектор не пуст и последний элемент равен нулю
				cout << "ник: " << allusrs[user_id]->get_Acc() << " ";  // проверить ник
				cout << "пароль: " << allusrs[user_id]->get_Pswd() << " "; // проверить пароль
				//allusrs[user_id]->Show();				
				cout << endl;
			}

			// cout << "ник: " << allusrs[0]->get_Acc() << endl;  // проверить ник
			// cout << "ник: " << allusrs[1]->get_Acc() << endl;  // проверить ник
			// cout << "ник: " << allusrs[2]->get_Acc() << endl;  // проверить ник
			cout << "Всего пользователей зарегистрировано: " << allusrs.size() << endl;
			std::cout << "До встречи! Завершение работы..." << endl;
			break;
		}
			
		default:
			break;
		}

	}
	
	//delete usr[0];
	//delete cht[0];
	return 0;
};