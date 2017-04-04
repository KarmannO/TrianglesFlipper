#include "controlbuttonstate.h"

CControlButtonState::CControlButtonState()
{
    lm_btn = rm_btn = false;
    left_btn = right_btn = up_btn = down_btn = false;
    z_btn = x_btn = false;
    old_mx = old_my = -100;
}
