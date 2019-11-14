#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int main()
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfFont* font;
    sfText* text;
    sfMusic* music;
    sfEvent event;

    window = sfRenderWindow_create(mode, "Duck Hunt", sfResize | sfClose, NULL);
    if (!window)
        return 1;

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);

        sfRenderWindow_display(window);
    }

    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return (0);
}