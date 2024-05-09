//Составить программу, которая на основе заданного списка формирует два других, помещая в первый из них положительные, а во второй
//— отрицательные элементы исходного списка, сортируя их по возрастанию при заполнении.

#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include <ctime>

int main() {

	srand(std::time(0));

	std::list <int> great_list; //основной список
	std::list <int> positive_list; //список положительных
	std::list <int> negative_list; //список отрицательных

	//создаём начальный список на рандом
	for (int _i = 0; _i < 20; ++_i) {

		if(rand()%2 == 1)
			great_list.push_back(rand() % 200);
		else
			great_list.push_back((rand() % 200)*(-1));

	}

	//печатаем начальный список
	std::cout << "Values: ";
	for (auto _i: great_list)
		std::cout << _i << " ";
	std::cout << std::endl;

	for(auto current_elem = great_list.begin(); current_elem != great_list.end(); current_elem++){
		
		if (*current_elem < 0) {

			for (auto negative_insert = negative_list.begin(); negative_insert != negative_list.end(); negative_insert++) {

				if (*current_elem < *negative_insert) {

					negative_list.emplace(negative_insert, *current_elem);
					break;

				}

			}
			
			if (negative_list.size() < 1)
				negative_list.push_back(*current_elem);
			else {

				if (*current_elem >= *std::prev(negative_list.end()))
					negative_list.push_back(*current_elem);

			}

		}
		else {
			
			for (auto positive_insert = positive_list.begin(); positive_insert != positive_list.end(); positive_insert++) {

				if (*current_elem < *positive_insert) {

					positive_list.emplace(positive_insert, *current_elem);
					break;

				}

			}
			
			if (positive_list.size() < 1)
				positive_list.push_back(*current_elem);
			else {

				if (*current_elem >= *std::prev(positive_list.end()))
					positive_list.push_back(*current_elem);

			}

		}
	
	}

	std::cout << "Positive list: ";
	for (int num : positive_list) {
		std::cout << num << " ";
	}

	std::cout << "\nNegative list: ";
	for (int num : negative_list) {
		std::cout << num << " ";
	}

	std::cout << "\n" << positive_list.size() + negative_list.size();
	
	return 0;

}