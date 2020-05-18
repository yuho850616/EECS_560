/* -----------------------------------------------------------------------------
 * File Name: Executive.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab12
 * Date: 05/03/2019
 ---------------------------------------------------------------------------- */
 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 #include "Adjacency.h"

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
