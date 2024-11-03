#include "fractal.h"

void draw_mandelbrot(SDL_Renderer *renderer, int width, int height, double min_real, double max_real, double min_imag, double max_imag, int max_iterations) {
    // Scaling factors for converting pixel space to Mandelbrot space
    double real_factor = (max_real - min_real) / (width - 1);
    double imag_factor = (max_imag - min_imag) / (height - 1);

    // Allocate a pixel buffer to store color values
    Uint32 *pixel_buffer = (Uint32 *)malloc(width * height * sizeof(Uint32));
    if (!pixel_buffer) {
        printf("Failed to allocate memory for pixel buffer\n");
        return;
    }

    // Iterate over each pixel on the screen in parallel
    #pragma omp parallel for schedule(dynamic)
    for (int y = 0; y < height; y++) {
        double imag = max_imag - y * imag_factor;
        for (int x = 0; x < width; x++) {
            double real = min_real + x * real_factor;

            // Initialize Z and C for the Mandelbrot equation
            double z_real = 0, z_imag = 0;
            double c_real = real, c_imag = imag;

            int iterations = 0;
            double z_real_sq = 0, z_imag_sq = 0;
            while ((z_real_sq + z_imag_sq <= 4.0) && iterations < max_iterations) {
                z_imag = 2.0 * z_real * z_imag + c_imag;
                z_real = z_real_sq - z_imag_sq + c_real;
                z_real_sq = z_real * z_real;
                z_imag_sq = z_imag * z_imag;
                iterations++;
            }

            // Use a psychedelic colorful gradient
            int r, g, b;
            if (iterations == max_iterations) {
                // Points inside the Mandelbrot set are black
                r = g = b = 0;
            } else {
                // Points outside the Mandelbrot set are colored with a psychedelic pattern
                r = (int)(sin(0.1 * iterations) * 127 + 128);
                g = (int)(sin(0.1 * iterations + 2.0) * 127 + 128);
                b = (int)(sin(0.1 * iterations + 4.0) * 127 + 128);
            }

            // Store the color value in the pixel buffer
            pixel_buffer[y * width + x] = (r << 16) | (g << 8) | b;
        }
    }

    // Create texture and render the entire image
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    if (!texture) {
        printf("SDL Texture Creation Error: %s\n", SDL_GetError());
        free(pixel_buffer);
        return;
    }

    SDL_UpdateTexture(texture, NULL, pixel_buffer, width * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // Clean up
    SDL_DestroyTexture(texture);
    free(pixel_buffer);
}