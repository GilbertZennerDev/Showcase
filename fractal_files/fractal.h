#ifndef FRACTAL_H
#define FRACTAL_H

#include <SDL2/SDL.h>
#include <complex.h>
#include <stdio.h>
#include <time.h>

//#include <omp.h>      // OpenMP for parallel processing

void draw_mandelbrot(SDL_Renderer *renderer, int width, int height, double min_real, double max_real, double min_imag, double max_imag, int max_iterations);
void draw_julia(SDL_Renderer *renderer, int width, int height, double min_real, double max_real, double min_imag, double max_imag, int max_iterations, double complex c);
void draw_fractals(SDL_Renderer *mandel_renderer, SDL_Renderer *julia_renderer1, SDL_Renderer *julia_renderer2 , SDL_Window *active_window, SDL_Window *mandel_window, SDL_Window *julia_window1, SDL_Window *julia_window2, int width, int height, double min_real, double max_real, double min_imag, double max_imag, int max_iterations, double complex c1, double complex c2);

#endif
