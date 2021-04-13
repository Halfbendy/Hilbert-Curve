//Driver Louis Mondesir
//Navigator Jesse Gonzales

#include <iostream>
#include <unordered_map>

#include "instruction_list.h"

using namespace std;

//adds given instruction
void InstructionList::append(hilbert_t t){
  
    /*InstructionList::node_t* end = tail;
    InstructionList::node_t* add;

    
    add->move = t;
    add->next = NULL; 
    end->next = add; 
    tail = add;*/
    
    
    //add instruction to node and move next node to the tail
    //cout << "appending to list\n";
    InstructionList::node_t* add = new node_t;
    
    
    //if list is empty add move and set append to head and tail
    if(head == NULL){
        add->move = t;
        head = add; 
        tail = add;
        add->next = NULL; 
    }
    //creates the second node in the list and moves the tail
    else if(head->next == NULL){
        //cout << "add another node\n";
        add->move = t;
        head->next = add;
        tail = add; 
        add->next = NULL; 
    }
    //creates node at end of list and moves the tail
    else{
        //cout << "adding to end\n";
        add->move = t;
        tail->next = add;
        tail = add; 
        add->next = NULL;

    }
    
}

//iterates through Instruction list, replacing instructions accordingly
void InstructionList::substitute(const unordered_map<hilbert_t ,const InstructionList* >& map){

  node_t* temp; //= new node_t;
  node_t* hold; //= new node_t;

  temp = head;
  
   //cout << "This is the head before: " << head << " " << head->move << endl;
   //cout << "This is the tail before: " << tail << " " << tail->move << endl;
  
  //cout << "In here";
  
  //The for loop was supposed to let it be 
  //done for any Move value but it was only substituting the last map element
  //so just made it for EVEN, ODD  
  //for (auto it = map.begin(); it != map.end(); it++)
   //{
      auto it1 = map.at(EVEN);
      auto it2 = map.at(ODD);
      
      //Could work for any substitution but you would need to add them to the map beforehand to avoid error
      /*
      auto it3 = map.at(TURN_LEFT);
      auto it4 = map.at(TURN_RIGHT);
      auto it5 = map.at(FORWARD);
      
      
      */   
      //cout << "In for" << endl;
      while(temp != NULL)
          {
            //cout << endl << "Third: " << temp->move;
            if (temp->move == EVEN)
               {
                  // Caused heap errors
                  /*hold = temp->next;
                  
                  temp->move = it->second->head->move;
                  
                  temp->next = it->second->head->next;
                  
                  it->second->tail->next = hold;
                  
                  temp = hold;*/
                  
                  hold = it1->head;
                  
                  temp->move = hold->move;
                  
                  hold = hold->next;
                  
                  
                  while (hold != NULL)
                     {
                        node_t* insert = new node_t;
                        
                        insert->move = hold->move;
                        
                        insert->next = temp->next;
                        
                        temp->next = insert;
                        
                        hold = hold->next;
                        
                        temp = temp->next;
                        
                        
                     }   
                     }
                 else if (temp->move == ODD)
               {
                  
                  
                  hold = it2->head;
                  
                  temp->move = hold->move;
                  
                  hold = hold->next;
                  
                  
                  while (hold != NULL)
                     {
                        node_t* insert = new node_t;
                        
                        insert->move = hold->move;
                        
                        insert->next = temp->next;
                        
                        temp->next = insert;
                        
                        hold = hold->next;
                        
                        temp = temp->next;
                        
                        
                     }
                     }
                     
          /*
                 else if (temp->move == ODD)
               {
                  
                  
                  temp = hold;
                  
                  hold = it3->head;
                  
                  temp->move = hold->move;
                  
                  hold = hold->next;
                  
                  
                  while (hold != NULL)
                     {
                        node_t* insert = new node_t;
                        
                        insert->move = hold->move;
                        
                        insert->next = temp->next;
                        
                        temp->next = insert;
                        
                        hold = hold->next;
                        
                        temp = temp->next;
                        
                        
                     }
                     }*/ 
                     
                      /*
                 else if (temp->move == ODD)
               {
                  
                  
                  temp = hold;
                  
                  hold = it4->head;
                  
                  temp->move = hold->move;
                  
                  hold = hold->next;
                  
                  
                  while (hold != NULL)
                     {
                        node_t* insert = new node_t;
                        
                        insert->move = hold->move;
                        
                        insert->next = temp->next;
                        
                        temp->next = insert;
                        
                        hold = hold->next;
                        
                        temp = temp->next;
                        
                        
                     }
                     }*/   
                     
                      /*
                 else if (temp->move == ODD)
               {
                  
                  
                  temp = hold;
                  
                  hold = it5->head;
                  
                  temp->move = hold->move;
                  
                  hold = hold->next;
                  
                  
                  while (hold != NULL)
                     {
                        node_t* insert = new node_t;
                        
                        insert->move = hold->move;
                        
                        insert->next = temp->next;
                        
                        temp->next = insert;
                        
                        hold = hold->next;
                        
                        temp = temp->next;
                        
                        
                     }
                     }*/              
     
                 
               //}                 
            temp = temp->next;
            
            
          } 
   
   //cout << "This is the head after: " << head << " " << head->move << endl;
  //cout << "This is the tail after: " << tail << " " << tail->move << endl;
   
}
//deallocate all of the nodes in the list
InstructionList::~InstructionList(){

  node_t* temp  = head;
  //cout << "Head: " << head <<endl;
  node_t* extra = head;
  int i = 0;

  while(temp != NULL)
    {
        extra = extra->next;
        //cout << "Temp: " << temp->move << endl;

        delete temp;
        i++;
        //cout << "Delete temp: " << i << endl;
       

        temp = extra;

    }
    
    head = NULL;
    
}

//print InstructionList as single character seperated by space
ostream& operator<<(ostream& out , const InstructionList& list){

    InstructionList::node_t* temp = list.head;

    while (temp != NULL)
      {
          if (temp->move == FORWARD)
            {
              out << "F ";
            }
          
          else if (temp->move == TURN_LEFT)
            {
              out << "L ";
            }

          else if (temp->move == TURN_RIGHT)
            {
              out << "R ";
            }

          else if (temp->move == ODD)
            {
              out << "O ";
            }

          else if (temp->move == EVEN)  
            {
              out << "E ";
            }

          temp = temp->next;
          
      }
      
      
    //out <<"overload\n";
    return out;
}
