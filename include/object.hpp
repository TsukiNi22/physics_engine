/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 06/01/2026 by @authorTsukini

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
        
    /* compare object */
    #define COMPARE_OBJECT(object1, object2) compare_objects(object1.get_id(), object1.get_vectors(), object1.get_pivot(), object1.get_rotation(), object1.get_acceleration(), \
        object2.get_id(), object2.get_vectors(), object2.get_pivot(), object2.get_rotation(), object2.get_acceleration())
    #define COMPARE_OBJECT_PTR(object1, object2) compare_objects(object1->get_id(), object1->get_vectors(), object1->get_pivot(), object1->get_rotation(), object1->get_acceleration(), \
        object2->get_id(), object2->get_vectors(), object2->get_pivot(), object2->get_rotation(), object2->get_acceleration())

//----------------------------------------------------------------//
/* TYPEDEF */

typedef enum type_e {
    SPRITE = 0, // Picture (In the future)
    SHAPE,      // list of point
    CIRCLE,     // origin, {radius, 0.f}
} type_t;

/* vector */
typedef struct vector2_s {
    float x;
    float y;

    // Operator
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

/* predef */
class Actor;
class Object;
class Prop;

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

        // Style
        float r = 0.f;
        float g = 0.f;
        float b = 0.f;

    public:
        // Status
        std::atomic<bool> hitbox = true;
        std::atomic<bool> input = true;
        std::atomic<bool> simulated = true;
        std::atomic<bool> rendered = true;
        std::atomic<int> layout = 0;
        
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

        // Don't use manualy these unsecured thread function, unexpeted behavior might append
        type_t get_id() const {return id;}
        std::vector<vector2> get_vectors() const {return vectors;}
        vector2 get_pivot() const {return rotation_pivot;}
        float get_rotation() const {return rotation;}
        vector2 get_acceleration() const {return acceleration;}
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

        // Style
        float r = 0.f;
        float g = 0.f;
        float b = 0.f;

    public:
        // Status
        std::atomic<bool> hitbox = true;
        std::atomic<bool> simulated = true;
        std::atomic<bool> rendered = true;
        std::atomic<int> layout = 0;
                
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

        // Don't use manualy these unsecured thread function, unexpeted behavior might append
        type_t get_id() const {return id;}
        std::vector<vector2> get_vectors() const {return vectors;}
        vector2 get_pivot() const {return rotation_pivot;}
        float get_rotation() const {return rotation;}
        vector2 get_acceleration() const {return acceleration;}
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
        
        // Physics
        vector2 acceleration{0.f, 0.f}; // Unused always at the original value (only to uniformize the hitbox detection)
        
        // Style
        float r = 0.f;
        float g = 0.f;
        float b = 0.f;

    public:
        // Status
        std::atomic<bool> hitbox = true;
        std::atomic<bool> rendered = true;
        std::atomic<int> layout = 0;
        
        // Constructor
        Prop(type_t type, std::vector<vector2> data) : id(type), vectors(data) {} // Default
        Prop(type_t type, std::vector<vector2> data, vector2 pivot, float deg) : id(type), vectors(data), rotation_pivot(pivot), rotation(deg) {} // With a rotation
        
        // --------- Pre-Function --------- //
        void draw();

        // ----------- Function ----------- //
        bool has_engine() const {if (engine != nullptr) return true; return false;}
        int set_engine(Engine *new_engine) {if (engine != nullptr) return KO; engine = new_engine; return OK;}

        // Don't use manualy these unsecured thread function, unexpeted behavior might append
        type_t get_id() const {return id;}
        std::vector<vector2> get_vectors() const {return vectors;}
        vector2 get_pivot() const {return rotation_pivot;}
        float get_rotation() const {return rotation;}
        vector2 get_acceleration() const {return acceleration;}
};

//----------------------------------------------------------------//
/* PROTOTYPE */

/* calcul */
float compute_drag_coef(type_t id, std::vector<vector2>& vectors);
void compute_acceleration(type_t id, std::vector<vector2>& vectors, const vector2 velocity);
vector2 rotate_point(const vector2& point, const vector2& pivot, const float deg);

/* collisions */
bool compare_objects(
    // First
    type_t id1, const std::vector<vector2>& vectors1,
    const vector2& pivot1, float rotation1,
    const vector2& acceleration1,
    // Second
    type_t id2, const std::vector<vector2>& vectors2,
    const vector2& pivot2, float rotation2,
    const vector2& acceleration2
);

#endif /* OBJECT_H */
