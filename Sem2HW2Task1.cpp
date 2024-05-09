//Вам надо написать функцию аналогичную Print, которая умеет печатать в поток std::cout элементы переданного контейнера через указанную строку -
//разделитель. Первый аргумент функции — контейнер.Гарантируется, что по этому контейнеру можно проитерироваться с помощью стандартного цикла range - based for,
//и что элементы контейнера можно напечатать в поток std::cout с помощью стандартного оператора << .Второй аргумент функции — строка - разделитель,
//которую надо печатать между элементами.В конце необходимо напечатать перевод строки \n.
//
//Пример вызова :
//int main() {
//    std::vector<int> data = { 1, 2, 3 };
//    Print(data, ", ");  // 1, 2, 3
//}

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>

template<typename Cont, typename S> void new_print(Cont&, S);

int main() {

	std::vector<int> data1 = { 1, 2, 3 };
	std::array<int, 3> data2 = { 1, 2, 3 };
	std::deque<int> data3 = { 1, 2, 3 };
	std::list<int> data4 = { 1, 2, 3 };
	std::forward_list<int> data5 = { 1, 2, 3 };

	std::cout << "vector\n";
	new_print(data1, ", ");

	std::cout << "array\n";
	new_print(data2, ", ");

	std::cout << "deque\n";
	new_print(data3, ", ");

	std::cout << "list\n";
	new_print(data4, ", ");

	std::cout << "forward_list\n";
	new_print(data5, "***");

}

template<typename Cont, typename S> void new_print(Cont& np_data, S np_splitter) {

	for (auto np_out : np_data) {

		if (std::next(std::find(np_data.begin(), np_data.end(), np_out)) != np_data.end())
			std::cout << np_out << np_splitter;
		else
			std::cout << np_out << "\n";

	}

}