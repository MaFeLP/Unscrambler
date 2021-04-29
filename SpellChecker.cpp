//
// Created by max on 29.04.21.
//

#include "SpellChecker.h"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;


//lower case alphabets.
char lower_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

bool SpellChecker::isCorrect(const string word) {


    return false;
}

//function to show the correct spelling if arrangement of word is incorrect.
int SpellChecker::incorrectArrangement(string input)
{
    string line;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while(getline(words,line))
        {
            string Xinput = input, Ninput, permutations, Tinput, Tline, Nline, Xline = line;
            int len = Xinput.size(), flen = line.size();
            if (len == flen)
            {
                for (int i=1; i<Xinput.length(); i++)
                    Ninput.push_back(input[i]);
                for (int i = 1; i < flen; i++)
                    Nline.push_back(Xline[i]);
                Xinput.resize(1);
                Xline.resize(1);
                sort(Nline.begin(),Nline.end());
                sort(Ninput.begin(), Ninput.end());
                Tinput = Xinput + Ninput;
                Tline = Xline + Nline;
                if (Tinput == Tline)
                {
                    found = 1;
                    cout<<line<<endl;
                    break;
                }
            }
        }
        words.close();
    }
    else
    {
        cout<<endl<<"Unexpected error occurred......."<<endl;
    }
    return found;
}

//function to show correct spelling if extra character is present in the given word
int SpellChecker::exchangedCharacters (string input)
{
    string line, Xinput;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = len-1; i >= 0 ; i--)
                {
                    Xinput = input;
                    Xinput[i] = lower_alpha[0];
                    for (int j=0; j<26; j++)
                    {
                        if (Xinput == line)
                        {
                            found == 1;
                            cout<<line<<endl;
                            break;
                        }
                        Xinput[i] = lower_alpha[j+1];
                    }
                    if (found == 1 ) break;
                    else continue;
                }
            }
        }
        words.close();
    }
    else cout<<"\nUnexpected error occurred"<<endl;
    return found;
}

//function to show correct spelling when there is a missing character in the given word.
int SpellChecker::missingCharacter (string input)
{
    string Xinput, line, Tinput, Tline, Xline;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            for (int i = 0; i < 26; i++)
            {
                Xinput = input;
                Xline = line;
                Xinput.resize(len+1,'a');
                Xinput[len] = lower_alpha[i];
                len = Xinput.size();
                string Ninput, Nline;
                if (len == flen)
                {
                    for (int j = 1; j <=len; j++)
                        Ninput.push_back(Xinput[j]);
                    for (int j = 1; j <= flen; j++)
                        Nline.push_back(Xline[j]);
                    Xinput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(),Nline.end());
                    sort(Ninput.begin(),Ninput.end());
                    Tinput = Xinput + Ninput;
                    Tline = Xline + Nline;
                    if (Tinput == Tline)
                    {
                        found = 1;
                        cout<<line<<endl;
                        break;
                    }
                }
                if (found == 1) break;
            }
            if (found == 1) break;
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

//function to show correct spelling of there is an extra character in given word.
int SpellChecker::extraCharacter (string input)
{
    string Xinput, line, Ninput, Tinput;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if ((len-1) == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    Xinput = input;
                    Xinput.erase(Xinput.begin()+i);
                    if (Xinput == line)
                    {
                        found = 1;
                        cout<<line<<endl;
                        break;
                    }

                }
            }
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

//function to show right spelling when given word has wrong extra character and right one is missing.
int SpellChecker::mixedExtraMissing (string input)
{
    string Xinput, line, Xline;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        Xinput = input; Xline = line;
                        Xinput.erase(Xinput.begin()+i);
                        Xinput.resize(len, 'a');
                        Xinput[len-1] = lower_alpha[j];
                        sort(Xinput.begin()+1,Xinput.end());
                        sort(Xline.begin()+1,Xline.end());
                        if (Xinput == Xline)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
        }
        words.close();
    }
    return found;
}

/*
int main()
{
    string input,line;
    int len,flen,correct=0;
    while (1) {
        cout<<"Enter the word: "; getline(cin,input);
        len = input.length();
        for (int i=0; i < len; i++)
            tolower(input[i]);
        ifstream words ("words.txt");
        if(words)
        {
            while (getline(words,line))
            {
                flen = line.length();
                if (len==flen)
                {
                    if (line==input)
                    {
                        correct=1;
                    }
                    else continue;
                }
                else continue;
            }
            words.close();
            if (correct==1)
            {
                cout<<endl<<"Spelling is correct"<<endl;
            }
            if (correct==0)
            {
                int missing = 0, extra = 0, mixed = 0, incorrect = 0, exchanged = 0;
                cout<<endl<<"Spelling is wrong. Possible right spellings are given below:- "<<endl<<endl;
                missing = missingCharacter(input);
                extra = extraCharacter(input);
                mixed = mixedExtraMissing(input);
                incorrect = incorrectArrangement(input);
                exchanged = exchangedCharacters(input);
                if (missing == 0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
                {
                    cout<<endl<<"No such word exist"<<endl;
                }
            }
        }
        else
        {
            cout<<"Not able to open words.txt"<<endl;
        }
        cout<<endl<<"Press any key to continue..."<<endl<<endl;
        _getch();
    }
    return 0;
}
*/