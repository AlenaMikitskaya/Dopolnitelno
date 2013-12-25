#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char Substitute (char letter, int key, char operation)
{
    int new_ind;
    char x;
    const int n=26;
    char Alfavit[n]={'a','b','c','d','e','f','g','h','i','j','k','l',
    'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i=0; i<n; i++)
    {
        if (letter==Alfavit[i])
        {
            if (operation==1)
            {
                new_ind=i+key;
                while (new_ind>(n-1))
               {
                  new_ind=new_ind-n;
               }
            }
            if (operation==2)
            {
                new_ind=i-key;
                while (new_ind<0)
               {
                  new_ind=new_ind+n;
               }
            }
            x=Alfavit[new_ind];
        }
    }
    return x;
}

int main()
{
    const int N=256;
    char Str[N];
    cout<<"Enter the text:"<<endl;
    gets(Str);
    int length=strlen(Str);
    int operation;
    cout<<"If you want to encrypt the text, enter 1"<<
    endl<<"If you want to decrypt the text, enter 2"<<endl;
    cin>>operation;
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    for (int i=0; i<length; i++)
    {
        if (Str[i]==' ')
        {
            Str[i]=Str[i];
        }
        else
        {
            Str[i]=Substitute (Str[i], key, operation);
        }
    }
    cout<<"The new text: "<<endl<<Str;
    return 0;
}
