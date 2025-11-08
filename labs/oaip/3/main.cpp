#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <sstream>

class Book
{
    std::string name = "", author = "";
    int year = 0;

public:
    bool read(std::istream &inp)
    {
        std::getline(inp, name);
        if (name.size() == 0)
            return false;
        std::getline(inp, author);
        std::string s_year;
        std::getline(inp, s_year);
        year = atoi(s_year.c_str());
        return true;
    }

    void print_f(std::ostream &outp)
    {
        outp << "Name: " << name << "; Author: " << author << "; Year of release: " << year << ";" << std::endl;
    }
    void print(std::ostream &outp)
    {
        outp << name << "\n"
             << author << "\n"
             << year << std::endl;
    }

    std::string get_name()
    {
        return name;
    }
    std::string get_author()
    {
        return author;
    }
    int get_year()
    {
        return year;
    }
};

const std::string fname = "books.txt";
std::vector<Book> books;

std::stringstream add_books()
{
    std::stringstream ss;
    std::ofstream outp(fname, std::ios::app);
    Book book;
    while (book.read(std::cin))
    {
        books.push_back(book);
        book.print(outp);
        book.print_f(ss);
    }
    outp.close();
    return ss;
}
void load_books()
{
    std::ifstream inp(fname);
    Book book;
    while (book.read(inp))
    {
        books.push_back(book);
    }
    inp.close();
}
Book find_book(std::string name)
{
    for (int i = 0; i < books.size(); i++)
        if (books[i].get_name() == name)
            return books[i];
    return Book();
}
void sort_books(bool by_name)
{
    std::sort(books.begin(), books.end(), [by_name](Book &a, Book &b)
              { 
                if(by_name) return a.get_name()<b.get_name();
                else return a.get_year()<b.get_year(); });
    std::ofstream outp(fname);
    for (int i = 0; i < books.size(); i++)
        books[i].print(outp);
    outp.close();
}
std::stringstream print_books_by_max_year(int max_year)
{
    std::stringstream ss;
    for (int i = 0; i < books.size(); i++)
        if (books[i].get_year() <= max_year)
            books[i].print_f(ss);
    if (ss.str() == "")
        ss.str("No matching books found");

    return ss;
}

int main()
{
    // std::ifstream inp("input.txt");

    // add_books();
    load_books();
    // find_book("b1").print_f(std::cout);
    // sort_books(0);
    // print_books_by_max_year(2);

    std::string com;
    while (com != "exit")
    {
        std::getline(std::cin, com);
        std::ofstream outp("logs.txt", std::ios::app);

        if (com == "add")
        {
            outp << "add files:\n"
                 << add_books().str() << std::endl;
            std::cout << "done" << std::endl;
        }
        else if (com == "find")
        {
            std::getline(std::cin, com);

            outp << "find book: " << com << ":\n";
            find_book(com).print_f(outp);
            find_book(com).print_f(std::cout);
        }
        else if (com == "sort")
        {
            std::getline(std::cin, com);
            sort_books(com == "by name");
            outp << "sort books" << std::endl;
            std::cout << "done" << std::endl;
        }
        else if (com == "get_by_max_year")
        {
            std::getline(std::cin, com);
            std::string res = print_books_by_max_year(std::stoi(com)).str();
            outp << "get_by_max_year = " + com << '\n'
                 << res << std::endl;
            std::cout << res << std::endl;
        }
        else if (com == "help")
        {
            std::cout << "command exit - escape" << '\n'
                      << "command find \\n book_name - find book" << '\n'
                      << "command sort \\n by name/by year - sort books.txt" << '\n'
                      << "command add - add books; to end edding, send empty line" << '\n'
                      << "command get_by_max_year \\n max_year - books published no later than the year of publication" << std::endl;
        }
        else if(com!="exit")std::cout<<"unknown command"<<std::endl;
        outp.close();
    }
    

    return 0;
}
