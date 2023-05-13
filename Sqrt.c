#include<stdbool.h>
#include<stdint.h>

#define PI 3.1415926535897932
#define E 2.7182818284590452

bool isDivisible(int x, int y){
    return (x%y==0)?true:false;
}

bool isEven(int x){
    return isDivisible(x,2);
}

bool isNegative(float x){
    return (x<0)?true:false;
}

bool isPrime(int n){
    if(isEven(n)&&n!=2){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool isCloser(float a, float b, float c){
    return (absolute(b-c)>absolute(b-a));
}

int firstDecimalPlace(float n){
    return trunc((n-trunc(n))*10);
}

float avg(float a, float b){
    return (a+b)/2;
}

float absolute(float x){
    return (x>=0)?x:x*-1;
}

float max(float x, float y){
    return (x>=y)?x:y;
}

float min(float x, float y){
    return (x<=y)?x:y;
}

int trunc(float x){
    return x;
}

int round(float x){
    float y=(x>0)?trunc(x)+0.5:trunc(x)-0.5;
    if(x>0){
        return (x>y)?trunc(x)+1:trunc(x);
    }
    else{
        return (x<y)?trunc(x)-1:trunc(x);
    }
}

int ceiling(float x){
    return (x>0)?trunc(x)+1:trunc(x);
}
int floor(float x){
    return (x>0)?trunc(x):trunc(x)-1;
}

void makeFraction(float x, int* numerator,int* denominator){
    for(int i=400;i>0;i--){
        for(int j=400;j>0;j--){
            if((float)j/i==x||((float)j/i>x*0.999&&(float)j/i<x*1.01)){
                if(isNegative(x)){
                    *numerator=j*-1;
                    *denominator=i; 
                }
                else{
                    *numerator=j;
                    *denominator=i;
                }
            }
        }
    }
}

float fmod(float a, float b){
    float f=a;
    for(int i=0; f>b; i++){
        f-=b;
    }
    return f;
}

float sq(float x){
    return x*x;
}

float cb(float x){
    return x*x*x;
}

float power(float x, int y){
    float j=1;
    if(y>=0){
        if(y==2){
            j=sq(x);
            return j;
        }
        else if(y==3){
            j=cb(x);
            return j;
        }
        for(int i=0;i<y;i++){
            j*=x;
        }
    }
    else{
        for(int i=0;i>y;i--){
            j/=x;
        }
    }
    return j;
}

float rt(float x, int y){
    for(int i=0;i<x;i++){
        if(power(i,y)==x){
            return i;
        }
    }
    for(float i=0;i<x;i+=0.001){
        if(power(i,y)==x||power(i,y)>x*0.9995){
            return i;
        }
    }
}

float sqrt(float x){
    return rt(x,2);
}

float cbrt(float x){
    return rt(x,3);
}

float Qsqrt(float x){
    int n=1;
    for(int i=1;i<x;i++){
        if(isCloser(i*i, x, n*n)){
            n=i;
        }
    }
    float m=x-n*n;
    return n+(m/(2*n));
}

float pow(float x, float y){
    if(trunc(y)==y){
        return power(x,y);
    }
    else{
        int num, den;
        makeFraction(y,&num,&den);
        float x2=power(x,num);
        return rt(x2,den);
    }
}

float map(float x, float fl, float fh, float tl, float th) {
  return (x-fl)*(th-tl)/(fh-fl)+tl;
}

uint64_t factorial(int x){
    if (x>1){
        return x*factorial(x-1);
    }
    else if (x==1|x==0){
        return 1;
    }
}

float log(float x, float y){
    for (int i=0; true; i+=0.01){
        if(pow(x,i)==y||pow(x,i)>y*0.995){
            return i;
        }
    }
}

float degToRad(float deg){
    return deg*(PI/180);
}

//trigonometric functions

float sin(float theta){
    int h;
    float t=theta;
    for(int h=0; t>PI; h++){
        t-=PI;
    }
    int f=(isEven(h))?-1:1;
    return (16*t*(PI-t))/((5*PI*PI)-((4*t)*(PI-t)))*f;
}

float cos(float theta){//cos and tan sometimes change the number's sign
    return sin(theta+PI/2);
}

float tan(float theta){
    return sin(theta)/cos(theta);
}

float hypot(float a, float b){
    return sqrt(sq(a)+sq(b));
}

//constants

float pi(int accuracy){
    float pf=0;
    int a=0;
    for (int i=1; i<accuracy; i+=2){
        if(isEven(a)){
            pf=pf+1.0/i;
        }
        else{
            pf=pf-1.0/i;
        }
        a++;
    }
    return pf*4;
}

float e(int accuracy){
    float e=1;
    for(int i=1; i<accuracy; i++){
        e+=1.0/factorial(i);
    }
    return e;
}

float phi(){
    return (1+sqrt(5))/2;
}

float tau(int accuracy){
    return pi(accuracy)*2;
}