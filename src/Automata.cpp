#include "Automata.h"
#include <cstring>
#include <iostream>

using namespace std;


Automata::Automata(){
cash=0;
state=OFF;
chos=-1;
count=3;
menu={"COFFE","TEA","CACAO"};
prices={29.99,19.99,49.99};
//cin>>count;
//menu= new char*(count);
//prices= new double(count);
//for (size_t i=0;i<count){cin>>menu[i]; cin>>prices[i];}
}

int Automata::on(){
if (state==OFF){
state=WAIT;
return 0;
}
return -1;
}

int Automata::off(){
if (state==WAIT){
state=OFF;
return 0;
}
return -1;
}




int Automata::finish(){
if (state==COOK){
state=WAIT;
int ret=cash;
cash=0;
chos=-1;
return ret;
}
return -1;
}

STATES Automata::getState() const{
return state;
}


char** Automata::getMenu() const{
char** ret= new char*(count);
char* a,b;
for (size_t i=0; i<count;i++){
strcpy(a,menu[i]);
b=DoubleToStr(prices[i],2);
strcat(a," ");
strcat(a,b);
ret[i]=a;
}
if (state!=OFF)
return ret;
else
return -1;
}



boolean Automata::check() const{
if (state==CHECK){
if (cash>=prices[chos])
return TRUE;
else return FALSE;
}
return -1;
}

int Automata::coin(double a){
if ((state!=OFF) &&(state!=COOK){
cash+=a;
chos=-1;
state=ACCEPT;
return 0
}
return -1;
}


int Automata::choice(int x){
if (state==ACCEPT){
state=CHECK;
chos=x;
return 0;
}
return -1;
}

int Automata::cook(){
if ((state==CHECK)&&check()){
state=COOK;
return 0;
}
return -1;
}

int Automata::cansel(){
if ((state==ACCEPT)||(state==check)){
int ret =cash;
cash=0
chos=-1;
state=WAIT;
return ret;
}
return -1
}

