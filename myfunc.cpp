#include "myfunc.h"
int calculate(string s) {
    int  ret;
    long  val=0;
    stack<int> stk;
    char sign ='+';
    char signReserve;
    for (int i = 0; i <s.length() ; ++i) {
        if (isdigit(s[i])) val = val*10 + (s[i]-'0');
        if (s[i] == '(') {
            signReserve = sign;
            sign = '+';
            stk.push(INT_MAX);

        }
        if (s[i] == ')'){
            sign = signReserve;
            int tmp=0;
            while ( stk.top() != INT_MAX){
                tmp += stk.top();
                stk.pop();
            }
            stk.pop();
            stk.push(tmp);
        }
        if ((!isdigit(s[i]) and s[i]!=' ' ) || i==s.length()-1){
            switch (sign) {
                case '+':stk.push(val);break;
                case '-':stk.push(-val);break;
                case '*':{
                    int temp =stk.top()*val;
                    stk.pop();
                    stk.push(temp);
                    break;
                }
                case '/':{
                    int temp =stk.top()/val;
                    stk.pop();
                    stk.push(temp);
                    break;
                }
            }
            val = 0 ;
            sign = s[i];
        }
    }
    while (!stk.empty()){
        ret += stk.top();
        stk.pop();

    }
    return ret;
}

