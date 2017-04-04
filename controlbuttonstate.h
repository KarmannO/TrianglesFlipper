#ifndef CCONTROLBUTTONSTATE_H
#define CCONTROLBUTTONSTATE_H


class CControlButtonState
{
public:
    bool lm_btn;
    bool rm_btn;
    bool left_btn;
    bool right_btn;
    bool up_btn;
    bool down_btn;
    bool z_btn;
    bool x_btn;
    int old_mx, old_my;

    CControlButtonState();
};

#endif // CCONTROLBUTTONSTATE_H
