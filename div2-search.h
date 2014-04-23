// Дата:  01 сентября 2012
// Автор: Дмитрий Бравиков (bravikov@gmail.com)
//
// Реализация поиска свободного места в областе для хранения данных
// методом половинного деления.
//
// Функция div2_search_is_data() реализуется пользователем.

#ifndef DIV2_SEARCH_H
#define DIV2_SEARCH_H

#include <stdbool.h>

// Количество итераций в последнем поиске
extern unsigned div2_search_iteration_count;

// Возвращает true, если удалось обнаружить данные в позиции position.
bool div2_search_is_data(const unsigned position);

// Возвращает: свободную позицию; -1, если size = 0; size, если нет свободной.
int div2_search_free_position(const unsigned size);


#endif //DIV2_SEARCH_H

