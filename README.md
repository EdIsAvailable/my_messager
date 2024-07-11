# my_messager
В качестве итогового проекта в команде с сокурсниками реализована следующая задача.

#### Условие задачи
Создан чат со следующим функционалом:
- консольная программа
- регистрация пользователей - логин, пароль, имя
- вход в чат по логину/паролю
- отправка сообщений конкретному пользователю
- обмен сообщениями между всеми пользователями чата одновременно

В чате согласно условию задания используются *классы*.

Класс *Acc* предназначенный для хранения и обработки учётных данных пользователя содержит:
- `string _pswd` - пароль пользователя;
- `string _name` - имя пользователя;
- `int _lastReadMsg` - номер последнего прочитанного пользователем сообщения из вектора сообщений;
- конструктор класса регистрирующий пользователя.

Класс *Chat* предназначенный для хранения и обработки сообщений содержит:
- `int _src_uid` - отправитель сообщения (*user id*);
- `int _dest_uid` - получатель сообщения (*user id*);
- `string _message` - тело сообщения;
- `string _dateSent` - время отправки сообщения;
- в конструктор класса добавлен функционал формирования времени отправки сообщения в *_dateSent*;
- `void ShowC()` - отобразить сообщение, которое хранится в классе
- `const int getDestUid(void)` - узнать получателя сообщения (возвращает *_dest_uid*).

*Дополнительно можно реализовать обработку исключений и использование шаблонов.*


Команда состоит из 3 человек:
- список участников команды: Эдуард Кушнир, Александр Очеретин, Евгений Сахаров;
- имя тимлида (по желанию)???;
- описание выбранной идеи решения: создаётся два вектора allusers - для учёта пользователей, вектор allmsgs - для хранения всех сообщений, где каждое сообщение как отдельный экземпляр класса Chat;
- описание пользовательских типов и функций в проекте;
- пояснение, как были распределены задачи в команде (кто какую часть проекта реализовывал): Эдуард Кушнир - регистрация пользователей, Александр Очеретин - работа с сообщениямм, Евгений Сахаров - работа с исключениями.

---
*Идея: простой месседжер с общим чатом, личными сообщениями, регистрацией и авторизацией пользователей.
Месседжер состоит из: отдельного класса User, родидельского класса Messeger классов-наследников Chat и  PrivateMsg.*