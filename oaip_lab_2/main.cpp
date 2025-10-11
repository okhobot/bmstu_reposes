#include<iostream>
#include<cstring>
#include<cmath>
const int str_len=256, word_size=str_len, words_count=10;
char str[str_len];
char words[words_count][word_size];

void split_str()
{
    int word_index=0;
    int char_index=0;
    bool new_word=true;
    for(int i=0;i<str_len&&str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            words[word_index][char_index]='\0';
            new_word=true;
            word_index++;
            char_index=0;
        }
        else 
        {
            new_word=false;
            words[word_index][char_index]=str[i];
            char_index++;
        }

    }
}

void find_sub(int i1, int i2, int &start_indx, int &max_len)
{
    int len=0;
    start_indx=0;
    for(int i=0;i<word_size&&words[i1][i]!='\0';i++)
    {
        for(int j=0;j<word_size&&words[i2][j]!='\0';j++)
        {
            for(len=0;len<word_size-std::max(i,j)&&words[i1][i+len]&&words[i2][j+len]!='\0';len++)
            {
                //std::cout<<i<<" "<<j<<" "<<len<<" "<<start_indx<<" "<<(words[i1][i+len]!=words[i2][j+len])<<std::endl;
                if(words[i1][i+len]!=words[i2][j+len])
                {
                    break;
                }
            }
            if(len>max_len)
            {
                start_indx=i;
                max_len=len;
            }

        }
    }
            
}

void print_max_sub()
{
    int max_len=0, start_index=0;
    char *sub_ptr;
    for(int i=0;i<words_count;i++)
    {
        for(int j=0;j<words_count;j++)
        {
            int len=0;
            if(j==i)continue;
            find_sub(i,j,start_index,len);
            if(len>max_len)
            {
                max_len=len;
                sub_ptr=&words[i][start_index];
            }
        }
    }
    char res[word_size];
    strncat(res, sub_ptr, max_len);
    std::cout<<"Самая длинная подстрока: "<<res<<std::endl;
    
}

int main()
{
    int b_count=0, max_len=0, c_count=0, same_count=0;

    ///std::cout<<"Введите строку длиной до 256 символов"<<std::endl;
    std::cin.getline(str,str_len);

    split_str();
    for(int i=0;i<10;i++)
    {
        std::cout<<words[i]<<std::endl;
        if(words[i][0]=='b')b_count++;
        max_len=std::max(max_len, (int)strlen(words[i]));

        if(strlen(words[i])>1 && toupper(words[i][1])==toupper(words[i][(int)strlen(words[i])-2]))same_count++;

    }
    for(int i=0;i<word_size&&words[3][i]!='\0';i++)
        if(words[2][i]=='c')c_count++;
    for(int i=0;i<str_len&&str[i]!='\0';i++)
        str[i]=toupper(str[i]);

    

    std::cout<<"Количество слов, начинающихся с буквы b: "<<b_count<<std::endl;
    std::cout<<"Максимальная длина слова: "<<max_len<<std::endl;
    std::cout<<"Количество \"с\" в 3 слове: "<<c_count<<std::endl;
    std::cout<<"Новая строка: "<<str<<std::endl;
    std::cout<<"Количество слов, у которых совпадает второй и предпоследний символ: "<<same_count<<std::endl;
    print_max_sub();
    return 0;
}