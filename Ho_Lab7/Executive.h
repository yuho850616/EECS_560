/* -----------------------------------------------------------------------------
 * File Name: Executive.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab07
 * Date: 03/31/2019
 ---------------------------------------------------------------------------- */
 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 #include "Node.h"
 #include "TTT.h"

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
