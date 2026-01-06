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
##  @file draw.cpp

File Description:
##  Pre made draw function
\**************************************************************/

#include "object.hpp"
#include "woof.hpp"
#include "error.hpp"
#include <string>
#include <fmt/core.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>

int Engine::draw_text(const char * const text, float scale, float x, float y)
{
    // Create the style for the text
    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface* surf = TTF_RenderText_Blended(font, text, white);
    if (!surf) return err_custom("Error during the creation of the text surface", KO, ERR_INFO);

    // Convertion of the text into an openGL texture
    SDL_Surface* formatted_surf = SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_RGBA32, 0);
    SDL_FreeSurface(surf);
    surf = formatted_surf;

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Drawing
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float scale_x = area_width / width;
    float scale_y = area_height / height;

    float text_w = surf->w * scale_x * scale;
    float text_h = surf->h * scale_y * scale;

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(x, y);
        glTexCoord2f(1, 0); glVertex2f(x + text_w, y);
        glTexCoord2f(1, 1); glVertex2f(x + text_w, y - text_h);
        glTexCoord2f(0, 1); glVertex2f(x, y - text_h);
    glEnd();

    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);

    // Clear used ressources
    SDL_FreeSurface(surf);
    glDeleteTextures(1, &texture);

    return OK;
}

static void draw_shape(const std::vector<vector2>& v, const vector2 pivot, const float deg)
{
    if (v.size() < 2) return;

    glBegin(GL_LINE_LOOP);
        for (const auto& orig : v) {
            vector2_s p = orig;
            p = rotate_point(p, pivot, deg);
            glVertex2f(p.x, p.y);
        }
    glEnd();
}

static void draw_circle(const std::vector<vector2>& v, int segments = CIRCLE_RESOLUTION)
{
    if (v.size() != 2) return;

    const vector2& origin = v[0];
    float radius = v[1].x;

    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < segments; ++i) {
            float angle = 2.0f * M_PI * i / segments;
            glVertex2f(
                origin.x + std::cos(angle) * radius,
                origin.y + std::sin(angle) * radius
            );
        }
    glEnd();
}

static void draw_object_dispatch(type_t id, const std::vector<vector2>& vectors, const vector2 pivot, const float deg)
{
    switch (id) {
        case SPRITE: break; // Ignore SPRITE for now
        case SHAPE:     draw_shape(vectors, pivot, deg); break;
        case CIRCLE:    draw_circle(vectors); break;
        default: break;
    }
}

void Actor::draw()
{
    if (!rendered) return;
    draw_object_dispatch(id, vectors, rotation_pivot, rotation);
}

void Object::draw()
{
    if (!rendered) return;
    draw_object_dispatch(id, vectors, rotation_pivot, rotation);
}

void Prop::draw()
{
    if (!rendered) return;
    draw_object_dispatch(id, vectors, rotation_pivot, rotation);
}

void Engine::debug_draw()
{
    std::string fps_debug_string = fmt::format("fps: {:.2f}", real_fps.load());
    const char * const fps_debug = fps_debug_string.c_str();
    draw_text(fps_debug, 1.25f, area_width / -2.f + 10.f, area_height / 2.f - 10.f);
}
