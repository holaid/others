#include<bits/stdc++.h>
using namespace std;

/*string s1="send";
string s2="more";
string s3="money";*/

/*string s1="base";
string s2="ball";
string s3="games";*/

/*string s1="YOUR";
string s2="YOU";
string s3="HEART";*/

string s1="TWO";
string s2="TWO";
string s3="FOUR";


string unique_char="";
int num[10]={0};

map <char, int> mapping;        //for storing the character with mapped number
map <char, int>::iterator iter,iter2;       // iterator to iterate over the map;
void uni_char()     // this function will insert unique character from all string to the map and will assign -1 initially
{
     for(int i=0; i<s1.size(); i++)
    {
        mapping.insert({s1[i],-1});
    }
    for(int i=0; i<s2.size(); i++)
    {
        mapping.insert({s2[i],-1});
    }
    for(int i=0; i<s3.size(); i++)
    {
        mapping.insert({s3[i],-1});
    }
    for(iter=mapping.begin(); iter!=mapping.end(); iter++)      // this will be our unique character string
    {
        unique_char = unique_char + iter->first;
    }
}

int sizeee(char *ptr)   // to determine the size of a string
{
    int a=0;
    int count = 0;
    while (*(ptr + a) != '\0')
    {
        ++count;
        ++a;
    }
    return count;
}

int mapping_to_num(string s)    //Convert number of string to mapped integer
{
    int n = s.size();
    int number=0;
    for(int i=0; i<n; i++)
    {
        number = 10*number + mapping[s[i]];
    }
    return number;
}

void cryp(char *c)
{
    //Base Case
    if(sizeee(c)==0)        // it means it has reached the maximum depth possible
    {

        int n1=mapping_to_num(s1);
        int n2=mapping_to_num(s2);
        int n3=mapping_to_num(s3);

        int total_length1= (s1.size()+s2.size()+s3.size());         // total length 1 and length 2 for eliminating those case where fist char of the string is mapped to zero
        int total_length2= floor(log10(n1)+1)+floor(log10(n2)+1)+floor(log10(n3)+1);

        if((n1+n2)==n3  &&  total_length1==total_length2)
        {
            cout<<s1<<"="<<n1<<"        "<<s2<<"="<<n2<<"       "<<s3<<"="<<n3<<"       \n";

            for(iter=mapping.begin(); iter!=mapping.end(); iter++)
            {
                cout<<iter->first<<" --> "<<iter->second<<endl;
            }
            cout<<"\n\n";
        }
        return;
    }
    for(int i=0; i<10; i++)
    {
        if(num[i]==0)  // means this number is not used before
        {
            num[i] = 1; // marking this number as mapped
            mapping[c[0]] = i; //mapping the number for the character c[0];
            cryp(c+1);  // passing the next character
            num[i] = 0; // unmapping the used number while backtracking
            mapping[c[0]] = -1;    // unmapping assigned number for the character while backtracking
        }
    }
}

int main()
{
    uni_char();
    char a[unique_char.length()+1];
    strcpy(a, unique_char.c_str()); // to convert the unique string into the array of charecter
    cryp(a);
    return 0;
}
