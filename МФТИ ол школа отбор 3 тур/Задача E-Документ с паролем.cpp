#include <iostream>
#include <string>
#include <stack>
#include <cmath>
 
using namespace std;
 
long long s2d(string s)
{
      long long i,f=0;
      char a;
      long long ce=0,fr=0,pw=1.0;
      for (i=0; i<s.size(); i++)
      {
          a=s[i];
          if (a=='.') 
             f=1;
          else
             if (f==0)
                ce=ce*10.0+(long long)(a-'0');
             else
             {
                fr=fr*10.0+(long long)(a-'0');
                pw=pw*10.0;
             }        
      }
      return ce+fr/pw;
}
 
// Проверка: символ a присутствует в строке s
 
long long isIn(char a, string s)
{
    long long i,n=s.size();
    for (i=0; i<n; i++)
        if (s[i]==a) return i;
    return -1;
}    
 
string * parse(string formula)
{
       long long n=formula.size();
       string *res = new string[n+1]; // один лишний элемент - на случай, если каждый символ есть лексема.
       string tmp;                    // это аккумулятор
       char a;                        // это очередной символ
       long long i,ptr;                     // ptr - номер очередной позиции в res
       
       ptr=0;
       tmp="";
       
       for (i=0; i<=n; i++) res[i]=""; // чистка res
       
       for (i=0; i<n; i++)             // цикл по символам формулы
       {
           a=formula[i];               // очередной символ
           if (isIn(a,"+-*/^()") >= 0) // это разделитель???
           {
                                       // да                    
             if (tmp.size()>0) res[ptr++]=tmp; // если аккумулятор непуст - сбросим его в res
             res[ptr++]=string(1,a);           // а в следующую позицию - найденный разделитель
             tmp="";                           // аккумулятор чистим                 
           }
           else                        // это не разделитель
           {
             tmp=tmp+string(1,a);      // приклеим его к аккумулятору
           }  
       }
       // если в аккумуляторе что-то осталось - сбросим
       if (tmp.size()>0) res[ptr++]=tmp;
       return res;
}
 
long long prty(char op)
{
    switch (op)
    {
       case '(':
            return 0;
       case '+':
       case '-':
            return 1;
       case '*':
       case '/':
            return 2;
       case '^':
            
            return 3;
       default:
            return -1;        
    }
}            
 
double exec(char op, long long a1, long long a2) {
    long long r;   
    switch (op)
    {
        case '+':
             r=a1+a2;
             return r;
        case '-':
             r=a1-a2;
             return r;
        case '*':
             r=a1*a2;
             return r;
        case '/':
             r=a1/a2;
             return r;
        case '^':
             r=pow(a1,a2);
             return r;
    }    
    return 1;
}                        
 
double calc(string formula)
{
    stack <long long> s1;
    stack <char>   s2;
 
    long long i,ilex=0,p1,p2;
    long long v,a1,a2,r;
    string curr; 
 
    string *lex=parse(formula);
 
    while(lex[ilex] != "")
    {
       curr=lex[ilex++];        
       
       if (curr[0]>='0' && curr[0]<='9')    // Число - в s1
       {
          v=s2d(curr);
          s1.push(v);
       }
       else                                 // разделитель
       {                 
          if ((curr[0]=='(') || s2.empty()) // левая скобка или первая операция 
          {    
             s2.push(curr[0]);
          }
          else 
          {
             if (curr[0]==')')              // опустошение до открывающей скобки
             {
                while(1)   
                {
                  if (s2.top()=='(')         
                  {
                     s2.pop();
                     break;
                   }                        
                   a2=s1.top();
                   s1.pop();
                   a1=s1.top();
                   s1.pop();
                   r=exec(s2.top(),a1,a2);
                   s1.push(r);
                   s2.pop(); 
                } 
             }
             else 
             {
                p1=prty(s2.top());          // приоритет вершины стека
                p2=prty(curr[0]);           // приоритет новой операции
             
                if (p2>p1)                  // более приоритетная операция 
                {
                   s2.push(curr[0]);
                }
                else
                {
                   a2=s1.top();
                   s1.pop();
                   a1=s1.top();
                   s1.pop();
                   r=exec(s2.top(),a1,a2);
                   s1.push(r);
                   s2.pop(); 
                   s2.push(curr[0]);
                }
             }   
          }             
       }      
    }           
 
    // Финишное опустошение стека
     
    while(1)
    {
       if (s2.empty())  break;
       a2=s1.top();
       s1.pop();
       a1=s1.top();
       s1.pop();
       r=exec(s2.top(),a1,a2);
       s1.push(r);
       s2.pop(); 
    }
 
    delete [] lex;
     
    return s1.top();
}
 
int main(int argc, char *argv[])
{
    string s;
    long long n;
    long long cnt = 0;
    cin >> s;
    cin >> n;
    string now = "";
    for (int a=0; a < 10; ++a) {
        for (int b=0; b < 10; ++b) {
            for (int c=0; c < 10; ++c){
                for (int d=0; d < 10; ++d) {
                    string new_s = "";
                    for (auto let : s) {
                        if (let == 'a') {
                            new_s += to_string(a);
                        } else if (let == 'b'){
                            new_s += to_string(b);
                        } else if (let == 'c') {
                            new_s += to_string(c);
                        } else if (let == 'd') {
                            new_s += to_string(d);
                        } else {
                            new_s += let;
                        }
                    }
                    long long res = calc(new_s);
                    if (res == n) {
                        cnt++;
                        now = to_string(a) + to_string(b) + to_string(c) + to_string(d);
                    }
                }
            }
        }
    }
    
    
    cout << cnt << endl;
    if (cnt == 1) {
        cout << now << endl;   
    }
}