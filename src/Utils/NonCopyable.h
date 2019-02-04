#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class NonCopyable
{
public:
    NonCopyable();
private:

    NonCopyable(const NonCopyable& nonCopyable);

    NonCopyable& operator=(const NonCopyable& nonCopyable);
};

#endif // NONCOPYABLE_H
