/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab08
 * Date: 04/05/2019
 ---------------------------------------------------------------------------- */
 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 #include "Minheap.h"
 #include "Maxheap.h"

 class Executive
 {
   private:

   public:
     //@pre none
     //@post to read the file and let user interact with hashtable
     //@return none
     Executive(std::string fileName);
     ~Executive();
 };
 #endif
