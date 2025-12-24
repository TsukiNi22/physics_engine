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
    #include "woof.hpp"     // engine_c
    class engine_c;
    
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
typedef class actor_c {
    private:
        engine_c *engine = nullptr;
        vector2 position{0.f, 0.f};

    public:
        // Constructor
        actor_c() {} // Default
        actor_c(float x, float y) : position{x, y} {} // Position
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(engine_c *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
} Actor;

/* object */
typedef class object_c {
    private:
        engine_c *engine = nullptr;
        vector2 position{0.f, 0.f};

    public:
        // Constructor
        object_c() {} // Default
        object_c(float x, float y) : position{x, y} {} // Position
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(engine_c *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
} Object;

/* prop */
typedef class prop_c {
    private:
        engine_c *engine = nullptr;
        vector2 position{0.f, 0.f};

    public:
        // Constructor
        prop_c() {} // Default
        prop_c(float x, float y) : position{x, y} {} // Position
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(engine_c *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
} Prop;

#endif /* OBJECT_H */

