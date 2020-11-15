#include "cNode.h"

cNode::cNode()
{
}

cNode::cNode(char status, bool isVisit)
{
	this->status = status;
	this->isVisit = isVisit;
}

cNode::~cNode()
{
}

void cNode::setStatus(const char status)
{
	this->status = status;
}

char cNode::getStatus()
{
	return status;
}

void cNode::setIsVisit(const bool isVisit)
{
	this->isVisit = isVisit;
}

bool cNode::getIsVisit()
{
	return isVisit;
}
