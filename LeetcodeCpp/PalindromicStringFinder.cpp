#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(const string &str)
{
    int i = 0;
    int j = str.length() - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string findFirstPalindromicString(const std::vector<std::string> &array)
{
    for (const string &str : array)
    {
        if (isPalindrome(str))
        {
            return str;
        }
    }
    return "";
}

int main()
{
    vector<string> array = {"hello", "level", "world", "radar", "openai"};
    string firstPalindromicString = findFirstPalindromicString(array);
    if (!firstPalindromicString.empty())
    {
        cout << "First palindromic string in the array: " << firstPalindromicString << std::endl;
    }
    else
    {
        cout << "No palindromic string found in the array." << std::endl;
    }
    return 0;
}
