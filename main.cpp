// Daniel Hernández Toledo
// 0243179

#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include <valarray>

// Versión más compleja
using namespace std;
double prueba (string);

int main() {
    // x;2.0;/;10;+;sen;y;0.3;/;5;+;cos;/

    double x = prueba("x;0.5;*;10;+;sin;0.3;y;*;5;+;cos;/");
    cout<<"El ultimo resultado es "<<x<<endl;

}
double prueba(string par) {
    double lv01= 0, lv02= 0, lv03 =0;
    cout << "Se convierte de string a double" << endl;
    double vaciox = 0;
    double vacioy = 0;
    stack<double> lStack;
    istringstream lExp(par);



    for (double i = -10; i <= 10; i+=0.25) {
        istringstream lExp(par);
        string lStr = "";
        for (double j = 10; j > -10.25 ; j-=0.25) {
            istringstream lExp(par);
            string lStr = "";
            while (getline(lExp, lStr, ';')) {
                //cout << lStr << endl;
                if (lStr == "x") {

                    //cout << "Se leyó como algo más x!" << endl;
                    vaciox += i;
                    lStr = to_string(i);
                    //cout << lStr << endl;

                } else if (lStr == "y") {

                    //cout << "Se leyó como algo más y!" << endl;
                    vacioy += j;
                    lStr = to_string(-j);
                    //cout << lStr << endl;
                }

                if (isdigit(lStr[0])) {
                    lStack.push(stod(lStr));
                } else {
                    if ((lStr.length() > 1) && (lStr[0] == '-')) {
                        lStack.push(stod(lStr));
                    } else {
                        if (lStr.length() == 1) {
                            //cout<<"EL valor de lv02 es "<<lv02<<endl;
                            //cout<<"EL valor de lv01 es "<<lv01<<endl;
                            lv02 = lStack.top();
                            lStack.pop();
                            lv01 = lStack.top();
                            lStack.pop();
                            //cout<<"EL valor de lv02 es "<<lv02<<endl;
                            //cout<<"EL valor de lv01 es "<<lv01<<endl;
                            switch (lStr[0]) {
                                case '+':
                                    lv03 = lv01 + lv02;
                                    //cout << lv03 << endl;

                                    break;
                                case '-':
                                    lv03 = lv01 - lv02;
                                    break;
                                case '*':
                                    lv03 = lv01 * lv02;
                                    break;
                                case '/':
                                    lv03 = lv01 / lv02;
                                    //cout << lv03 << endl;
                                    break;
                                case '%':
                                    lv03 = (int) lv01 % (int) lv02;
                                    break;

                            }

                            lStack.push(lv03);
                        } else {
                            lv02 = lStack.top();
                            lStack.pop();
                            if (lStr == "sin") {
                                lv03 = sin(lv02);

                            } else if (lStr == "cos") {
                                lv03 = cos(lv02);

                            } else if (lStr == "tan") {
                                lv03 = tan(lv02);
                            } else if (lStr == "pow") {
                                lv01 = lStack.top();
                                lStack.pop();
                                lv03 = pow(lv01, lv02);
                            }
                            lStack.push(lv03);
                        }
                    }
                }
            }
            cout << "X evaluado en  " << i << " y evaluado en Y " << -j << " ES igual "<<lv03 << endl;
        }

    }
    return lv03;
}