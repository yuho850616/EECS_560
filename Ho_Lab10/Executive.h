/* -----------------------------------------------------------------------------
 * File Name: Executive.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab10
 * Date: 04/21/2019
 ---------------------------------------------------------------------------- */
 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 #include "Maxleftist.h"

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
