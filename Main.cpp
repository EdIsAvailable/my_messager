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
	
	string n_name; // Временная переменная для ввода nick name
	string u_pswd; // Временная переменная для ввода пароля
	string u_name; // Временная переменная для ФИО пользователя
	string newmsgs; // Временная переменная для ввода тела сообщения

	vector <Acc *> allusrs; // Вектор учётных записей пользователей
	vector <Chat *> allmsgs; // Вектор отправленных сообщений пользователей
	// Регистрируем виртуального пользователя с UID = 0 для общего чата
	allusrs.push_back(new Acc("n_name", "u_pswd", "Общий чат"));
	// Следующий пользователь будет с ID+1
	user_id++;
	char switchLogon = 'w'; // Выбор режима работы w - work / c - create user / l - login user / q - quit

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
			// "Отправляем сообщение" - Добавляем очередное сообщение в вектор
			allmsgs.push_back(new Chat(user_id, 5-user_id, u_name));
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
					// Проверяем введённый пароль на соответствие учётной записи из вектора пользователей
					if (u_pswd == allusrs[i]->get_Pswd())
					{
						int dest_uid = (int)allusrs.size();
						cout << "Зарегистрированные пользователи, всего: " << dest_uid << "человек." << endl;
						while (dest_uid--) {
							// Выводим список зарегистрированных пользователей, пока вектор не пуст и последний элемент равен нулю
							cout << dest_uid << ".\tИмя: \t\t" << allusrs[dest_uid]->getName();  // вывести имя
							cout << endl;
						}
						std::cout << "Выберите адресата сообщения от 0 (общий чат) до " << (allusrs.size()-1) << ": ";
						std::cin >> dest_uid; // Указываем адресата сообщения
						
						cout << "Введите сообщение: ";
						cin.get(); // Очистить буфер ввода перед чтением строки
						getline(cin, newmsgs); // Читаем строку тела сообщения для отправки
						// "Отправляем сообщение" - Добавляем очередное сообщение в вектор
						allmsgs.push_back(new Chat(current_uid, dest_uid, newmsgs));
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
				cout << "Ник: " << allusrs[user_id]->get_Acc() << " ";  // проверить ник
				cout << "Пароль: " << allusrs[user_id]->get_Pswd() << " "; // проверить пароль
				//allusrs[user_id]->Show();				
				cout << endl;
			}

			cout << "Всего пользователей зарегистрировано: " << allusrs.size() << endl;
			std::cout << "До встречи! Завершение работы..." << endl;
			break;
		}
			
		default:
			break;
		}
	}

	return 0;
};