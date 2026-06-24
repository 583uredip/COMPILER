#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
char str[100];
cout<<"Enter statement:";
cin.getline(str,100);
char keyword[6][10]={"int","float","if","else","while","return"};
char *start,*end;
start = end = str;
while(*end!='\0')
{
    if(isspace(*end))
    {
        end++;
        continue;
    }
    if(isalpha(*end))
    {
        start=end;
        while(isalnum(*end))
        {
            end++;
        }
        char temp[200];
        strncpy(temp,start,end-start);
        temp[end-start]='\0';
        bool found=false;
        for(int i=0;i<6;i++)
        {
            if(strcmp(temp,keyword[i])==0)
            {
                cout<<temp<<" : keyword\n";
                found=true;
                break;

            }
        }
        if(!found)
        {
            cout<<temp<<": Identifier\n";
        }
    }
    else if(isdigit(*end))
{
    start = end;

    while(isdigit(*end))
    {
        end++;
    }

    char temp[20];

    strncpy(temp, start, end-start);
    temp[end-start] = '\0';

    cout << temp << " : Constant\n";
}
    else if(strchr("+-*/%=<>", *end))
    {
    cout << *end << " : Operator\n";
    end++;
    }
    else if(strchr("(){}[];,.", *end))
    {
    cout << *end << " : Punctuation\n";
    end++;
    }
    else
   {
    cout << *end << " : Lexical Error\n";
    end++;
   }
}
return 0;

}
