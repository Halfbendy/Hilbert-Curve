//Driver Jesse Gonzales
//Navigator Louis Mondesir
#include <string>
using namespace std;
#include "hilbert.h"
#include <math.h>

//initializes an InstructionList and Turtle to draw a Hilbert curve
//level = number of times to apply substitution (level = 8)
//size = pixels of output (size = 600)
    
    
HilbertCurve::HilbertCurve(int level, int size)
    :rules(),  turtle(size, size)
{    
    //make even and odd instructions to follow
    
    InstructionList odd; 
    InstructionList* o; 


    odd.append(TURN_LEFT); 
    odd.append(EVEN);
    odd.append(FORWARD);
    odd.append(TURN_RIGHT);
    odd.append(ODD);
    odd.append(FORWARD);
    odd.append(ODD);
    odd.append(TURN_RIGHT);
    odd.append(FORWARD);
    odd.append(EVEN);
    odd.append(TURN_LEFT);
    o = &odd; 
    

    InstructionList even; 
    InstructionList* e;
    even.append(TURN_RIGHT); 
    even.append(ODD);
    even.append(FORWARD);
    even.append(TURN_LEFT);
    even.append(EVEN);
    even.append(FORWARD);
    even.append(EVEN);
    even.append(TURN_LEFT);
    even.append(FORWARD);
    even.append(ODD);
    even.append(TURN_RIGHT);
    e = &even; 
    //place instructions in map to be referenced
    unordered_map<hilbert_t, const InstructionList*> sub = { {EVEN,e}, {ODD,o}}; 
    //sub.emplace(ODD, o);
    //sub.emplace(EVEN, e); 
      
      //odd instructions= L,E,F,R,O,F,O,R,F,E,L 
      //even instructions= R,O,F,L,E,F,E,L,F,O,R
    rules.append(TURN_LEFT); 
    rules.append(EVEN);
    rules.append(FORWARD);
    rules.append(TURN_RIGHT);
    rules.append(ODD);
    rules.append(FORWARD);
    rules.append(ODD);
    rules.append(TURN_RIGHT);
    rules.append(FORWARD);
    rules.append(EVEN);
    rules.append(TURN_LEFT); 
      
    //give turle the instructions to follow
    for (int i = 1; i < level; i++)
      {
         rules.substitute(sub);
      }
    //cout << "Odd: " << odd << endl << "Even: " << even << endl;
    //cout << "Rules: " << rules << endl;
    //rules.substitute(sub);
    
    double distance = size/(pow(2,(level))); 
    rules.setDistance(distance); 
     
    //cout << rules << endl;
    //rules.substitute(sub);
    //cout << "Rules: " << rules << endl;
    //cout << odd << endl; 
    //cout << "calling follow"; 
    turtle.follow(rules);
    
    /*//odd instructions= L,E,F,R,O,F,O,R,F,E,L 
    InstructionList* odd;
    
    //even instructions= R,O,F,L,E,F,E,L,F,O,R
    InstructionList* even;
    
    //place instructions in map to be referenced
    unordered_map<hilbert_t, const InstructionList*> sub; 
    sub.emplace(ODD, odd);
    sub.emplace(EVEN, even); 
   
      
    //give turle the instructions to follow
    rules.append(TURN_LEFT);
    rules.append(FORWARD); 
    rules.append(TURN_RIGHT);
    rules.append(FORWARD);
    rules.append(TURN_RIGHT); 
    rules.append(FORWARD); 
    rules.append(TURN_LEFT); 

    rules.setDistance(50);

    //prints a level one curve
    turtle.follow(rules); */
    
    

    
}