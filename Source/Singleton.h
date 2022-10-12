#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <vcruntime.h>

template <class T>
class Singleton
{
protected:
	Singleton(void) { s_pInstance = (T*)this; }
	virtual ~Singleton(void) { s_pInstance = NULL; }

public:
	static T& GetInstance(void) { return *s_pInstance; }

private:
	static T* s_pInstance;
};

template <class T> T* Singleton< T >::s_pInstance = NULL;

#endif