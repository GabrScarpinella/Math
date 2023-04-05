#include<stdbool.h>

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
    for (int i=2;i<n;i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
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
    if (x>0){
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
    for (int i=400;i>0;i--){
        for (int j=400;j>0;j--){
            if ((float)j/i==x||((float)j/i>x*0.999&&(float)j/i<x*1.01)){
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

float sq(float x){
    return x*x;
}

float cb(float x){
    return x*x*x;
}

float power(float x, int y){
    float j=1;
    if(y>=0){
        if (y==2){
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
    for (float i=0;i<x;i+=0.001){
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

long int factorial(int x){
    if (x>1){
        return x*factorial(x-1);
    }
    else if (x==1|x==0){
        return 1;
    }
}

//didn't work
float log(float x, float y){
    for (int i=0; true; i+=0.01){
        if(pow(x,i)==y||pow(x,i)>y*0.995){
            return i;
        }
    }
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