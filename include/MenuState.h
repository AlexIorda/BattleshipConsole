#pragma once

class Menu;

class MenuState
{
    public:
        MenuState();
        virtual ~MenuState();

        void set_menu(Menu *menu);
        virtual bool printMenuHandle() const = 0;

    protected:
        Menu *menu_;
};
