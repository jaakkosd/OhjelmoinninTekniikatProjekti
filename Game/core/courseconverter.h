#ifndef COURSECONVERTER_H
#define COURSECONVERTER_H
#include <QPair>
namespace Game
{

/**
 * @brief The CourseConverter class is used to easily convert map and ui cordinates and store map dimensions
 */
class CourseConverter
{
public:
    /**
     * @brief The cords struct is used as an easy way to return both cordinates at the same time
     */
    struct cords
    {
        int x;
        int y;
    };
    typedef struct coord coord;
    /**
     * @brief mapToUi converts course map cordinates (used by the CourseLib interface) to ui cordinats (used by ui in mainwindow)
     * @param input cords struct with map cordinates
     * @return cords struct in course map format
     */
    static cords mapToUi(cords input);

    /**
     * @brief uiToMap converts ui cordinats (used by ui in mainwindow) to map cordinates (used by the CourseLib interface)
     * @param input cords struct with ui cordinates
     * @return cords struct in ui format
     */
    static cords uiToMap(cords input);

    static const int MAP_WIDTH = 1095;
    static const int MAP_HEIGHT = 592;

private:
    static const int map_width_offset = 353;
    static const int map_height_offset = 556;
};
} // namespace Game
#endif // COURSECONVERTER_H
