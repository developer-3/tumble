// C++ Standard Libraries
#include <iostream>

// Third-party library
#include <SDL2/SDL.h>
// Include GLAD
#include <glad/glad.h>

#include "../src/tumble.h"


int main(int argc, char* argv[]){

    // Create a window data type
    // This pointer will point to the 
    // window that is allocated from SDL_CreateWindow
    SDL_Window* window=nullptr;

    // Initialize the video subsystem.
    // If it returns less than 1, then an
    // error code will be received.
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }
    // Before we create our window, specify OpenGL version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);

    // Request a window to be created for our platform
    // The parameters are for the title, x and y position,
    // and the width and height of the window.
    window = SDL_CreateWindow("C++ SDL2 Window",
            20,
            20,
            640,
            480,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    // OpenGL setup the graphics context
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);

    // Setup our function pointers
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // Clear winow
    SDL_RenderClear( renderer );

    // setup for particles
    tumble::Particle particle;
    particle.setMass(1.0f);
    particle.setAcceleration(tumble::Vector3(0.0f, 0.0f, 0.0f));
    particle.setDamping(0.995f);

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = particle.getPosition().x;
    r.y = particle.getPosition().y;
    r.w = 50;
    r.h = 50;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    unsigned int time = SDL_GetTicks();

    // Infinite loop for our application
    bool gameIsRunning = true;
    while(gameIsRunning){
        glViewport(0,0,640,480);

        SDL_Event event;
        // Start our event loop
        while(SDL_PollEvent(&event)){
            // Handle each specific event
            if(event.type == SDL_QUIT){
                gameIsRunning= false;
            }
            if(event.type == SDL_MOUSEMOTION){
                // std::cout << "mouse has been moved\n";
            }
            if(event.type == SDL_KEYDOWN){
                std::cout << "a key has been pressed\n";
                if(event.key.keysym.sym == SDLK_1){
                    particle.setVelocity(tumble::Vector3(1.0f, 0.0f, 0.0f));
                }else{
                    std::cout << "0 was not pressed\n";
                }
            }
            // Retrieve the state of all of the keys
            // Then we can query the scan code of one or more
            // keys at a time
            const Uint8* state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_RIGHT]){
                std::cout << "right arrow key is pressed\n";
            }
        }


        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
        SDL_RenderClear(renderer);

        // Do drawing

        // Render rect
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderFillRect( renderer, &r );

        unsigned int last = SDL_GetTicks() - time;

        particle.integrate(last);

        r.x = particle.getPosition().x;
        r.y = particle.getPosition().y;

        time = SDL_GetTicks();

        // Show renderer
        SDL_RenderPresent(renderer);

        SDL_Delay(1);

        glClearColor(1.0f,0.0f,0.0f,1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    // We destroy our window. We are passing in the pointer
    // that points to the memory allocated by the 
    // 'SDL_CreateWindow' function. Remember, this is
    // a 'C-style' API, we don't have destructors.
    SDL_DestroyWindow(window);
    
    // We safely uninitialize SDL2, that is, we are
    // taking down the subsystems here before we exit
    // We add a delay in order to see that our window
    // has successfully popped up.
    SDL_Delay(3000);
    // our program.
    SDL_Quit();
    return 0;
}