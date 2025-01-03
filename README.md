[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/-hH64FG6)
## Лабораторная работа: Реализация MapReduce для анализа данных о продажах с ипользованием HADOOP!!!
# Цель работы

Ознакомиться с концепцией распределенных вычислений на примере модели MapReduce. Научиться разрабатывать многопоточную систему для обработки больших данных и применять её для анализа данных о продажах.
# Описание задачи

У вас в репозитории есть несколько CSV-файлов, представляющих данные о продажах, например:

    transaction_id,product_id,category,price,quantity
    1,101,electronics,300.00,2
    2,102,books,15.00,5
    3,101,electronics,300.00,1
    4,103,toys,25.00,4
    5,102,books,15.00,3

Необходимо:

  * Вычислить общую выручку для каждой категории товаров.
  * Подсчитать общее количество проданных товаров по категориям.
  * Отсортировать категории по общей выручке в порядке убывания.

Пример вывода:

    Category      Revenue    Quantity
    electronics   900.00     3
    books         120.00     8
    toys          100.00     4

# Требования
Основная часть:

  * Используем hadoop
  * Написать реализацию MapReduce для обработки CSV-файлов.
  * Реализовать многопоточность в каждой фазе:
      * Map — обработка строк из файлов.
      * Shuffle/Sort — группировка данных по категориям.
      * Reduce — вычисление итоговых значений для каждой категории.
  * Сохранить результат в файл.
  * Обеспечить потокобезопасность при работе с общими данными.
  * Реализовать поддержку одновременной обработки большого количества файлов.

Дополнительные задачи (по желанию):

* Добавить возможность выбора метрики анализа (например, подсчёт средней цены товара в категории).

# Результаты
Результатом работы является сам код, файл с результатами и экспериментальные данные по быстродействию работы написанного кода при изменении числа worker-ов / частей, на которые разбивается файл

# How to run
1. Set up `JAVA_HOME`
2. Set up `HADOOP_HOME`
3. Run: `$HADOOP_HOME/bin/hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.4.1.jar -Dmapred.reduce.tasks=16 -output ./output/ -mapper ./mapper.out -reducer ./reducer.out -input ./0.csv -input ./1.csv  -input ./2.csv -input ./3.csv -input ./4.csv -input ./5.csv -input ./6.csv -input ./7.csv`
4. Run: `$HADOOP_HOME/bin/hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.4.1.jar -mapper ./idmapper.out -reducer ./idreducer.out -input ./tmp/ -output ./output`
