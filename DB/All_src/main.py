import psycopg2
conn = psycopg2.connect(dbname='sekiro', user='postgres',
                        password='Rem002Kyoku', host='localhost', port=5444)

cur = conn.cursor()
def print_data(cur):
    for line in cur:
        for elem in line:
            print(elem, end=' ')
        print()

f = open('title.sql', 'r')
cur.execute(f.read())
print_data(cur)
cur.close()

if conn.closed:
    print('Соединение отсутствует.')
else:
    cur = conn.cursor()

    choice = None

    while choice != '0':
        print('''   МЕНЮ
        1. Выполнить скалярный запрос;
        2. Выполнить запрос с несколькими соединениями (JOIN);
        3. Выполнить запрос с ОТВ(CTE) и оконными функциями;
        4. Выполнить запрос к метаданным;
        5. Вызвать скалярную функцию (написанную в третьей лабораторной работе);
        6. Вызвать многооператорную или табличную функцию (написанную в третьей лабораторной работе);
        7. Вызвать хранимую процедуру (написанную в третьей лабораторной работе);
        8. Вызвать системную функцию или процедуру;
        9. Создать таблицу в базе данных, соответствующую тематике БД;
        10. Выполнить вставку данных в созданную таблицу с использованием инструкции INSERT или COPY.
        0. Выход
        ''')

        choice = input('Выбор: ')
        try:
            if choice == '1':
                first_in = input('Введите нижнюю границу Серий: ')
                second_in = input('Введите верхнюю границу Серий: ')
                cur.execute('''
                                SELECT *
                                FROM Title
                                WHERE count_of_episodes BETWEEN %s and %s;
                            ''', (first_in, second_in))
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '2':
                lab = input('Введите название Студио: ')
                cur.execute('''
                                SELECT T.id, T.name, T.genres_of_anime, T.count_of_episodes, S.name
                                FROM Title AS T join Studio as S on T.studio_creator = S.studio_id join Role as R on R.anime = T.id
                                WHERE S.name=%(LR)s
                                ORDER BY T.id;
                            ''', {'LR': lab})
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '3':
                cur.execute('''
                                WITH CTE (TID, nam, avgcount, mincount, maxcount, gen, typ)
                                AS
                                (
                                    SELECT T.ID, T.name, (select AVG(T.count_of_episodes) from title as T  where T.genres_of_anime like '%Seinen%') , (select MIN(T.count_of_episodes) from title as T  where T.genres_of_anime like '%Seinen%'),(select MAX(T.count_of_episodes) from title as T  where T.genres_of_anime like '%Seinen%'), T.genres_of_anime, T.type_of_title
                                    FROM Title AS T
                                    where T.genres_of_anime like '%Seinen%'
                                    GROUP BY T.ID, T.name, T.count_of_episodes, T.genres_of_anime, T.type_of_title
                                )
                                SELECT TID, nam, avgcount, gen, typ,
                                min(MINcount) OVER (PARTITION BY nam, gen, typ) AS minavg,
                                max(MAXcount) OVER (PARTITION BY nam, gen, typ) AS maxavg
                                FROM CTE;
                            ''')
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '4':
                cur.execute('''
                                SELECT proname, proargnames, prokind
                                FROM pg_proc AS pr JOIN information_schema.routines AS r ON pr.proname = r.routine_name
                                WHERE r.specific_schema = 'public';
                            ''')
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '5':
                print('Название первого тайтла в котором присутствует жанр Seinen: ')
                cur.execute('''
                                select * from get_name_of_seinen();
                            ''')
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '6':
                in_id = input ('Введите id тайтла, жанры которого будут выведены:')
                cur.execute('''
                                SELECT *
                                FROM get_genres_of_anime_by_id(%(in_id)s);
                            ''', {'in_id' : in_id})
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '7':
                #887
                t_id = input('Введите id тайтла, чью студию хотите поменять:')
                b_id = input('Введите id нынешней студии:')
                a_id = input('Введите id будущей студии:')
                cur.execute('''
                                call update_studio_title(%(t_id)s, %(b_id)s, %(a_id)s);
                                select * from title where id = %(t_id)s;
                            ''', {'t_id' : t_id, 'b_id' : b_id, 'a_id' : a_id})
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '8':
                cur.execute('''
                                SELECT current_database(), current_user, pg_backend_pid();
                            ''')
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '9':
                cur.execute('''
                                CREATE TABLE Replacement
                                (
                                    ID int generated always as identity,
                                    TitleID int NOT NULL,
                                    ReplacingID int NOT NULL
                                );
                            ''')

            elif choice == '10':
                cur.execute('''
                                INSERT INTO Replacement (TitleID, ReplacingID) VALUES (1, 29);
                                INSERT INTO Replacement (TitleID, ReplacingID) VALUES (3, 34);
                                INSERT INTO Replacement (TitleID, ReplacingID) VALUES (12, 22);
                                INSERT INTO Replacement (TitleID, ReplacingID) VALUES (14, 49);
                                INSERT INTO Replacement (TitleID, ReplacingID) VALUES (7, 33);
                                INSERT INTO Replacement (TitleID, ReplacingID) VALUES (44, 11);
                                INSERT INTO Replacement (TitleID, ReplacingID) VALUES (32, 13);
                                INSERT INTO Replacement (TitleID, ReplacingID) VALUES (21, 16);
                            ''')

            elif choice == '0':
                #conn.commit()

                cur.close()

                conn.close()

            else:
                print('Неверный ввод. Попробуйте еще раз.')
        except psycopg2.Error as e:
            print(e.pgerror)
            print('Попробуйте другие входные данные или другой пункт.')
            cur.close()
            conn.close()

            conn = psycopg2.connect(database='sekiro',
                       user='postgres',
                       password='Rem002Kyoku',
                       host='localhost', port=5444)
            cur = conn.cursor()
            f = open('title.sql', 'r')
            cur.execute(f.read())
            cur.close()
            cur = conn.cursor()
            pass

