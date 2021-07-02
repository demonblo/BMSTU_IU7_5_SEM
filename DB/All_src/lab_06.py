import psycopg2

con = psycopg2.connect(database='sekiro',
                       user='postgres',
                       password='Rem002Kyoku',
                       host='localhost', port=5444)

if con.closed:
    print('Соединение отсутствует.')
else:
    cur = con.cursor()

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
                # (МКТ-2)
                lab = input('Введите название Студио: ')
                cur.execute('''
                                SELECT T.id, T.name, T.genres_of_anime, T.count_of_episodes
                                FROM Title AS T
                                WHERE id < 10
                                ORDER BY T.id;
                            ''', {'LR': lab})
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '3':
                cur.execute('''
                                WITH CTE (SID, avgmark, fac, dep, gr)
                                AS
                                (
                                    SELECT S.StudentID, AVG(M.mark), S.faculty, S.department, S."number of group"
                                    FROM Students AS S JOIN Marks AS M ON S.StudentID = M.StudentID
                                    GROUP BY S.faculty, S.department, S."number of group", S.StudentID
                                )
                                SELECT SID, fac, dep, gr, avgmark,
                                AVG(avgmark) OVER (PARTITION BY fac, dep, gr) AS sumavg,
                                MIN(avgmark) OVER (PARTITION BY fac, dep) AS minavg,
                                MAX(avgmark) OVER (PARTITION BY fac, dep) AS maxavg
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
                # ФН 4 21
                fac = input('Введите название факультета: ')
                dep = input('Введите номер кафедры: ')
                gr_no = input('Введите номер группы: ')
                cur.execute('''
                                SELECT StudentID, scalar(%(fac)s, %(dep)s, %(gr_no)s)
                                FROM Students
                                WHERE faculty = %(fac)s AND department = %(dep)s and "number of group" = %(gr_no)s; 
                            ''', {'fac': fac, 'dep': dep, 'gr_no': gr_no})
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '6':
                cur.execute('''
                                SELECT *
                                FROM inlineTable1() AS (a int, b varchar, c varchar);
                            ''')
                for row in cur.fetchall():
                    for i in range(len(row)):
                        print(row[i], end=' ')
                    print()

            elif choice == '7':
                cur.execute('''
                                CALL GetAvg();
                            ''')
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
                                    TitleID int references Title(id),
                                    ReplacingID int references Title(id)
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
                #con.commit()

                cur.close()

                con.close()

            else:
                print('Неверный ввод. Попробуйте еще раз.')
        except psycopg2.Error as e:
            print(e.pgerror)
            print('Попробуйте другие входные данные или другой пункт.')
            cur.close()
            con.close()

            con = psycopg2.connect(database='sekiro',
                       user='postgres',
                       password='Rem002Kyoku',
                       host='localhost', port=5444)
            cur = con.cursor()
            pass
