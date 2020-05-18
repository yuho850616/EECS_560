/* -----------------------------------------------------------------------------
 * File Name: Executive.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab05
 * Date: 02/28/2019
 ---------------------------------------------------------------------------- */
 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 #include "Node.h"
 #include "BST.h"

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
