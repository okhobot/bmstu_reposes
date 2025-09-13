#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, cost=0;
    std::cout<<"Введите количество остановок"<<std::endl;
    std::cin >> n;

    for(int i=0;i<n;i++)
        cost+=5;
    std::cout<<"Стоимость проезда: "<<cost<<" рублей"<<std::endl;

    return 0;
}