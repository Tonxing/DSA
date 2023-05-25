#include <iostream>

using namespace std;

string XORoperation(string a, string b)
{
    string result = "";
    int n = b.length();

    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

string mod2div(string dividend, string divisor)
{
    int part = divisor.length();
    string slice = dividend.substr(0, part);
    int n = dividend.length();

    while (part < n)
    {
        if (slice[0] == '1')
            slice = XORoperation(divisor, slice) + dividend[part];
        else
            slice = XORoperation(std::string(part, '0'), slice) + dividend[part];
        part += 1;
    }
    if (slice[0] == '1')
        slice = XORoperation(divisor, slice);
    else
        slice = XORoperation(std::string(part, '0'), slice);

    return slice;
}

void encodeData(string message, string gp)
{
    int l_gp = gp.length();

    string appended_data = (message + std::string(l_gp - 1, '0'));

    string remainder = mod2div(appended_data, gp);

    string codeword = message + remainder;
    cout << "Remainder : " << remainder << "\n";
    cout << "Encoded Data (Data + Remainder) :" << codeword
         << "\n";
}

void receiver(string message, string gp)
{
    string currxor = mod2div(message.substr(0, gp.size()), gp);
    int curr = gp.size();
    while (curr != message.size())
    {
        if (currxor.size() != gp.size())
        {
            currxor.push_back(message[curr++]);
        }
        else
        {
            currxor = mod2div(currxor, gp);
        }
    }
    if (currxor.size() == gp.size())
    {
        currxor = mod2div(currxor, gp);
    }
    if (currxor.find('1') != string::npos)
    {
        cout << "there is some error in data" << endl;
    }
    else
    {
        cout << "correct message received" << endl;
    }
}

int main()
{
    string message, gp;
    cout << "Enter the message: " << endl;
    cin >> message;
    cout << "Enter generator polynomial: " << endl;
    cin >> gp;

    encodeData(message, gp);

    cout << "\nReceiver side..." << endl;
    receiver(message + mod2div(message + std::string(gp.size() - 1, '0'), gp), gp);

    return 0;
}