/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 03/01/2026 by @authorTsukini

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
    /* DEFINE */
    #include "error.hpp"    // KO, OK

    /* physics */
    #define GRAVITY 25.f // 9.81f // earth

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
    vector2_s operator-() const {return {-x, -y};};
    vector2_s operator*(float f) const {return {x * f, y * f};}
    vector2_s operator/(float f) const {return {x / f, y / f};}
    vector2_s operator+(float f) const {return {x + f, y + f};}
    vector2_s operator+(const vector2_s& v) const {return {x + v.x, y + v.y};}
    vector2_s& operator+=(const vector2_s& v) {x += v.x; y += v.y; return *this;}
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

        // Shape
        type_t id;
        std::vector<vector2> vectors;
        vector2 rotation_pivot{0.f, 0.f};
        float rotation = 0.f;
        
        // Physics
        float mass = 1.f; // kg
        vector2 velocity{0.f, 0.f};
        vector2 acceleration{0.f, 0.f};

    public:
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
        Actor(type_t type, std::vector<vector2> data, vector2 pivot, float deg) : id(type), vectors(data), rotation_pivot(pivot), rotation(deg) {} // With a rotation
         
        // --------- Pre-Function --------- //
        void draw();
        void physics(const float delta_time);
        void compute_velocity(const float delta_time, const float drag_coef);

        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

/* object */
class Object {
    private:
        Engine *engine = nullptr;
        
        // Shape
        type_t id;
        std::vector<vector2> vectors;
        vector2 rotation_pivot{0.f, 0.f};
        float rotation = 0.f;
        
        // Physics
        float mass = 1.f; // kg
        vector2 velocity{0.f, 0.f};
        vector2 acceleration{0.f, 0.f};

    public:
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
        Object(type_t type, std::vector<vector2> data, vector2 pivot, float deg) : id(type), vectors(data), rotation_pivot(pivot), rotation(deg) {} // With a rotation
        
        // --------- Pre-Function --------- //
        void draw();
        void physics(const float delta_time);
        void compute_velocity(const float delta_time, const float drag_coef);

        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

/* prop */
class Prop {
    private:
        Engine *engine = nullptr;

        // Shape
        type_t id;
        std::vector<vector2> vectors;
        vector2 rotation_pivot{0.f, 0.f};
        float rotation = 0.f;
        
    public:
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
        Prop(type_t type, std::vector<vector2> data, vector2 pivot, float deg) : id(type), vectors(data), rotation_pivot(pivot), rotation(deg) {} // With a rotation
         
        // --------- Pre-Function --------- //
        void draw();

        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}
};

//----------------------------------------------------------------//
/* PROTOTYPE */

/* calcul */
float compute_drag_coef(type_t id, std::vector<vector2>& vectors);
void compute_movement_dispatch(type_t id, std::vector<vector2>& vectors, const vector2 movement);
vector2 rotate_point(const vector2& point, const vector2& pivot, const float deg);

#endif /* OBJECT_H */

