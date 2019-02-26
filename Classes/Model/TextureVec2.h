#ifndef __TextureVec_H__
#define __TextureVec_H__
#include"Model/Point.h"
#include"Model/WorldObject.h"

using namespace std;
class TextureVec : public WorldObject
{
public:
	TextureVec() {};
	TextureVec(PPoint* position, ETexture texture, int width, int height);
};
typedef vector<TextureVec*> TexVec2;
#endif // __TextureVec_H__
