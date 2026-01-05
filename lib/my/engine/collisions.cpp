/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 05/01/2026 by @authorTsukini

File Name:
##  @file collisions.cpp

File Description:
##  Check for any potential collisions between 2 objects
\**************************************************************/

#include "object.hpp"

// Pre-Operator build
bool Actor::operator&&(const Actor& other) const {return false;};
bool Actor::operator&&(const Object& other) const {return false;};
bool Actor::operator&&(const Prop& other) const {return false;};

bool Object::operator&&(const Actor& other) const {return false;};
bool Object::operator&&(const Object& other) const {return false;};
bool Object::operator&&(const Prop& other) const {return false;};

bool Prop::operator&&(const Actor& other) const {return false;};
bool Prop::operator&&(const Object& other) const {return false;};
bool Prop::operator&&(const Prop& other) const {return false;};

/*
Uniformize the the input into:
(id1, vectors1, pivot1, rotation1, acceleration1
id2, vectors2, pivot2, rotation2, acceleration2)

First: compare with max&min x and y to get a first aproxmative check
Second: if the first is true check with the real border of the object

if the second is true then return true in other case no collisions between the tow given object
*/
