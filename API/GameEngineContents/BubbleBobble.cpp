#include "BubbleBobble.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include "TitleLevel.h"

BubbleBobble::BubbleBobble()
{
}

BubbleBobble::~BubbleBobble()
{
}

void BubbleBobble::GameInit()
{
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");

}
void BubbleBobble::GameLoop()
{

}
void BubbleBobble::GameEnd()
{

}