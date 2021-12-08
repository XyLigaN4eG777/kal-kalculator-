#include <iostream>           // ymnojenie rabotaet tolko po polnolyniyam
using namespace std;                 


long itc_len(string str) {
    int i = 0;
    while (str[i] != '\0'){ 
        i += 1;
    }
    return i;
}


string itc_slice_str(string str, int start, int last){
    string newstr = "";
    if(last > itc_len(str)) last = itc_len(str) - 1;
    for(int i = start; i <= last; i++) newstr += str[i];
    return newstr;
}

string module(string num){
    return itc_slice_str(num, 1, itc_len(num));
}


string itc_reverse_str(string str){
    string newstr = "";
    for(int i = itc_len(str) - 1; i >= 0; i--){
        newstr += str[i];
    }
    return newstr;
}
string itc_max_num_str(string str1, string str2){
    long long len1 = itc_len(str1), len2 = itc_len(str2);
    if (len1 > len2)
        return "1";
    if (len2 > len1)
        return "2";
    for(long long i = len1; i >= 0; i--){
        if ((str1[i] - 48) > (str2[i] - 48))
            return "1";
        if ((str2[i] - 48) > (str1[i] - 48))
            return "2";
    }
    return "0";
}
string sort_dlin(string num1, string num2){
    string otvet = "";
    string new_str = "";
    long long len1 = itc_len(num1), len2 = itc_len(num2);
        for(long long i = 0; i < (len1 - len2); i++){
            new_str += "0";
        }
        new_str += num2;
    return new_str;
}


string lish_zero(string str){
    string new_str = "";
    if (str[0] == '-'){
        str = itc_slice_str(str, 1, itc_len(str));
        new_str += "-";
    }
    bool bol = true;
    long long i = 0;
    while(bol && i < itc_len(str)){
        if (str[i] != '0'){
            new_str += str[i];
            bol = false;
        }
       i++;
    }
    if (new_str == "")
        new_str += "0";
    new_str += itc_slice_str(str, i, itc_len(str));
    return new_str;
}

string s(string n1, string n2)
{
    string newstr = "";
    bool hop = false;
    while(itc_len(n1) < itc_len(n2))
        n1 = "0" + n1;
    while(itc_len(n2) < itc_len(n1))
        n2 = "0" + n2;
    long long len = itc_len(n1);
    for(long long i = len - 1; i >= 0 || hop; i--){
        if(i >= 0){
            newstr += (n1[i] - 48 + n2[i] - 48 + hop) % 10 + 48;
            if(n1[i] - 48 + n2[i] - 48 + hop > 9)
                hop = true;
            else
                hop = false;
        }
        else{
            newstr += "1";
            hop = false;
        }
    }
    return itc_reverse_str(newstr);
}




string v(string str1, string str2)
{
    string otv = "", ch;
    bool znak = false;
    int rasrad = 1;
    str1 = lish_zero(str1);
    str2 = lish_zero(str2);
    long long n1, n2, len1 = itc_len(str1), len2 = itc_len(str2);
    if(itc_max_num_str(str1, str2) == "2"){
        ch = sort_dlin(str2, str1);
        str1 = str2;
        str2 = ch;
        znak = true;
        len1 = itc_len(str1);
    }
    else
        str2 = sort_dlin(str1, str2);
    for(long long i = len1 - 1; i >= 0; i--){
        n1 = (str1[i] - 48) - 1 + rasrad;
        n2 = str2[i] - 48;
        ch = (((10 + n1) - n2) % 10) + 48;
        otv += ch;
        rasrad = ((10 + n1) - n2) / 10;
    }
    if(znak)
        otv += "-";
    return lish_zero(itc_reverse_str(otv));

}




string u(string n1, string n2)
{
    return "gg";
}




int invalid_check(string n1, string n2, string z)
{
    int a = 1;
    if (z != "1" && z != "2" && z != "3")
        a = 228;
    long long len1 = itc_len(n1);
    long long len2 = itc_len(n2);
    for(long long i = 0; i < len1; i++){
        string l;
        l = n1[i];
        if(l != "2" && l != "1" & l != "3" && l != "4" && l != "5" && l != "6" && l != "7" && l != "8" && l != "9" && l != "0" && l != "-" && l != "+")
            a = 228;
    }
    for(long long p = 0; p < len2; p++){
        string k;
        k = n2[p];
        if(k != "2" && k != "1" && k != "3" && k != "4" && k != "5" && k != "6" && k != "7" && k != "8" && k != "9" && k != "0" && k != "-" && k != "+")
            a = 228;
    }
    return a;
}




string coonector(string n1, string n2, string z)
{
    string z1;
    string z2;
    z1 = n1[0];
    z2 = n2[0];
    string n11;
    string n21;
    if(z == "1") // ñëîæåíèå
    {
        if((z1 != "-") && (z2 != "-"))
            return s(n1, n2);
        if((z1 == "-") && (z2 != "-"))
        {
            n11 = module(n1);
            return v(n2, n11);
        }
        if((z1 != "-") && (z2 == "-"))
        {
            n21 = module(n2);
            return v(n1, n21);
        }
        if((z1 == "-") && (z2 == "-"))
        {
            n11 = module(n1);
            n21 = module(n2);
            return "-" + s(n11, n21);
        }
    }
    else // âû÷èòàíèå
    {
         if((z1 != "-") && (z2 != "-"))
            return v(n1, n2);
        if((z1 == "-") && (z2 == "-"))
        {
            n11 = module(n1);
            n21 = module(n2);
            return v(n21, n11);
        }
        if((z1 == "-") && (z2 != "-"))
        {
            n11 = module(n1);
            return "-" + s(n11, n2);
        }
        if((z1 != "-") && (z2 == "-"))
        {
            n21 = module(n2);
            return s(n21, n1);
        }

    }

}




int main()
{
    string n1, n2;
    string z;
    cout << "Enter the first number" << endl;
    cin >> n1;
    cout << "Enter the second number" << endl;
    cin >> n2;
    cout << "1 - +" << endl << "2 - -" << endl << "3 - *" << endl;
    cin >> z;
    int g = invalid_check(n1, n2, z);
    if (g == 228)
        cout << "invalid"<< endl;
    if((z == "1") || (z == "2"))
        cout << coonector(n1, n2, z);
    return 0;
}
