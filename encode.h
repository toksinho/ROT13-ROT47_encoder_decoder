#ifndef ENCODE_H
#define ENCODE_H
#include <iostream>
void encode13(std::string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=97 && s[i]<=122)
        {
            if(s[i]<110)
                s[i] = static_cast<char>(s[i]+13);
            else
                s[i] = static_cast<char>(s[i]-13);
        }
    }
}

void encode47(std::string &s)
{
    int num = 0;
    char c = ' ';
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=33 && s[i]<=126)
        {
            if(s[i]<=79)
                s[i] = static_cast<char>(s[i] + 47);
            else
            {
                num = (s[i] + 47) - 126;
                s[i] = static_cast<char>(c + num);
            }

        }
    }
}

#endif // ENCODE_H
