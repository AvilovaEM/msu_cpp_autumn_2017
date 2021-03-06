# HW01: Измерение работы функций суммирования элементов матрицы по строкам и по столбцам и сравнение результатов

В проекте реализованы функции суммирования элементов матрицы по строкам и по столбцам, а также присутствует возможность получения статистики замера времени их выполнения.

## Использование
Для проведения процедуры сбора статистики замеров времени работы функций следует использовать утилиту **make**.
### Подготовка и запуск
Сборку бинарных файлов и запуск замеров можно произвести следующими командами

```
# сборка бинарных файлов
make

# произведение замеров и печать статистики о них 
make benchmark
```
### Очистка временных файлов
Данная команда удаляет созданные временные файлы

```
make clean
```
## Отчет
Файлы, относящиеся к полученным результатам, располагаются в директории **reporting\_results**
### Результаты замеров
Файл **benchmark.txt** содержит статистику замеров.
Посчитав среднее значение результатов прогонов (average time), получаем, что подсчет суммы по строкам быстрее подсчета по столбцам при использованном размере матрицы в среднем приблизительно в **3.45 раза**.
### Промахи в кэше
В файле **about\_cachegrind\_results.txt** записан анализ результатов замера доли промахов в кэше при выполнении подсчетов суммы обеими функциями.
