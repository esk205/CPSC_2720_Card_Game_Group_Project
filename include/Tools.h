#ifndef SPLIT_H
#define SPLIT_H

#include <vector>
#include <string>
#include <iostream>


using namespace std;
class Tools
{
public:
    static vector<string> split(const string& str, const string& delim);
    static string base64_encode(unsigned char const* , unsigned int len);
    static string base64_decode(string const& s);
protected:
private:
};

#endif // SPLIT_H
