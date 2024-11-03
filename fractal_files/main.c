// main.c
#define SDL_MAIN_HANDLED
#include "fractal.h"

// Corrected draw_fractals function
void draw_fractals(SDL_Renderer *mandel_renderer, SDL_Renderer *julia_renderer1, SDL_Renderer *julia_renderer2 , SDL_Window *active_window, SDL_Window *mandel_window, SDL_Window *julia_window1, SDL_Window *julia_window2, int width, int height, double min_real, double max_real, double min_imag, double max_imag, int max_iterations, double complex c1, double complex c2) {
    if (active_window == mandel_window) {
        draw_mandelbrot(mandel_renderer, width, height, min_real, max_real, min_imag, max_imag, max_iterations);
    } else if (active_window == julia_window1) {
        draw_julia(julia_renderer1, width, height, min_real, max_real, min_imag, max_imag, max_iterations, c1);
    }else if (active_window == julia_window2) {
        draw_julia(julia_renderer2, width, height, min_real, max_real, min_imag, max_imag, max_iterations, c2);
    }
}

// Function to create an SDL window
SDL_Window* create_window(const char *title, int width, int height, int x, int y) {
    SDL_Window *window = SDL_CreateWindow(title,
                                          x,
                                          y,
                                          width, height,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        printf("SDL Window Creation Error: %s\n", SDL_GetError());
    }
    return window;
}

// Function to create an SDL renderer
SDL_Renderer* create_renderer(SDL_Window *window) {
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("SDL Renderer Creation Error: %s\n", SDL_GetError());
    }
    return renderer;
}

int main(int argc, char *argv[]) {
    // Seed random number generator
    srand(time(NULL));

    int width = 400;  // Window width
    int height = 300; // Window height
    const int miny = 100;
    int max_iterations = 10000;

    // Generate random real and imaginary parts between -1.5 and 1.5
    double real_part;
    double imag_part;

    real_part = ((double)rand() / RAND_MAX) * 3.0 - 1.5;
    imag_part = ((double)rand() / RAND_MAX) * 3.0 - 1.5;
    // Create the random complex number
    double complex c1 = real_part + imag_part * I;

    real_part = ((double)rand() / RAND_MAX) * 3.0 - 1.5;
    imag_part = ((double)rand() / RAND_MAX) * 3.0 - 1.5;
    double complex c2 = real_part + imag_part * I;

    // Separate boundaries for Mandelbrot and Julia
    double min_real_mandel = -2.0, max_real_mandel = 1.0;
    double min_imag_mandel = -1.2, max_imag_mandel = 1.2;
    double min_real_julia = -2.0, max_real_julia = 1.0;
    double min_imag_julia = -1.2, max_imag_julia = 1.2;

    double pan_factor = 0.02;
    double zoom_factor = 3;
    int zoom_level = 1;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Initialization Error: %s\n", SDL_GetError());
        return 1;
    }

    // Windows

    SDL_Window *mandel_window = create_window("Mandelbrot Viewer", width, height, 0, miny);
    SDL_Window *julia_window1 = create_window("Julia Viewer", width, height, 500, miny);
    SDL_Window *julia_window2 = create_window("Julia Viewer", width, height, 1000, miny);

    // Renderers
    SDL_Renderer *mandel_renderer = create_renderer(mandel_window);
    SDL_Renderer *julia_renderer1 = create_renderer(julia_window1);
    SDL_Renderer *julia_renderer2 = create_renderer(julia_window2);

    SDL_Window *active_window = mandel_window; // Default active window

    // Draw initial fractals
    draw_mandelbrot(mandel_renderer, width, height, min_real_mandel, max_real_mandel, min_imag_mandel, max_imag_mandel, max_iterations);
    draw_julia(julia_renderer1, width, height, min_real_julia, max_real_julia, min_imag_julia, max_imag_julia, max_iterations, c1);
    draw_julia(julia_renderer2, width, height, min_real_julia, max_real_julia, min_imag_julia, max_imag_julia, max_iterations, c2);

    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            } else if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
                // Update active window on focus
                active_window = SDL_GetWindowFromID(e.window.windowID);
            } else if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEWHEEL) {
                // Determine active fractal boundaries
                double *min_real, *max_real, *min_imag, *max_imag;
                if (active_window == mandel_window) {
                    min_real = &min_real_mandel;
                    max_real = &max_real_mandel;
                    min_imag = &min_imag_mandel;
                    max_imag = &max_imag_mandel;
                } else {
                    min_real = &min_real_julia;
                    max_real = &max_real_julia;
                    min_imag = &min_imag_julia;
                    max_imag = &max_imag_julia;
                }

                // Handle panning and zoom only in active window
                if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                        case SDLK_UP:
                            *min_imag += pan_factor * (*max_imag - *min_imag);
                            *max_imag += pan_factor * (*max_imag - *min_imag);
                            break;
                        case SDLK_DOWN:
                            *min_imag -= pan_factor * (*max_imag - *min_imag);
                            *max_imag -= pan_factor * (*max_imag - *min_imag);
                            break;
                        case SDLK_LEFT:
                            *min_real -= pan_factor * (*max_real - *min_real);
                            *max_real -= pan_factor * (*max_real - *min_real);
                            break;
                        case SDLK_RIGHT:
                            *min_real += pan_factor * (*max_real - *min_real);
                            *max_real += pan_factor * (*max_real - *min_real);
                            break;
                    }
                } else if (e.type == SDL_MOUSEWHEEL) {
                    int mouse_x, mouse_y;
                    SDL_GetMouseState(&mouse_x, &mouse_y);
                    double center_real = *min_real + (*max_real - *min_real) * mouse_x / width;
                    double center_imag = *max_imag - (*max_imag - *min_imag) * mouse_y / height;

                    if (e.wheel.y < 0) { // Zoom in
                        *min_real = center_real + (*min_real - center_real) * zoom_factor;
                        *max_real = center_real + (*max_real - center_real) * zoom_factor;
                        *min_imag = center_imag + (*min_imag - center_imag) * zoom_factor;
                        *max_imag = center_imag + (*max_imag - center_imag) * zoom_factor;
                        zoom_level++;
                    } else if (e.wheel.y > 0) { // Zoom out
                        *min_real = center_real + (*min_real - center_real) / zoom_factor;
                        *max_real = center_real + (*max_real - center_real) / zoom_factor;
                        *min_imag = center_imag + (*min_imag - center_imag) / zoom_factor;
                        *max_imag = center_imag + (*max_imag - center_imag) / zoom_factor;
                        if (zoom_level > 1) zoom_level--;
                    }

                    max_iterations = 1000 + zoom_level * 500;
                }

                draw_fractals(mandel_renderer, julia_renderer1, julia_renderer2 , active_window, mandel_window, julia_window1, julia_window2, width, height, *min_real, *max_real, *min_imag, *max_imag, max_iterations,  c1, c2);
            }
        }
    }

    SDL_DestroyRenderer(mandel_renderer);
    SDL_DestroyRenderer(julia_renderer1);
    SDL_DestroyRenderer(julia_renderer2);
    SDL_DestroyWindow(mandel_window);
    SDL_DestroyWindow(julia_window1);
    SDL_DestroyWindow(julia_window2);
    SDL_Quit();

    return 0;
}
