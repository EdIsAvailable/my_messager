#include<iostream>
#include <vector>
#include <string>
#include <time.h>
#ifndef __GCC__
#include <windows.h>
#endif // __GCC__
#include "Acc.h"
#include "Chat.h"
using namespace std;

int main()
{
#if __GCC__
	setlocale(LC_ALL, "ru_RU.UTF-8");
#else
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif // !__GCC__
	int user_id = 0; // Счётчик учётных записей пользователей
	int lastMsg = 0; // Счётчик отправленных сообщений
	
	string n_name; // Временная переменная для ввода nick name
	string u_pswd; // Временная переменная для ввода пароля
	string u_name; // Временная переменная для ФИО пользователя
	string newmsgs; // Временная переменная для ввода тела сообщения

	vector <Acc *> allusrs; // Вектор учётных записей пользователей
	vector <Chat *> allmsgs; // Вектор отправленных сообщений пользователей
	// Регистрируем виртуального пользователя с UID = 0 для общего чата
	allusrs.push_back(new Acc("public", "chat", "Общий чат"));
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
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get(); // Очистить буфер ввода перед чтением строки
			getline(cin, u_name); // Читаем строку ФИО для регистрации пользователя
			// Регистрируем пользователя - добавляем очередного пользователя в вектор
			allusrs.push_back(new Acc(n_name, u_pswd, u_name));
			// Следующий пользователь будет с ID+1
			user_id++;
			// "Отправляем тестовое сообщение регистрации пользователя" - Добавляем очередное сообщение в вектор
			//allmsgs.push_back(new Chat(user_id, 5-user_id, u_name));
			//lastMsg++; // Увеличиваем счётчик сообщений

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
						// Получение сообщений
						//cout << "У вас " << allusrs[current_uid]->getName() << " соообщений." << endl;
						// Временная переменная для вектора сообщений
						int msgId = allmsgs.size(); // Всего сообщений
						while (msgId--) {  // Обратный отсчёт
							// Проверить получателя сообщения
							if (allmsgs[msgId]->getDestUid() == current_uid || allmsgs[msgId]->getDestUid() == 0)
							{
								allmsgs[msgId]->ShowC();
							}
						}
						// Всего пользователей
						int dest_uid = (int)allusrs.size();
						cout << "Зарегистрированные пользователи, всего: " << dest_uid << " шт." << endl;
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
				cout << "Ник: \t" << allusrs[user_id]->get_Acc() << " ";  // выводим ник
				cout << "Пароль: \t" << allusrs[user_id]->get_Pswd() << " "; // выводим пароль
				cout << "ФИО: \t" << allusrs[user_id]->getName(); // выводим ФИО
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