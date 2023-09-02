#include <iostream>
#include <exception>

int function(std::string str, int forbidden_length){
    int length_str = str.size();
    if(length_str == forbidden_length){
        throw std::invalid_argument("Вы ввели слово запретной длины! До свидания");
    }
    return length_str;
}

int main() {
    int forb_length;
    std::string word;
    std::cout << "Введите запретную длину:";
    std::cin >> forb_length;
    while (true){
        int func = 0;
        std::cout << "Введите слово: ";
        std::cin >> word;
        try {
            func = function(word, forb_length);
        }catch (const std::invalid_argument& er){
            std::cout << er.what() << std::endl;
            break;
        }
        std::cout << "Длина слова " << word << " равна " << func << std::endl;
    }
    return 0;
}
