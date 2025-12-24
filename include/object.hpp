/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 24/12/2025 by @authorTsukini

File Name:
##  @file object.hpp

File Description:
##  Header for the different engine's object
\**************************************************************/

#ifndef OBJECT_H
    #define OBJECT_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <stdbool.h>    // boolean
    #include "woof.hpp"     // Engine
    class Engine;
    
    //----------------------------------------------------------------//
    /* TYPEDEF */
    #include "error.hpp"    // KO, OK

//----------------------------------------------------------------//
/* TYPEDEF */

/* vector */
typedef struct vector2_s {
    float x;
    float y;
} vector2;
typedef struct vector3_s {
    float x;
    float y;
    float z;
} vector3;

/* actor */
class Actor {
    private:
        Engine *engine = nullptr;
        vector2 position{0.f, 0.f};

    public:
        // Constructor
        Actor() {} // Default
        Actor(float x, float y) : position{x, y} {} // Position
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

/* object */
class Object {
    private:
        Engine *engine = nullptr;
        vector2 position{0.f, 0.f};

    public:
        // Constructor
        Object() {} // Default
        Object(float x, float y) : position{x, y} {} // Position
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

/* prop */
class Prop {
    private:
        Engine *engine = nullptr;
        vector2 position{0.f, 0.f};

    public:
        // Constructor
        Prop() {} // Default
        Prop(float x, float y) : position{x, y} {} // Position
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

#endif /* OBJECT_H */

