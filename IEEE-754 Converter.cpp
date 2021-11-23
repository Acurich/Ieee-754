#include <iostream> 
#include <string>
using namespace std;
unsigned long long itc_len(string number) {
	unsigned long long razmer = 0;
	while (number[razmer] != '\0')razmer++;
	return razmer;
}
int itc_size(string number) 
{
	int g = 0;
	while (number[g] != '\0')
		g++;
	return g;
}
int itc_len_num(long long acur)
{
    int kr=0;
    if(acur<0)
    {
        acur=acur*(-1);
    }
    if(acur==0)
    {
        return 1;
    }
    while(acur>0)
    {
        kr=kr+1;
        acur=acur/10;
    }
    return (int(kr));
}

string itc_reverse_str(string number){
    string result = "";
    for (int i = 0; i < itc_len(number); i++){ result += number[itc_len(number)-i-1]; }
    return result;
}
int expon(string number) 
{
	int dotoch = 0, posl = 0, count = 0, i = 0;
	int razmer = itc_size(number);
	while (i < razmer) // ищем "."
	{
		if (number[i] == '.')
		{
			dotoch = i;
			break;
		}
		i++;
	}
	i = 0;
	while (i < razmer) 
	{
		if (number[i] != '.')
		{
			if (number[i] == '1')
			{
				posl = count + 1; 
				break;
			}
			count++;
		}
		i++;
	}
	return dotoch - posl;
}
string itc_toUpper(string number){
    for(long long i = 0; i < itc_len(number); i++){
        if(number[i] >= 'a' && number[i] <= 'z') number[i] -= 32;
    }
    return number;
}

unsigned long long itc_toInt(string number){
    long long newnumber = 0;
    for(long long i = 0; i < itc_len(number); i++){
        newnumber += number[i] - 48;
        newnumber *= 10;
    }
    newnumber /= 10;
    return newnumber;
}

string itc_slice_str(string number, int nachalo, int konec){
    long long dlina = itc_len(number);
    string result;
    if((konec > dlina) and (nachalo < dlina)){
        for(int i = nachalo; i < dlina; i++){
            result = result + number[i];
        }
        return result;
    }
    if(nachalo > konec){
        return number;
    }
    for(int i = nachalo; i <= konec; i++){
        result = result + number[i];
    }
    return result;
}

string itc_toString(unsigned long long number){
    string newnumber = "";
    string answer = "";
    if(number == 0) return "0";
    while(number > 0){
        newnumber += number % 10 + 48;
        number /= 10;
    }
    for(long long i = itc_len(newnumber) - 1; i >=0; i--){
        answer += newnumber[i];
    }
    return answer;
}

long long bin_num_celliy(long long number){
    int chislo;
    long long result = 0, newnumber = 0, dlina = 0;
    while(number > 0){
        chislo = number % 2;
        newnumber = newnumber * 10 + chislo;
        number = number / 2;
        dlina++;
    }
    while(dlina > 0){
        chislo = newnumber % 10;
        result = result * 10 + chislo;
        newnumber = newnumber / 10;
        dlina--;
    }
    return result;
}

string mantissa(string number) 
{
	string result = "";
	int i = 0, count = 0;
	bool flag = false;
	while (i < itc_size(number) && count < 23)
	{
		if (flag)
		{
			if (number[i] != '.')
			{
				result += number[i];
				count++;
			}
		}
		if (number[i] == '1') 
			flag = true;
		i++;
	}
	while (count < 23) 
	{
		result += "0";
		count++;
	}
	return result;
}

string bindrob(string number){
    string chislo = "";
    int dlina = itc_len(number);
    unsigned long long newnumber = itc_toInt(number);
    unsigned long long por = 1;
    for (long long i = 0;i < dlina; i++){
    por *= 10;
    }
    for(int j = 0; j <64; j++){
        newnumber *= 2;
        if (itc_len_num(newnumber) > dlina){
        chislo += "1";
        newnumber %= por;

        }
        else
        chislo += "0";
}
    return chislo;
}



int main() {
    string number;
    cin >> number;
    cout << expon(number);
}
