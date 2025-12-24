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
##  @file stack.hpp

File Description:
##  Definition of the stack for the engine
\**************************************************************/

#ifndef STACK_H
    #define STACK_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <vector>       // vector
    #include <mutex>        // mutex
    #include <algorithm>    // remove
    #include "woof.hpp"     // Engine
    class Engine;

//----------------------------------------------------------------//
/* TYPEDEF */

/* task_id */
typedef enum task_id_e {
    MOVE = 0,
} task_id;

/* task */
typedef struct task_s {
    const task_id id;
    const char * const data;
} task_t;

/* stack */
class Stack {
    private:
        Engine *engine;
        std::vector<task_t*> stack;
        std::mutex mtx;
    
    public:
        // --------- Pre-Function --------- //
        void resolve();
        
        // ----------- Function ----------- //
        const task_t * push(const task_id id, const char * const data) {std::lock_guard<std::mutex> lock(mtx); task_t * const task = new task_t{id, data}; stack.push_back(task); return task;};
        void pop(const task_t * task) {std::lock_guard<std::mutex> lock(mtx); stack.erase(std::remove(stack.begin(), stack.end(), task), stack.end()); delete task;};
        void clear() {std::lock_guard<std::mutex> lock(mtx); for (task_t *p: stack) delete p; stack.clear();};
        
        // ---------- Constructor --------- //
        Stack(Engine *new_engine) : engine(new_engine) {} // Default
        
        // ----------- Destructor --------- //
        ~Stack() {clear();}
};

#endif /* STACK_H */
