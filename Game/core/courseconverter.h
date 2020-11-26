#ifndef COURSECONVERTER_H
#define COURSECONVERTER_H
#include <QPair>
namespace Game {
class CourseConverter
{
public:
    struct cords{
        int x;
        int y;
    };
    static cords mapToUi(cords);
    static cords uiToMap(cords);

    static const int map_width = 1095;
    static const int map_height = 592;
private:
    static const int map_width_offset = 353;
    static const int map_height_offset = 556;
};
}
#endif // COURSECONVERTER_H
