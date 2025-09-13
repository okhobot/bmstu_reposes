#include <iostream>
static const int size=10;
int a[size];

void print()
{
    for(int i=0;i<size;i++)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}

int sum()
{
    int sum=0;
    for(int i=0;i<size;i++)
        sum+=a[i];
    return sum;
}
int min()
{
    int min=a[0];
    for(int i=1;i<size;i++)
        min=(min>a[i])?a[i]:min;
    return min;
}
void insert(int val_indx, int indx)
{
    int val=a[val_indx];
    for(int i=val_indx;i>indx;i--)
        a[i]=a[i-1];
    a[indx]=val;
}
void sort()
{
    for(int i=1;i<size;i++)
        for(int j=0;j<size;j++)
            if(a[i]<a[j]) 
            {
                insert(i, j);
            }
}

int main()
{
    
    std::cout<<"Введите массив\n";
    for(int i=0;i<size;i++)
        std::cin>>a[i];
    std::cout<<"Введено:\n";
    print();
    std::cout<<"Сумма: "<<sum()<<std::endl;
    std::cout<<"Минимальный элемент: "<<min()<<std::endl;
    sort();
    std::cout<<"Отсортированный массив:\n";
    print();
    return 0;
}