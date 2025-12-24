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
    #include "woof.hpp"     // Engine
    class Engine;
    #include <stdbool.h>    // boolean
    #include <vector>       // vector
    #include <atomic>       // atomic
    
    //----------------------------------------------------------------//
    /* TYPEDEF */
    #include "error.hpp"    // KO, OK

//----------------------------------------------------------------//
/* TYPEDEF */

typedef enum type_e {
    SPRITE = -2,    // Picture (In the future)
    SHAPE = -1,     // list of point
    POINT = 0,      // 1 point
    LINE,           // 2 point
    TRIANGLE,       // 3 point
    RECTANGLE,      // 4 point
    CIRCLE,         // center + radius
} type_t;

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

    public:
        // Shape
        type_t id;
        std::vector<vector2> vectors;
        
        // Status
        std::atomic<bool> hitbox = true;
        std::atomic<bool> input = true;
        std::atomic<bool> simulated = true;
        std::atomic<bool> rendered = true;
        std::atomic<int> layout = 0;

        // Style
        float r = 0.f;
        float g = 0.f;
        float b = 0.f;
        
        // Constructor
        Actor(type_t type, std::vector<vector2> data) : id(type), vectors(data) {} // Default
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

/* object */
class Object {
    private:
        Engine *engine = nullptr;
        
        // Physics
        vector2 movement_vector{0.f, 0.f};

    public:
        // Shape
        type_t id;
        std::vector<vector2> vectors;
        float rotation = 0.f;
        
        // Status
        std::atomic<bool> hitbox = true;
        std::atomic<bool> simulated = true;
        std::atomic<bool> rendered = true;
        std::atomic<int> layout = 0;
 
        // Style
        float r = 0.f;
        float g = 0.f;
        float b = 0.f;
               
        // Constructor
        Object(type_t type, std::vector<vector2> data) : id(type), vectors(data) {} // Default
        Object(type_t type, std::vector<vector2> data, float deg) : id(type), vectors(data), rotation(def % 360) {} // Default
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

/* prop */
class Prop {
    private:
        Engine *engine = nullptr;

        // Physics
        vector2 movement_vector{0.f, 0.f};

    public:
        // Shape
        type_t id;
        std::vector<vector2> vectors;
        float rotation 0.f;
 
        // Status
        std::atomic<bool> hitbox = true;
        std::atomic<bool> rendered = true;
        std::atomic<int> layout = 0;

        // Style
        float r = 0.f;
        float g = 0.f;
        float b = 0.f;
        
        // Constructor
        Prop(type_t type, std::vector<vector2> data) : id(type), vectors(data) {} // Default
        Prop(type_t type, std::vector<vector2> data, float deg) : id(type), vectors(data), rotation(def % 360) {} // Default
        
        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

#endif /* OBJECT_H */

