#include <iostream> 
#include <string> 
using namespace std; 
 
char to_String(double ost); 
string Bin(int num); 
string bins(double nums); 
 
string bins(double nums) { 
int num = (int)nums; 
 double ost = nums-(double)num; 
 string bin_ost = ""; 
 int mas[100]; 
 int n = 0; 
 while (num > 0) { 
 mas[n]=num%2; 
 num/=2; 
 n++; 
 } 
 while (ost != 0) { 
 ost*=2; 
 bin_ost+=to_String(ost); 
 ost-=(int)ost; 
 } 
 string final = ""; 
 for (int i = 0; i < n; ++i) { 
 final+=to_String(mas[n-1-i]); 
 } 
 final=final+'.'+bin_ost; 
 return final; 
} 
 
char to_String(double ost) { 
return char((int)ost%10+48); 
} 
 
string Bin(int num) { 
 string str = "", fin=""; 
 
 while (num > 0) { 
 str+=to_String(num%2); 
 num/=2; 
 } 
 for (int i = 0; i < str.length(); ++i) fin+=str[str.length()-1-i]; 
 while (fin.length() != 8) fin= '0'+fin; 
 return fin; 
} 
 
int main() { 
 long double nums; 
 cin >> nums; 
 int bi = 0; 
 if (nums < 0) bi = 1; 
 
 string bin = bins(nums), mas[100], mantiss, por; 
 int n = 0; 
 
 for (int i = 0; i < bin.length(); ++i) { 
 if (bin[i] == '.') { 
 for (int j = i; j > 1; j--) { 
 swap(bin[j-1], bin[j]); 
 n++; 
 } 
 } 
 } 
 
 por = Bin(127+n); 
 for (int i = 2; i < 25; ++i) { 
 mantiss+=(char)bin[i]; 
 } 
 cout << bi << por << mantiss; 
return 0; 
}
