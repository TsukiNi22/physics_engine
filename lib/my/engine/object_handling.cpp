/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 24/12/2025 by @author Tsukini

File Name:
##  @file object_handling.cpp

File Description:
##  Handle the object list of the engine
\**************************************************************/

#include "object.hpp"
#include "woof.hpp"

/* add */
// Can only be done when the engine is interrupted
int Engine::add_actor(Actor * const actor)     {if (running || actor->has_engine()) return KO; actor->set_engine(this); actors.push_back(actor); return OK;} // Error: KO
int Engine::add_object(Object * const object)  {if (running || object->has_engine()) return KO; object->set_engine(this); objects.push_back(object); return OK;} // Error: KO
int Engine::add_prop(Prop * const prop)         {if (running || prop->has_engine()) return KO; prop->set_engine(this); props.push_back(prop); return OK;} // Error: KO
        
/* remove */
// Can only be done when the engine is interrupted
int Engine::remove_actor(Actor * const actor)      {if (running) return KO; actors.erase(std::remove(actors.begin(), actors.end(), actor), actors.end()); return OK;} // Error: KO
int Engine::remove_object(Object * const object)   {if (running) return KO; objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end()); return OK;} // Error: KO
int Engine::remove_prop(Prop * const prop)         {if (running) return KO; props.erase(std::remove(props.begin(), props.end(), prop), props.end()); return OK;} // Error: KO

