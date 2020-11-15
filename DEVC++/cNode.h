#pragma once

class cNode
{
private:
	char status;
	bool isVisit;
public:
	cNode();
	cNode(char status, bool isVisit);
	~cNode();
	void setStatus(const char status);
	char getStatus();
	void setIsVisit(const bool isVisit);
	bool getIsVisit();
};

