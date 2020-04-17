#ifndef HIGHLIGHTABLE_HPP
#define HIGHLIGHTABLE_HPP

class IHighlightable
{
public:
    virtual void highlight() = 0;
    virtual void reset_color() = 0;
};

#endif