#include "core/courseconverter.h"
namespace Game {
CourseConverter::cords CourseConverter::mapToUi(cords input)
{
    CourseConverter::cords output;
    output.x = input.x + map_width_offset;
    output.y = map_height_offset - input.y;
    return output;
}

CourseConverter::cords CourseConverter::uiToMap(cords input)
{
    CourseConverter::cords output;
    output.x = input.x - map_width_offset;
    output.y = map_height_offset - input.y;
    return output;
}
}
