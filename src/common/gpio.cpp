#include "gpio.h"


GPIO::Error_t GPIO::checkErrorStatus()
{
    return errorStatus;
}