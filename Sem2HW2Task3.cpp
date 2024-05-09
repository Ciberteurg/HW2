//Дан текст.Выведите слово, которое в этом текст встречается чаще всего.
//Если таких слов несколько, выведите то, которое меньше в лексикографическом порядке.

#include <iostream>
#include <map>
#include <algorithm>

int main() {

	std::string text = "abc bbbcd abc dfjds ababab bbbcd dfjds dhjsk abc abc dfjds abc dfjds bbbcd bbbcd bbbcd bbbcd";
    //std::string text = "abc bbbcd abc dfjds ababab bbbcd dfjds dhjsk abc abc dfjds abc dfjds bbbcd bbbcd bbbcd";  //поровну abc и bbbcd

    std::map<std::string, int> word_сount;

    std::string word = "";

    for (auto it = text.begin(); it != text.end(); ++it) {

        if (std::isalpha(*it))
            word += *it;
        else {

            if (!word.empty()) {

                word_сount[word]++;
                word = "";

            }

        }

    }

    if (!word.empty()) {
        word_сount[word]++;
    }

    std::string most_frequent_word = "";
    int counter = 0;

    for (auto& pair : word_сount) {

        if (pair.second > counter) {

            counter = pair.second;
            most_frequent_word = pair.first;

        }
        else if (pair.second == counter)
            most_frequent_word = std::min(most_frequent_word, pair.first);

    }

    std::cout << most_frequent_word << std::endl;

    return 0;


}