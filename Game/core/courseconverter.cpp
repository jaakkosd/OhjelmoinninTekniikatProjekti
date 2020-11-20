#include "core/courseconverter.h"
namespace Game {
courseConverter::cords courseConverter::mapToUi(cords input)
{
    courseConverter::cords output;
    output.x = input.x + map_width_offset;
    output.y = map_height_offset - input.y;
    return output;
}

courseConverter::cords courseConverter::uiToMap(cords input)
{
    courseConverter::cords output;
    output.x = input.x - map_width_offset;
    output.y = map_height_offset - input.y;
    return output;
}
}
