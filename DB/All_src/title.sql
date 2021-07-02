CREATE TABLE if not exists Studio (
      Studio_id SERIAL NOT NULL PRIMARY KEY,
      name VARCHAR(60) NOT NULL
);

copy Studio(name) from '/Users/demonblo/Desktop/DB/studios.csv' delimiter ',' csv;

CREATE TABLE if not exists Title (
      id SERIAL NOT NULL PRIMARY KEY,
      name VARCHAR(200) NOT NULL,
      genres_of_anime VARCHAR(1000) NOT NULL,
      type_of_title VARCHAR(60) NOT NULL,
      count_of_episodes int NOT NULL,
      Studio_creator int references Studio(Studio_id) not null
);

copy Title(name, genres_of_anime, type_of_title, count_of_episodes, Studio_creator) from '/Users/demonblo/Desktop/DB/titles.csv' delimiter ',' csv;

CREATE TABLE if not exists Author (
      Author_id SERIAL NOT NULL PRIMARY KEY,
      name VARCHAR(60) NOT NULL,
      count_of_titles INT NOT NULL
);

copy Author(name, count_of_titles) from '/Users/demonblo/Desktop/DB/names.csv' delimiter ',' csv;

create table if not exists Role (
	anime int references Title(id) not null,
	worker int references Author(Author_id) not null,
	role varchar (20) NOT NULL
);

copy Role(anime, worker, role) from '/Users/demonblo/Desktop/DB/roles.csv' delimiter ',' csv;

--15 Insert
--INSERT into Title(name, genres_of_anime, type_of_title, count_of_episodes, Studio_creator)
--Values('Naruto shippuden 2', 'Seinen, Drama, Action', 'TV', 300, 2);
--select * from Title

--16 Многострочная инструкция INSERT, выполняющая вставку в таблицу результирующего набора данных вложенного подзапроса.
--INSERT into Title(name, genres_of_anime, type_of_title, count_of_episodes, Studio_creator)
--select (
--    select name
--    from Title
--    where name = 'Otokogi'
--    ), 'Seinen', 'TV', 700, 1000
--from Title
--where genres_of_anime like '%Seinen%';
--select * from Title

--17 update
--update title
--set count_of_episodes = count_of_episodes + 10
--where id = 12000;
--select * from Title

--18 UPDATE со скалярным подзапросом в предложении SET
--update title
--set count_of_episodes =
--  (
--    select AVG(count_of_episodes)
--    from title
--    where genres_of_anime like '%Seinen%'
--  )
--where name = 'Otokogi';
--select * from Title


--19 Delete
--Delete from title
--where id = 9999;
--select * from Title

--20 DELETE с вложенным коррелированным подзапросом в предложении WHERE.
--delete from title
--where name in
--    (
--        select name
--        from title
--        where id = 10002
--
--    );

--select * from Title

-- 21 SELECT, использующая простое обобщенное табличное выражение
--WITH aue(na, count_e)
--as
--(
--  select name, count_of_episodes
--  from title
--  where count_of_episodes > 11
--  group by count_of_episodes, name
--)
--select AVG(count_e) as Srednee_kol_vo_serij
--from aue

--23 Оконные функции. Использование конструкций MIN/MAX/AVG OVER()
--Select id, name, genres_of_anime, count_of_episodes,
--avg(count_of_episodes) over (PARTITION BY genres_of_anime) as AVG_count,
--min(count_of_episodes) over (PARTITION BY genres_of_anime) as MIN_count,
--max(count_of_episodes) over (PARTITION BY genres_of_anime) as MAX_count
--from title


--select * from role
--select  Title.id, title.name, title.genres_of_anime, title.type_of_title, title.count_of_episodes, Studio.name
--from Title join Studio on Title.Studio_creator = Studio.studio_id

--1 Select с предикатом сравнения
--Выводится информация об аниме жанра Seinen
--select distinct T.name, T.genres_of_anime
--from Title as T
--where T.genres_of_anime = 'Seinen'
--ORDER BY T.name, T.genres_of_anime

--2 Select с предикатом Between
--Выводится информация об аниме где количество серий от 8 до 13
--SELECT DISTINCT T.ID, T.name, T.count_of_episodes
--FROM Title as T
--where T.count_of_episodes BETWEEN 8 and 13

--3 Select  с предикатом Like
--Выводится информация об аниме в жанрах которого пристуствует Thriller
--select distinct T.name, T.genres_of_anime
--from Title as T
--where T.genres_of_anime like '%Thriller%'
--ORDER BY T.name, T.genres_of_anime

--4 Select с предикатом IN с вложенным подзапросом
--Выводится информация обо всех аниме и студиях которые их создавали, кроме аниме типов Movie
--Select T.name, T.genres_of_anime, T.count_of_episodes, S.name
--From Title as T join Studio as S on T.studio_creator = S.Studio_id
--Where T.name IN
--      (
--          Select T.name
--          from Title as T
--          Where T.type_of_title not like 'Movie'
--      )

--5 Select с предикатом EXISTS с вложенным подзапросом
--Выводится информация о тайтлах и студии, к работе над которыми был привлечен Seyu (озвучка) из имеющихся в таблице авторов аниме
--Select T.name, T.genres_of_anime, T.count_of_episodes, S.name
--From Title as T join Studio as S on T.studio_creator = S.Studio_id
--where exists
--    (
--      Select T.id, R.role
--      from Title as T join Role as R on T.id = R.anime
--      where R.role = 'Seyu'
--    )

--6 Select с предикатом сравнения с квантаром
--Выводится информация об аниме, количество серий которых больше чем у любого аниме имеющего среди жанров жанра Аниме
--Select T.name, T.genres_of_anime, T.count_of_episodes, S.name
--From Title as T join Studio as S on T.studio_creator = S.Studio_id
--where T.count_of_episodes > ALL
--      (
--         select T.count_of_episodes
--          From Title as T
--          where genres_of_anime like '%Thriller%'
--      )

--7 Select с агрегатными функциями в выражениях столбцов
--Выводится среднее количество епизодов среди всех аниме
--select    AVG(TotalEpisodes) AS Actual_avg,
--  SUM(TotalEpisodes) / COUNT(id) as Calc_AVG
--  from (
--      Select id, SUM(count_of_episodes) AS TotalEpisodes
--      from Title
--      group by id
--  ) AS TotalTitles

--8 Select со скалярными подзапросами в выражениях столбцов
--select T.id, T.count_of_episodes,
--  (
--    select AVG(T.count_of_episodes)
--    From Title as T
--  )AS AVGcount_of_episodes,
--  (
--    select MIN(T.count_of_episodes)
--    From Title as T
--  )AS MINcount_of_episodes,
--  T.name
--From Title as T

--9 Select case простой
--select id, name,
--  CASE count_of_episodes
--      WHEN 1 then 'Film'
 --     WHEN 12 THEN 'One season'
 --     WHEN 24 THEN 'Long season or two seasons'
 --     WHEN 48 Then 'Multiple seasons'
--      else 'Ongoing'
--  END AS count
--From Title

--10 Select case поисковый
--select id, name,
--  CASE
--      WHEN count_of_episodes < 12 THEN 'Short'
--      WHEN count_of_episodes < 24 THEN 'Normal'
--      WHEN count_of_episodes < 48 Then 'Long'
--      else 'Almost endless'
--  END AS count
--From Title

--11 Создание новой временной локальной таблицы
--select id, name,
--  case
--    WHEN count_of_episodes = 12 then '1 season'
--    else 'Not 1 season'
--  end as seasons
--Into one_season_anime
--from Title
--where id IS NOT NULL
--group by id;
--select * from one_season_anime

--13 SELECT, использующая вложенные подзапросы с уровнем вложенности 3
--Select T.id, T.name, T.type_of_title, T.count_of_episodes, avg(T.count_of_episodes) as AVGEP
--From Title as T
--Where T.id =
--(
--    Select t.id
--    from title as t
--    where T.type_of_title =
--        (
--            select type_of_title
--            from title
--            where type_of_title = 'TV' and count_of_episodes >
--            (
--              select avg(count_of_episodes)
--              from title
--            )
--        )
--)
--group by T.id

--14 SELECT, консолидирующая данные с помощью предложения GROUP BY, но без предложения HAVING
--select T.name, T.count_of_episodes, S.name
--From Title as T join Studio as S on T.studio_creator = S.Studio_id
--Where T.genres_of_anime like '%Seinen%'
--group by T.id, T.name, T.count_of_episodes, S.name

--15 select group by having
--select id, name, AVG(Count_of_episodes) as AVGepisodes
--from Title
--group by id
--having AVG(Count_of_episodes) >
--      (
--        select avg(Count_of_episodes) as Curepisodes
--        from Title
--      )


--3 лабораторная

-- A1 выдет имя первого тайтла в жанрах которого присутствует Seinen
CREATE FUNCTION get_name_of_seinen() RETURNS varchar AS '
    select name from title
        WHERE genres_of_anime like ''%Seinen%'';

' LANGUAGE SQL;

SELECT get_name_of_seinen();
--drop function get_name_of_seinen;

--A2 выдает жанры аниме под заданным id
CREATE FUNCTION get_genres_of_anime_by_id(int) RETURNS varchar AS '
    select genres_of_anime from title
      Where id = $1
' LANGUAGE SQL;

--select get_genres_of_anime_by_id(1000);
--drop function get_genres_of_anime_by_id;

--A3 получить все данные об аниме по заданному id
CREATE FUNCTION get_watched_title_info_by_id(int) returns table
(
      name VARCHAR(200),
      genres_of_anime VARCHAR(1000),
      type_of_title VARCHAR(60),
      count_of_episodes int,
      Studio_creator int,
      studio_name VARCHAR(60)
)
as
'
  update title
  set type_of_title = ''watched_'' || type_of_title
  where id = $1;
  select title.name,
  title.genres_of_anime,
  title.type_of_title,
  title.count_of_episodes,
  title.Studio_creator,
  studio.name
  from title join studio on title.studio_creator = studio.studio_id
  where id = $1 and count_of_episodes > 0;

' LANGUAGE SQL;

--select * from get_title_info_by_id(666);
--drop function get_title_info_by_id;

-- A4
-- Рекурсивное OTB
-- Обойти рекурсивно таблицу title
create or replace function rec_func() returns table (id int, title_name varchar(60))
as
'
with recursive rec_table as
(
    select id as index, name as title_name
    from title
    where id = 1
    union
    select title.id as index, title.name as title_name
    from rec_table join title on rec_table.index + 1 = title.id
    where title.id <= 100
)
select * from rec_table;
' language sql;

--select * from rec_func();
--drop function rec_func;


-- B1 Хранимая процедура без параметров или с параметрам

select *
into temp title_copy
from title;

--select *
--from title_copy;

create or replace procedure update_studio_title(title_id real, studio_before real, studio_after real) as
$$
	update title
	set studio_creator = studio_after
	where title.studio_creator = studio_before and title.id = title_id
$$ language sql;

--call update_studio_title(1, 887, 666);

--select *
--from title;

-- B2
-- замена type_of_title в заданном диапазоне id

--select *
--into temp title_copy
--from title;

--select *
--from title_copy;

create or replace procedure update_type_of_title(id_from int, id_to int, new_type varchar(60)) as
$$
begin
    if (id_from <= id_to)
then
	update title_copy
	set type_of_title = new_type
	where title_copy.id = id_from;
	call update_type_of_title(id_from + 1, id_to, new_type);
end if;
end;
$$ language plpgsql;

--call update_type_of_title(1, 30, 'Ova');

--select *
--from title_copy;

--drop table title_copy;

--B3
-- замена type_of_title в заданном диапазоне id
create or replace procedure update_type_of_title(id_from int, id_to int, new_type varchar(60)) as
$$
declare cur cursor for
        select title_copy.id from title_copy
        where title_copy.id between id_from and id_to;
        row record;
begin
    open cur;
    loop
        fetch cur into row;
        exit when not found;
        update title_copy
        set type_of_title = new_type
        where title_copy.id = row.id;
    end loop;
    close cur;
end;
$$ language plpgsql;

--call update_type_of_title(100, 300, 'Film');

--select *
--from title_copy;

-- B4
-- Процедура удаляющая все пользовательские тригеры
create or replace procedure DropTriggers(inout cnt int = 0) AS
$$
declare
    cur cursor for select trigger_name, event_object_table
        from information_schema.triggers
        where trigger_schema = 'public';
    r record;
BEGIN
    open cur;
    loop
        fetch cur into r;
        exit when not found;
        EXECUTE format ('DROP TRIGGER IF EXISTS %s ON %s',
        quote_ident(r.trigger_name), r.event_object_table);
        cnt := cnt + 1;
    end loop;
end;
$$ LANGUAGE plpgsql;

-- C1
-- Создаю таблицу логов
create table if not exists type_changes_audit
(
	change_id int not null,
	change_date text not null
);

create or replace function type_log_func()
returns trigger as
$$
   begin
      insert into type_changes_audit(change_id, change_date) values (new.id, current_timestamp);
      return new;
   end;
$$ language plpgsql;

create trigger title_type_upd
	after update of type_of_title on title_copy
	for each row
	execute procedure type_log_func();

call update_type_of_title(1, 30, 'Film');
--select * from type_changes_audit;

-- С2 Вместо удаления меняю тип на deleted
create view title_view as
select *
from title;

create or replace function upd_is_deleted_func()
returns trigger as
$$
begin
	update title
	set type_of_title = 'Deleted'
	where id = old.id;
	return old;
end;
$$ language plpgsql;

create trigger type_deleted
	instead of delete on title_view
	for each row
	execute procedure upd_is_deleted_func();

delete from title_view
where title_view.id in
    (
    select title.id
    from title
    where title.type_of_title like '%OVA%'
    );
--select * from title;

-- триггеры существуют
--select trigger_name, event_object_table
--        from information_schema.triggers
--        where trigger_schema = 'public';

--call DropTriggers();

-- триггеры удалены
--select trigger_name, event_object_table
--        from information_schema.triggers
--        where trigger_schema = 'public';

--5 лабораторная

-- 1 Извлечение данных с помощью функций создания JSON.
--select to_json(title) from title;
--select row_to_json(title) from title;
--
-- 2 Загрузка и сохранение JSON-документа
--copy (select row_to_json(title) from title)
--to '/Users/demonblo/Desktop/DB/title.json';

--create temp table title_from_json(doc json);
--copy title_from_json from '/Users/demonblo/Desktop/DB/title.json';

--select p.*
--from title_from_json, json_populate_record(null::title, title_from_json.doc) as p;

--select * from title_from_json;

-- 3 Добавление оценок студентам и генерация случайных значений



--select title.id, f.*
--from title, json_to_record(status) AS f(Announced int, Teasered int, Done int, In_process int,
--                        Paused int);

-- Извлекаем фрагмент
--select title.id, f.Done
--from title, json_to_record(status) AS f(Announced int, Teasered int, Done int, In_process int,
--                        Paused int);


-- Проверка сещствования узла
--create function check_key(str json, key_ varchar)
--returns boolean AS $$
--declare
--el varchar;
--begin
--for el in (select json_object_keys(str))
--    loop
--    IF key_ = el then return true;
--    end IF;
--    end LOOP;
--    return false;
--end;
--$$ language plpgsql;

--select check_key(status, 'Announced') FROM title;


-- Изменяем файл
--copy (select row_to_json(title) from title)
--to '/Users/demonblo/Desktop/DB/title.json';


--create temp table Title2
--(
--    info json
--);

--copy Title2 from '/Users/demonblo/Desktop/DB/title.json';

--create temp table Title3
--(
--    info json
--);


--insert into Title3 (
--select Title2.*
--from Title2, json_populate_record(NULL::Title, info) AS T
--where T.genres_of_anime like '%Seinen%');

--select T.*
--from Title3, json_populate_record(NULL::Title, info) AS T;

--COPY (select * FROM Title3)
--TO '/Users/demonblo/Desktop/DB/title.json';

-- Группируем по узлам
--select title.name, title.genres_of_anime, round(avg(f.Announced), 2)
--from title, json_to_record(status) AS f(Announced int, Teasered int, Done int, In_process int,
--                        Paused int)
--group by title.name, title.genres_of_anime;

-- A1.3
--SELECT get_name_of_seinen();
-- A2.3
--select name from title
--where genres_of_anime = get_genres_of_anime_by_id(1000);
-- A3.3
--select * from get_title_info_by_id(666);
-- A4.3
--select * from rec_func();
-- B1.3
--call update_studio_title(1, 887, 666);
--select * from title;
-- B2.3
--call update_type_of_title(1, 30, 'Ova');
--select * from title_copy;
-- B3.3
--call update_type_of_title(100, 300, 'Film');
--select * from title_copy;
-- B4.3
-- C1.3
--call update_type_of_title(1, 30, 'Film');
--select * from type_changes_audit;
-- C2.3
--select * from title;

-- триггеры существуют
--select trigger_name, event_object_table
--        from information_schema.triggers
--        where trigger_schema = 'public';

--call DropTriggers();

-- триггеры удалены
--select trigger_name, event_object_table
--        from information_schema.triggers
--        where trigger_schema = 'public';


create temp table title_from_json(doc json);
copy title_from_json from '/Users/demonblo/Desktop/DB/title.json';

select p.*
from title_from_json, json_populate_record(null::title, title_from_json.doc) as p;

--select * from title_from_json;

create language plpython3u;

alter table title add status json NULL;

create or replace procedure update_status_title() as
$$
from random import randint
plan = plpy.prepare("update title set status = $1 where title.id = $2", ["json", "real"])
zapr = plpy.execute("select * from title where id < 1000")
subj = ['Empty', 'Announced', 'Teasered', 'Done', 'In_process', 'Paused']
for cur in zapr:
    stroka = '{'
    cnt = randint(1, 5)
    stroka += '"' +  subj[cnt] + '"' + ':' + '"' + str(cnt) + '"'
    stroka += '}'
    print(stroka)
    plpy.execute(plan, [stroka, cur['id']])
$$ language plpython3u;

call update_status_title();

--select * from title;

create function check_key(str json, key_ varchar)
returns boolean AS $$
declare
el varchar;
begin
for el in (select json_object_keys(str))
    loop
    IF key_ = el then return true;
    end IF;
    end LOOP;
    return false;
end;
$$ language plpgsql;

--select check_key(status, 'Announced') FROM title;


-- 2 lab 25 question
delete from title
where name in
(
  select name
  from
  (
    select *, row_number() over (partition by name) as cnt
    from title
  ) as f
  where f.cnt = 2
);
select * from title;
