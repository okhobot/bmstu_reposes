#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "Russian");

    float temp;
    std::cout<<"Введите температуру за окном"<<std::endl;
    std::cin >> temp;
    std::cout<<"Рекомендуется надеть ";
    if (temp < 0)
        std::cout<<"зимнюю одежду"<<std::endl;
    else if (temp <= 10)
        std::cout<<"тёплую одежду"<<std::endl;
    else if (temp <= 20)
        std::cout<<"лёгкую одежду"<<std::endl;
    else
        std::cout<<"летнюю одежду"<<std::endl;

    return 0;
}