#ifndef __ARB_MULTISAMPLE_H__
#define __ARB_MULTISAMPLE_H__

#include <gl/glext.h>
#include <gl/wglext.h>

extern bool arbMultisampleSupported;
extern int  arbMultisampleFormat;

#define CHECK_FOR_MULTISAMPLE 1

bool InitMultisample(HINSTANCE hInstance, HWND hWnd, PIXELFORMATDESCRIPTOR pfd);

#endif
